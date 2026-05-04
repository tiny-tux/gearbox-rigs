# Gearbox Versioning - Simple Guide

## The System

**Version format:** `v[MAJOR].[MINOR]-[STATUS]`

**Examples:**
- `v1.0` - First stable release (on main branch)
- `v1.1-dev` - Pre-release/testing version (on dev branch)
- `v1.1` - New features stable (on main branch)
- `v2.0` - Major changes or different hardware (on main branch)

**Rules:**
- **MAJOR** (1.x → 2.x): Changed hardware, broke compatibility, or major rewrite
- **MINOR** (x.1 → x.2): Added features, improved code, bug fixes
- **STATUS**: Add `-dev` for pre-release versions (tagged on dev branch only)

## Branch Workflow

- **main branch** = Stable releases only, always deployable
- **dev branch** = Daily work, can be messy or half-finished

## Where to Put Version Info

### 1. Top of Your Code
```cpp
/*
 * AC Type H
 * v1.0 - Stable
 * Last Updated: 2026-02-17
 * 
 * Hardware Configuration:
 * - Load Cell: HX711, calibration 225000
 * - Encoder: 400 PPR
 * - Torque Arm: 0.1m
 * 
 * Currently Deployed On: Bench Arduino #1
 */
```

### 2. GitHub Release
When you tag a release, document all rigs in [CHANGELOG.md](./CHANGELOG.md):

```markdown
## v1.0 - Initial Stable Release

**Status:** Stable - All rigs deployed

Initial Release, as deployed on the rigs at end 2025.

### Changes

**Firmware Changes:**
- Changed: Tidied and amalgamated codebase
- Changed: Verified functionality with control GUI

**Hardware Changes:**
- Rig currently broken - changes and fixes imminent

**Known Issues:**
- AC motor burned out due to shaft misalignment, replacement motor to be fitted and aligned

**Migration Notes:**
- None
```

### 3. README.md
Create overview notes in the README.

## Workflow Examples

### Daily Work
```bash
# Work on dev branch
git checkout dev
git add .
git commit -m "Improved sensor reading"
git push origin dev
```

### Creating a Stable Release
```bash
# Test everything on dev first, then:
git checkout main
git merge dev
git tag -a v1.0 -m "All rigs stable - initial release"
git push origin main
git push origin v1.0

# Create GitHub release from v1.0 tag
# Update CHANGELOG.md
# Switch back to dev
git checkout dev
```

### Pre-release/Testing Version
```bash
# Tag on dev branch (don't merge to main yet)
git checkout dev
git tag -a v1.1-dev -m "Testing version"
git push origin dev
git push origin v1.1-dev

# On GitHub, mark as "pre-release"
```

## Common Git Commands

```bash
git status                  # See what changed
git log --oneline          # See commit history
git tag -l                 # List all tags
git checkout main          # Switch to main branch
git checkout dev           # Switch to dev branch
git branch                 # See which branch you're on
```

## One-Time Setup

```bash
# Create dev branch (first time only)
git checkout -b dev
git push -u origin dev
```
