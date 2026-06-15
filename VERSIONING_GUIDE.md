# Versioning Guide

## Version Format
`v[MAJOR].[MINOR]`

| Bump | When |
|------|------|
| MAJOR | Hardware change, broke compatibility, major rewrite |
| MINOR | Features, fixes, improvements |

## Branches
- `main` — stable releases only
- `dev` — daily work

## File Header
```cpp
/*
 * [Project Name] — v1.0
 * Status: Deployed on Bench Arduino #1
 * Last Updated: 2026-02-17
 * Hardware: HX711 (cal 225000), 400 PPR encoder, 0.1m torque arm
 * Issues: github.com/[repo-url]/issues
 */

 void setup() {

 }

 void loop() {

 }
```

## Releasing

### Pre-release
```bash
# Stay on dev branch, mark as pre-release on GitHub
git tag -a v1.1 -m "Description"
git push origin dev --tags
```

### Stable Release
```bash
# 1. Push dev to GitHub
git push

# 2. Open a pull request on GitHub: dev → main
# 3. Merge the pull request on GitHub

# 4. Pull main locally and tag
git checkout main
git pull
git tag -a v1.1 -m "Description"
git push origin --tags

# 5. Switch back to dev
git checkout dev
```

### GitHub Release Template
```markdown
## Status
Deployed on: Bench Arduino #1

## Changes
- Fixed sensor dropout issue
- Improved PID tuning

## Hardware
- Any hardware changes from previous version, or "No changes"

## Known Issues
- Motor alignment needs checking
```

## Useful Commands
```bash
git status          # See what's changed since last commit
git log --oneline   # Compact commit history
git tag -l          # List all tags
git checkout main   # Switch to main branch
git checkout dev    # Switch to dev branch
```

## One-Time Setup
```bash
# Only required once
git checkout -b dev     # Create dev branch
git push -u origin dev  # Push to dev
```