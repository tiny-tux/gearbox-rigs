#include <LiquidCrystal.h>
#include <Wire.h> 
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

#include <Encoder.h>
#include <SimpleTimer.h> //https://github.com/jfturcot/SimpleTimer

hd44780_I2Cexp lcd(0x27);//0x27 or 0x3F
Encoder motorEncoder(2, 3);

double currentcount = 0;
double currenttime = 0;
double lastcount = 0;
double currentspeed = 0;
double lasttime = 0;

SimpleTimer timer;


void setup() {
  // put your setup code here, to run once:

pinMode(2, INPUT);
pinMode(3, INPUT);

 Serial.begin(9600);

 lcd.begin(16,2);  //initialize the lcd
 //lcd.backlight(); //open the backlight 
   lcd.setCursor(0,0);
  lcd.print("   ENGME353");
  lcd.setCursor(0,1);
  lcd.print("  Gearbox Rig");
delay(3000);
lcd.clear();

timer.setInterval(200, repeatMe);
}

void loop() {
  // put your main code here, to run repeatedly:

timer.run();

}

void repeatMe() {

  lasttime = currenttime;
  lastcount = currentcount;
  
  currenttime = (double)micros();
  currentcount = double(motorEncoder.read());

  currentspeed = (currentcount - lastcount)*1000000/(currenttime-lasttime)*0.0075*12;//RPM
 
  Serial.println("s"+ String(currentspeed,0));

  lcd.setCursor(0,0);
  lcd.print("Motor Speed");
  lcd.setCursor(0,1);
  lcd.print(currentspeed, 0);
  lcd.print(" RPM    ");


}