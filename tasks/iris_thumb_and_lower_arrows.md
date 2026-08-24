# Iris y0shi_via Keymap: Thumb Rework + WASD Arrows on Lower

## Requirements

Keyboard: `keebio/iris/rev8`, keymap `y0shi_via`.

### Base layer (layer 0) — right thumb cluster rework
Starting point (current uncommitted state): Home(c7r4) / Alt(c8r4) / Space(c7r5) / Space(c8r5) / Enter(c10r5).

1. Move Enter to the right thumb space button (c8r5).
2. Put End where Alt is now (c8r4).
3. Put Alt where Enter is now (c10r5).

Resulting thumb cluster: Win/Cmd(c5r5), Lower(c6r5), Home(c7r4), End(c8r4), Space(c7r5), Enter(c8r5), Upper(c9r5), Alt(c10r5).

### Lower layer (layer 1) — WASD arrow duplicate
Add arrow keys on the physical WASD positions (in addition to the existing arrows already on H/J/K/L-ish position at c9-c12/r3), gamer-style:
- W position (c3r2): Up
- A position (c2r3): Left
- S position (c3r3): Down
- D position (c4r3): Right

All four are currently `KC_TRNS` on Lower, safe to override.

## Task List

- [x] Edit `keyboards/keebio/iris/keymaps/y0shi_via/keymap.json` — base layer thumb cluster swap
- [x] Edit `keyboards/keebio/iris/keymaps/y0shi_via/keymap.json` — lower layer WASD arrows
- [x] Regenerate `docs/iris_y0shi_keymap.html` visualization to match
- [x] Update `docs/developer_journal.md`
- [ ] User to compile/flash and verify on hardware

## Verification

Diffed final `keymap.json` against last commit position-by-position (row4/row5 of layer 0): only `c7r5`/`c8r5` actually differ from the committed baseline (Space and Enter swapped) — `c8r4` (End) and `c10r5` (Alt) land back on their originally-committed values, net unchanged despite passing through an intermediate state.
