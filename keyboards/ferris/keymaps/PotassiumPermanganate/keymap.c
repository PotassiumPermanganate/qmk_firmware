#include QMK_KEYBOARD_H

// MACROS

enum custom_keycodes {
    M_INPUTSWITCH = SAFE_RANGE,
    M_UNDO,
    M_CUT,
    M_COPY,
    M_PASTE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case M_INPUTSWITCH:
          if (record->event.pressed) {
              // when keycode M_INPUTSWITCH is pressed
              register_code(KC_LWIN);
              register_code(KC_RGUI);
          } else {
              // when keycode M_INPUTSWITCH is released
              unregister_code(KC_LWIN);
              unregister_code(KC_RGUI);
          }
          break;
        case M_UNDO:
          if (record->event.pressed) {
              register_code(KC_RGUI);
              register_code(KC_Z);
          } else {
              unregister_code(KC_RGUI);
              unregister_code(KC_Z);
          }
          break;
        case M_CUT:
          if (record->event.pressed) {
              register_code(KC_RGUI);
              register_code(KC_X);
          } else {
              unregister_code(KC_RGUI);
              unregister_code(KC_X);
          }
          break;
        case M_COPY:
          if (record->event.pressed) {
              register_code(KC_RGUI);
              register_code(KC_C);
          } else {
              unregister_code(KC_RGUI);
              unregister_code(KC_C);
          }
          break;
        case M_PASTE:
          if (record->event.pressed) {
              register_code(KC_RGUI);
              register_code(KC_V);
          } else {
              unregister_code(KC_RGUI);
              unregister_code(KC_V);
          }
          break;
    }
    return true;
};

// LAYERS

enum ferris_layers {
  _BASE,
  _FUNC,
  _NAVSYM,
  _NUM
};

#define KC_GUISPC MT(MOD_LGUI, KC_SPC)
#define KC_ALTENT MT(MOD_LALT, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
// ___Q___ , ___W___ , ___E___ , ___R___ , ___T___     ,     ___Y___ , ___U___ , ___I___ , ___O___ , ___P___ ,
//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
// ___A___ , ___R___ , ___S___ , ___T___ , ___D___     ,     ___H___ , ___J___ , ___K___ , ___L___ , ___;___ ,
//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
// ___Z___ , ___X___ , ___C___ , ___V___ , ___B___     ,     ___N___ , ___M___ , ___,___ , ___.___ , ___/___ ,
//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
//                               __SFT__ , ALTENTR ,        WIN/SPC  , _CTRL__
//                              ---------+---------+---+---+---------+---------                              //
  [_BASE] = LAYOUT( /* BASE */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,  KC_I,    KC_O,   KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,  KC_K,    KC_L,   KC_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,  KC_COMM, KC_DOT, KC_SLSH,
                              KC_LSFT, KC_ALTENT, KC_GUISPC, KC_LCTL
  ),


//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
// __F12__ , __F7___ , __F8___ , __F9___ , __CAPS_     ,     ___Y___ , _MUTE__ , _VOLD__ , _VOLU__ , ___;___ ,
//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
// __F11__ , __F4___ , __F5___ , __F6___ , _LchPad_     ,     ___H___ , _MPRV__ , ___K___ , _MPLY__ , _MNXT__ ,
//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
// __F10__ , __F1___ , __F2___ , __F3___ , __INS__     ,     __PSCR_ , _MACRO_ , ___,___ , ___.___ , ___/___ ,
//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
//                               __SFT__ , ALTENTR ,        WIN/SPC  , _CTRL__
//                              ---------+---------+---+---+---------+---------                              //
  [_FUNC] = LAYOUT( /* FUNCTIONS */
    KC_F12,    KC_F7,    KC_F8,    KC_F9,    KC_CAPS,           KC_Y,     KC_MUTE,       KC_VOLD, KC_VOLU,   KC_SCLN,
    KC_F11,    KC_F4,    KC_F5,    KC_F6,    KC_LAUNCHPAD,      KC_H,     KC_MPRV,       KC_E,    KC_MPLY,   KC_MNXT,
    KC_F10,    KC_F1,    KC_F2,    KC_F3,    KC_INS,            KC_PSCR,  M_INPUTSWITCH, KC_COMM, KC_DOT,    KC_SLSH,
                                      KC_LSFT, KC_ALTENT, KC_GUISPC, KC_LCTL
  ),


//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
// ___^___ , ___&___ , ___*___ , ___`___ , ___~___     ,     ___J___ , ___K___ , ___|___ , ___\___ , ___;___ ,
//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
// _MACRO_ , _MACRO_ , _MACRO_ , _MACRO_ , __DEL__     ,     ___←___ , ___↓___ , ___↑___ , ___→___ , __ESC__ ,
//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
// ___!___ , ___@___ , ___#___ , ___$___ , ___%___     ,     __HOME__ , __PGU__ , __PGD__ , __END__ , ___N___ ,
//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
//                               __SFT__ , ALTENTR ,        WIN/SPC  , _CTRL__
//                              ---------+---------+---+---+---------+---------                              //
  [_NAVSYM] = LAYOUT( /* NAVIGATION & SYMBOLS */
    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_GRV,    KC_TILD,            KC_J,    KC_K,     KC_PIPE,   KC_BSLS,  KC_SCLN,
    M_UNDO,     M_CUT,      M_COPY,     M_PASTE,   KC_DELETE,          KC_LEFT, KC_DOWN,  KC_UP,    KC_RIGHT, KC_ESC,
    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,    KC_PERC,            KC_HOME, KC_PGUP,  KC_PGDN, KC_END,  KC_N,
                                      KC_LSFT, KC_ALTENT, KC_GUISPC, KC_LCTL
  ),


//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
// ___Q___ , ___W___ , ___E___ , ___R___ , ___T___     ,     ___Y___ , ___7___ , ___8___ , ___9___ , ___;___ ,
//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
// ___+___ , ___-___ , ___*___ , ___/___ , ___=___     ,     ___0___ , ___4___ , ___5___ , ___6___ , ___O___ ,
//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
// ___Z___ , ___X___ , ___C___ , ___#___ , ___%___     ,     ___N___ , ___1___ , ___2___ , ___3___ , ___.___ ,
//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
//                               __SFT__ , ALTENTR ,        WIN/SPC  , _CTRL__
//                              ---------+---------+---+---+---------+---------                              //
  [_NUM] = LAYOUT( /* NUMBERS */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,   KC_7,  KC_8,    KC_9,   KC_SCLN,
    KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, KC_EQL,          KC_0,   KC_4,  KC_5,    KC_6,   KC_O,
    KC_Z,    KC_X,    KC_C,    KC_HASH,    KC_PERC,         KC_N,   KC_1,  KC_2,    KC_3,   KC_DOT,
                                      KC_LSFT, KC_ALTENT, KC_GUISPC, KC_LCTL
  )
};

// COMBOS

enum combo_events {
  TO_BASE_LAYER_0,
  TO_BASE_LAYER_1,
  TO_BASE_LAYER_3,
  TO_FUNC_LAYER,
  TO_NAVSYM_LAYER,
  TO_SYM_LAYER,
  TO_NUM_LAYER
};

// layer combos
const uint16_t PROGMEM base_base_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM base_func_combo[] = {KC_F8, KC_F9, COMBO_END};
const uint16_t PROGMEM base_navsym_combo[] = {KC_ASTR, KC_GRV, COMBO_END};
const uint16_t PROGMEM navsym_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM num_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM func_combo[] = {KC_Y, KC_I, COMBO_END};

// key combos
const uint16_t PROGMEM esc_combo[] = {KC_G, KC_H, COMBO_END};
const uint16_t PROGMEM delete_combo[] = {KC_B, KC_N, COMBO_END};
const uint16_t PROGMEM backspace_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM backspace_combo_num[] = {KC_Y, KC_7, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM lparen_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM rparen_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM underscore_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM dash_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM equals_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM dquote_combo[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM squote_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM lsquare_combo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM rsquare_combo[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM grv_combo[] = {KC_U, KC_P, COMBO_END};
const uint16_t PROGMEM at_combo[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM carrot_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM dollar_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM hash_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM plus_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM exc_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM amp_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM star_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM bslash_combo[] = {KC_Z, KC_X, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  [TO_BASE_LAYER_0] = COMBO_ACTION(base_base_combo),
  [TO_BASE_LAYER_1] = COMBO_ACTION(base_func_combo),
  [TO_BASE_LAYER_3] = COMBO_ACTION(base_navsym_combo),
  [TO_FUNC_LAYER] = COMBO_ACTION(func_combo),
  [TO_NAVSYM_LAYER] = COMBO_ACTION(navsym_combo),
  [TO_NUM_LAYER] = COMBO_ACTION(num_combo),
  COMBO(esc_combo, KC_ESC),
  COMBO(lparen_combo, KC_LPRN),
  COMBO(rparen_combo, KC_RPRN),
  COMBO(underscore_combo, KC_UNDS),
  COMBO(dash_combo, KC_MINS),
  COMBO(equals_combo, KC_EQL),
  COMBO(dquote_combo, KC_DQUO),
  COMBO(squote_combo, KC_QUOT),
  COMBO(lsquare_combo, KC_LBRC),
  COMBO(rsquare_combo, KC_RBRC),
  COMBO(grv_combo, KC_GRV),
  COMBO(at_combo, KC_AT),
  COMBO(delete_combo, KC_DELETE),
  COMBO(backspace_combo, KC_BSPC),
  COMBO(backspace_combo_num, KC_BSPC),
  COMBO(tab_combo, KC_TAB),
  COMBO(carrot_combo, KC_CIRC),
  COMBO(dollar_combo, KC_DLR),
  COMBO(hash_combo, KC_HASH),
  COMBO(plus_combo, KC_PLUS),
  COMBO(exc_combo, KC_EXLM),
  COMBO(amp_combo, KC_AMPR),
  COMBO(star_combo, KC_ASTR),
  COMBO(grv_combo, KC_GRAVE),
  COMBO(bslash_combo, KC_BSLS)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case TO_BASE_LAYER_0:
      if (pressed) {
        layer_move(_BASE);
      }
      break;
    case TO_BASE_LAYER_1:
      if (pressed) {
        layer_move(_BASE);
      }
      break;
    case TO_BASE_LAYER_3:
      if (pressed) {
        layer_move(_BASE);
      }
      break;
    case TO_FUNC_LAYER:
      if (pressed) {
        layer_move(_FUNC);
      }
      break;
    case TO_NAVSYM_LAYER:
      if (pressed) {
        layer_move(_NAVSYM);
      }
      break;
    case TO_NUM_LAYER:
      if (pressed) {
        layer_move(_NUM);
      }
      break;
  }
}

