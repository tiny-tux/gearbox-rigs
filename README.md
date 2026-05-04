# ENGME353 Gearboxes

Gearbox system for measuring torque output at different gear ratio stages.

## Current State

**Latest Stable (main branch):** v1.1 - All rigs deployed and tested as of Week 8 Lab, A-trimester 2026

**In Development (dev branch):** Nothing currently under development


## Rig Overview

- **Version:** v1.1
- **Status:** Stable
- **Location:** LSL.1.02
- **Purpose:** Display motor RPM during gear ratio testing.


## Getting Started

1. **Clone the repository**
   ```bash
   git clone https://github.com/tiny-tux/engme353-gearboxes/
   cd engme353-gearboxes
   ```

2. **Install dependencies**
   - Install Arduino IDE
   - Install required libraries

3. **Deploy**
   - Open the `.ino` file in Arduino IDE
   - Configure hardware-specific settings if needed
   - Upload to Arduino

## Development Workflow

This repository uses a two-branch workflow:

- **main branch:** Stable, tested releases only
- **dev branch:** Active development and testing

### Making Changes

```bash
# Work on dev branch
git checkout dev

# Make your changes, commit regularly
git add .
git commit -m "describe your changes"
git push origin dev
```

### Creating a Release

```bash
# Test all rigs thoroughly on dev branch

# Merge to main and tag
git checkout main
git merge dev
git tag -a v1.1 -m "Release description"
git push origin main
git push origin v1.1

# Create GitHub release and update CHANGELOG.md
```

See [VERSIONING_GUIDE.md](./VERSIONING_GUIDE.md) for detailed workflow.

## Documentation

- **[CHANGELOG.md](./CHANGELOG.md)** - Version history and changes for all rigs
- **VERSIONING_GUIDE.md** - Version control and release workflow

## Common Libraries

- LiquidCrystal_I2C (LCD display)
- Encoder (speed measurements)
- Wire (possibly redundant)

## Contributing

1. Always work on the `dev` branch
2. Test your changes thoroughly before merging to `main` - only stable, deployed, and tested releases should be merged
3. Update the README if you change hardware or configuration
4. Update CHANGELOG.md when creating a release

## Notes


