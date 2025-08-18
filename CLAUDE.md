# QMK Firmware

## Project Overview
This is firmware and associated code for QMK keyboards.

## Key Guidelines DO NOT SKIP THESE
- Always always make a plan
 - write the requirements and your task list to the tasks/ directory as markdown files.
    - keep the task list updated as you work
 - keep a running summary of what was done in docs/developer_journal.md
 - never make tmp/bak/new files.  edit in place.  use git!
 - do not remove functionality if it stops working.  always fix it.

## Development Environment Setup

- let the user handle credentials
- new features that we work on are documented in the docs/ folder using the existing naming convention. always write your plan there and update it as things are completed.

### Environment Management

```bash
```



### Git Workflow

#### Branch Management
- Branch for feature development
  - branches should be named using the following pattern `feature/new_feature_name`
- Use descriptive commit messages
- Test before committing
- Do not commit without user approval

#### Common Git Commands
```bash
# Check status
git status

# Stage changes
git add .

# Commit changes
git commit -m "descriptive message"

# Push changes
git push origin calendar-bot
```
