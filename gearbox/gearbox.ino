/*
 * Gearbox
 * v1.0
 * Last Updated: 2026-05-04
 * Updated By: Sam Knox
 *
 * **Firmware Status: Deployed**
 * **Hardware Status: Operational**
 * 
 * Measures motor RPM during gear ratio testing.
 * 
 * Hardware:
 * - RS Pro 238-9759 DC Motor 4.5V-15V
 * - Arduino Uno
 * - Same Sky (formerly CUI Devices) AMT102-V Encoder
 * - 9V Battery Clip
 * - 4xAA Battery Holder
 * - LCD Display (I2C)
 *
 * Known Issues:
 * - Hard to read the RPM output as it changes so fast
 *
 * To-do:
 * - Average the RPM reading
 *
 */

#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
#include <Encoder.h>

// ============================================================================
// CONFIGURATION
// ============================================================================

// Pin Definitions
#define PIN_ENCODER_A 2
#define PIN_ENCODER_B 3

// Calibration Factors
#define ENCODER_CPR 8192                // AMT102-V at 2048 PPR; library counts all 4 quadrature edges (CPR = PPR × 4)
#define STAGE_RATIO 12.0                // Combined gear ratio between motor and encoder shaft: (48/12) × (60/20) = 4 × 3

// LCD Configuration
#define LCD_ADDRESS 0x27                // 0x27 or 0x3F
#define LCD_COLUMNS 16
#define LCD_ROWS 2

// Timing
#define UPDATE_INTERVAL_MS 200
#define CURRENT_SAMPLES 70

// ============================================================================
// HARDWARE OBJECTS
// ============================================================================

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);
Encoder motorEncoder(PIN_ENCODER_A, PIN_ENCODER_B);

// ============================================================================
// GLOBAL STATE
// ============================================================================

// Timing variables
uint16_t lastMeasurement;

// Speed measurement variables
struct MotorData {
  double encoderCount;
  double timestamp;
  double speed;  // RPM
};

MotorData currentData = { 0 };
MotorData previousData = { 0 };

// ============================================================================
// SETUP
// ============================================================================

void setup() {
  // Initialise pins
  pinMode(PIN_ENCODER_A, INPUT);
  pinMode(PIN_ENCODER_B, INPUT);

  // Initialise serial communication
  Serial.begin(115200);

  // Initialise LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);

  lcd.print("   ENGME353");
  lcd.setCursor(0,1);
  lcd.print("  Gearbox Rig");

  delay(2000);
  
  lcd.clear();
}

void loop() {
  if ((millis() - lastMeasurement) > UPDATE_INTERVAL_MS) {
    updateMeasurements();
    lastMeasurement = millis();
  }
}

void updateMeasurements() {
  // Store previous values
  previousData = currentData;

  // Read current values
  currentData.timestamp = (double)micros();
  currentData.encoderCount = (double)motorEncoder.read();

  // Calculate speed (RPM)
  currentData.speed = calculateRPM(
    currentData.encoderCount,
    previousData.encoderCount,
    currentData.timestamp,
    previousData.timestamp);

  // Output to serial
  sendSerialData(currentData.speed);

  // Update display
  updateDisplay(currentData.speed);
}

double calculateRPM(double currentCount, double lastCount,
                    double currentTime, double lastTime) {
  if (lastTime == 0) {
    return 0.0;
  }

  double countDelta = currentCount - lastCount;
  double timeDelta = currentTime - lastTime;

  // Convert to RPM: (counts/microsecond) * (1000000 us/s) * (60 s/min) / (counts/rev)
  return (countDelta / timeDelta) * 1000000.0 * 60.0 / (ENCODER_CPR / STAGE_RATIO);
}

// ============================================================================
// OUTPUT FUNCTIONS
// ============================================================================

void sendSerialData(double speed) {
  Serial.println("s" + String(speed, 0));
}

void updateDisplay(double speed) {
  lcd.setCursor(0, 0);
  lcd.print("Motor Speed");
  lcd.setCursor(0,1);
  lcd.print(speed, 0);
  lcd.print(" RPM    ");
}