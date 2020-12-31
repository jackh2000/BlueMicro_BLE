/*
Copyright 2018 <Pierre Constantineau>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#include "keymap.h"
#include "keyboard_config.h"


std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
  {{
    {KC_NO,      LAYER_1,  KC_PSLS,  KC_PAST,  KC_PMNS,},
    {KC_NO,      KC_P7,    KC_P8,    KC_P9,    KC_PPLS,},
    {KC_NO,      KC_P4,    KC_P5,    KC_P6,    KC_NO,},
    {KC_MUTE,    KC_P1,    KC_P2,    KC_P3,    KC_PENT,},
    {KC_BSPC,    KC_P0,    KC_NO,    KC_PDOT,  KC_NO}
  }};


void setupKeymap() {

  uint32_t layer1[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
      _______,          LAYER_2,  _______,  _______,  _______,
      _______,          KC_HOME,  KC_UP,    KC_PGUP,  _______,
      _______,          KC_LEFT,  _______,  KC_RIGHT, _______,
      KC_SYSTEM_POWER,  KC_END,   KC_DOWN,  KC_PGDN,  _______,
      _______,          _______,  KC_INS,   KC_DEL,   _______
   );

    uint32_t layer2[MATRIX_ROWS][MATRIX_COLS] =
      KEYMAP(
        _______,    LAYER_0,  RGB_TOG,  RGB_MOD,  _______,
        _______,    RGB_HUI,  RGB_SAI,  RGB_VAI,  _______,
        _______,    RGB_HUD,  RGB_SAD,  RGB_VAD,  _______,
        RESET,      _______,  BL_TOGG,   BL_INC,  _______,
        _______,    _______,  _______,   BL_DEC,  _______
    );


    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
      for (int col = 0; col < MATRIX_COLS; ++col)
      {
        matrix[row][col].addActivation(_L1, Method::PRESS, layer1[row][col]);
        matrix[row][col].addActivation(_L2, Method::PRESS, layer2[row][col]);
      }
    }
}
