# Keebio Iris Rev8 RGB Layer Lighting Requirements

## Objective
Implement RGB lighting that changes colors based on the active layer for a Keebio Iris Rev8 split keyboard.

## Current State
- Iris Rev8 already has RGB Matrix enabled with 68 LEDs (34 per side)
- Uses WS2812 LEDs on pin GP9
- Has 3 layers: base (0), lower (1), upper (2)
- RGB Matrix driver is working with extensive animation support

## Requirements

### Functional Requirements
1. **Layer-based Color Changes**: Different colors for each layer
   - Layer 0 (Base): Default/white
   - Layer 1 (Lower): Blue  
   - Layer 2 (Upper): Green

2. **Split Keyboard Support**: Both halves should display the same layer color

3. **Preserve Existing Functionality**: Keep current RGB Matrix animations and controls

### Technical Requirements
1. Use RGB Matrix indicators instead of RGB Light for layer colors
2. Implement `rgb_matrix_indicators_advanced_user()` function
3. Add layer state syncing for split keyboard
4. Separate RGB Matrix keycodes from RGB Light if needed

## Implementation Approach
- Keep existing RGB Matrix configuration
- Add custom keymap with layer indicator function
- Handle split keyboard layer synchronization
- Test on actual hardware

## Task Status

### Phase 1: Setup and Planning
- [x] Create project documentation
- [x] Create feature branch (feature/iris_rgb_layers)
- [x] Create custom keymap directory

### Phase 2: Implementation
- [x] Implement RGB Matrix layer indicators function
- [x] Add split keyboard layer state syncing
- [x] Configure layer colors (White, Blue, Green)

### Phase 3: Testing and Validation
- [x] Test and build firmware (compilation successful)
- [ ] Verify layer switching works (requires hardware testing)
- [ ] Test on actual hardware

## Final Implementation

**Solution Used**: RGB Matrix Indicators (not RGB Light Lighting Layers)
- RGB Matrix and RGB Light cannot both use WS2812 simultaneously
- RGB Matrix indicators provide equivalent functionality
- All 68 LEDs change color based on active layer
- Split keyboard layer state syncing enabled

## Success Criteria
- LEDs change color when switching layers
- Both keyboard halves show the same color
- No conflicts with existing RGB functionality
- Smooth color transitions