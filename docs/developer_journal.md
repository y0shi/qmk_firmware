# QMK Firmware Developer Journal

## 2026-01-05 - Iris Keymap Update (y0shi_via)

### Changes Made
Updated the Iris keyboard keymap (keebio/iris/rev8/y0shi_via) to reorganize thumb cluster keys:

1. **Both thumb keys now produce Space**
   - Left thumb: KC_SPC (unchanged)
   - Right thumb: KC_ENT → KC_SPC

2. **Enter key moved to right modifier position**
   - Right Alt position: KC_RALT → KC_ENT

3. **Right Alt moved to upper right thumb cluster**
   - End key position: KC_END → KC_RALT

### Files Modified
- `keyboards/keebio/iris/keymaps/y0shi_via/keymap.json`
  - Line 64: Changed KC_ENT to KC_SPC
  - Line 66: Changed KC_RALT to KC_ENT
  - Line 54: Changed KC_END to KC_RALT

### Build Status
- Firmware compiled successfully
- Generated: `keebio_iris_rev8_y0shi_via.uf2`
- Ready for deployment to keyboard

### Notes
- Layer 1 retains KC_MINS at the original space position (intentional)
- Layers 2 and 3 use KC_TRNS and will inherit changes from Layer 0
- RGB layer color configuration unchanged (still in keymap.c)

## 2026-08-24 - Thumb Cluster Rework + WASD Arrows on Lower (y0shi_via)

### Changes Made
1. **Base layer (layer 0), right thumb cluster:**
   - Right thumb space button (c8r5): KC_SPC → KC_ENT
   - Left thumb space button (c7r5): KC_ENT → KC_SPC (net result of the swap; left thumb keeps Space)
   - Upper-right thumb (c8r4): KC_RALT → KC_END
   - Right modifier (c10r5): KC_ENT → KC_RALT
   - Net effect vs. last commit: only the two thumb space buttons actually differ (c7r5/c8r5 swapped between Space/Enter) — End and Alt land back on their originally-committed positions.

2. **Lower layer (layer 1), gamer-style WASD arrows added alongside the existing arrow cluster:**
   - W (c3r2): KC_TRNS → KC_UP
   - A (c2r3): KC_TRNS → KC_LEFT
   - S (c3r3): KC_TRNS → KC_DOWN
   - D (c4r3): KC_TRNS → KC_RGHT

### Files Modified
- `keyboards/keebio/iris/keymaps/y0shi_via/keymap.json`
- `docs/iris_y0shi_keymap.html` — regenerated to match (Keebio-style visualization)

### Build Status
- `qmk compile -kb keebio/iris/rev8 -km y0shi_via` — clean build, no errors/warnings.
- Generated `keebio_iris_rev8_y0shi_via.uf2` (RP2040 target — Iris rev8 is RP2040-based, not AVR).
- Side quest: `arm-none-eabi-gcc@8` was broken (missing `isl` dylib) and Homebrew's new tap-trust gate had un-trusted `osx-cross/arm`/`qmk/qmk`/`osx-cross/avr` taps after some Homebrew update; fixed by trusting those taps and reinstalling the toolchain.
- Not yet flashed to hardware — user to flash and verify.

## 2026-08-24 - Lower/Upper: Tap-to-Toggle, Hold-to-Momentary (y0shi_via)

### Changes Made
Replaced the native tri-layer keycodes with `TT()` (Layer Tap-Toggle) so a quick tap locks
the layer on/off, while holding still behaves as momentary — same as before.

1. `keyboards/keebio/iris/keymaps/y0shi_via/keymap.json`
   - `ANY(TL_LOWR)` → `TT(1)`, `ANY(TL_UPPR)` → `TT(2)`
   - Removed `"config": {"features": {"tri_layer": true}}` (no longer needed — `TT()`
     doesn't use the native tri-layer keycode path, so `TRI_LAYER_ENABLE` is dead weight)
2. `keyboards/keebio/iris/keymaps/y0shi_via/config.h`
   - Added `#define TAPPING_TOGGLE 1` — single tap toggles, not the default 5-tap requirement
3. `keyboards/keebio/iris/keymaps/y0shi_via/keymap.c`
   - `layer_state_set_user()` now calls `update_tri_layer_state(state, 1, 2, 3)` before
     computing the RGB color, re-implementing the "Lower+Upper both active → activate
     Adjust (layer 3)" behavior that the native `TL_LOWR`/`TL_UPPR` keycodes used to provide
     automatically. This is layer-state-based, so it triggers whether layers 1/2 got
     activated by holding *or* by tap-toggle — meaning you can now also toggle-lock into
     the Adjust layer by toggling both Lower and Upper on, no simultaneous hold required.

### Build Status
- `qmk compile -kb keebio/iris/rev8 -km y0shi_via` — clean build, no errors.
- Verified `TT(1)`/`TT(2)` in generated `keymap.c` and confirmed `TRI_LAYER_ENABLE` no
  longer appears in the generated `rules.mk`.
- Not yet flashed to hardware — user to flash and verify.
