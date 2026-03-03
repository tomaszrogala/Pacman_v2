# Copilot instructions (C++)

## Goal
Apply naming rules consistently across this repository. Prefer semantic refactors/renames (IDE Rename / symbol-aware refactoring), not regex. Do not change behavior.

## Naming rules

### 1) Functions / methods
- Use snake_case for all free functions and all methods.
  - Examples: `try_move`, `update_state`, `compute_path`

### 3) Members (fields) — prefix for ALL members
- All data members (fields) in BOTH classes and structs MUST have prefix `m_`.

### 1) Members of classes (class fields)
- For fields that belong to a `class`: after the `m_` prefix use snake_case.
  - Examples: `m_map`, `m_ghosts`, `m_player_speed`

### 2) Members of structs (struct fields)
- For fields that belong to a `struct`: after the `m_` prefix use PascalCase.
  - Examples: `m_Map`, `m_Ghosts`, `m_PlayerSpeed`

### 4) Parameters (function/method arguments)
- All parameters MUST have prefix `a_`.
- After the `a_` prefix use snake_case.
  - Examples: `a_config`, `a_state`, `a_target_pos`

### Local variables
- Keep local variables in lowerCamelCase.
  - Examples: `ghostIndex`, `nextPos`, `pathCost`

## Refactor boundaries (MUST)
- Rename ONLY identifiers inside the current project (do not touch external/third-party code).
- Do NOT rename:
  - macros
  - types (classes/structs/enums/typedefs/using)
  - namespaces
- Public API: if a rename would break external users, stop and ask before proceeding (unless I explicitly request breaking API changes).
- Work in small batches (one file at a time) and ensure the solution still builds.
- Avoid name collisions and shadowing; if a rename would collide, choose a safe alternative.

## How to apply renames (MUST)
- Use semantic rename/refactoring (symbol-aware rename) whenever possible.
- When renaming a symbol, update all references required for the solution to compile (do not partially rename).
- If semantic rename is not possible for a requested change, stop and explain what blocks it.

## Output format when asked to refactor
- Show a concise summary of what was renamed.
- Provide a diff-style patch when possible.