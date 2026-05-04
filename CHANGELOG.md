# Changelog

All releases are listed newest first. Each release applies to all rigs in the repository.

## [v1.1] - 2026-05-04

**Status:** Stable

First overhaul involving code refactoring and library trimming.

### Changes

**Firmware:**
- Changed: Full code refactoring
- Changed: Removed SimpleTimer library, replaced with simple millis() check
- Changed: Removed other redundant libraries
- Added: Variable macros
- Added: Annotations and calculations

**Hardware:**
- Changed: Button model

**Known Issues:**
- RPM readings are not averaged, so it can be difficult to read the momentary speed with precision

**Migration Notes:**

---

## Template for Future Releases

Copy this template when creating a new release:

```markdown
## [v1.1] - YYYY-MM-DD

**Status:** Stable / Development

[Give an overview of the release]

### Changes

**Firmware:**
- Changed: [what changed]
- Added: [what was added]
- Fixed: [what was fixed]

**Hardware:**
- [List any hardware changes, or write "None"]

**Known Issues:**
- [List any known issues, or write "None"]

**Migration Notes:**
- [Any special instructions for updating from previous version]

```
