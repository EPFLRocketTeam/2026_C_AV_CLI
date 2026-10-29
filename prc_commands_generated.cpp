// GENERATED FILE -- do not edit by hand. Regenerate with generate_commands.py.
#include "prc_commands_generated.hpp"

#include <cstdlib>

namespace prc_cli {

void push_char(context* ctx, const driver* drv, char c) {
    switch (ctx->state) {
    case State_0: {
        switch (c) {
        case 'c': ctx->state = State_125; break;
        case 'f': ctx->state = State_58; break;
        case 'i': ctx->state = State_50; break;
        case 'l': ctx->state = State_112; break;
        case 's': ctx->state = State_1; break;
        case 'v': ctx->state = State_12; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_1: {
        switch (c) {
        case 'e': ctx->state = State_6; break;
        case 't': ctx->state = State_2; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_2: {
        switch (c) {
        case 'a': ctx->state = State_3; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_3: {
        switch (c) {
        case 't': ctx->state = State_4; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_4: {
        switch (c) {
        case 'e': ctx->state = State_5; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_5: {
        if (c == '\n') {
            drv->state_print(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_6: {
        switch (c) {
        case 'n': ctx->state = State_7; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_7: {
        switch (c) {
        case 's': ctx->state = State_8; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_8: {
        switch (c) {
        case 'o': ctx->state = State_9; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_9: {
        switch (c) {
        case 'r': ctx->state = State_10; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_10: {
        switch (c) {
        case 's': ctx->state = State_11; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_11: {
        if (c == '\n') {
            drv->sensors_print(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_12: {
        switch (c) {
        case 'a': ctx->state = State_13; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_13: {
        switch (c) {
        case 'l': ctx->state = State_14; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_14: {
        switch (c) {
        case 'v': ctx->state = State_15; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_15: {
        switch (c) {
        case 'e': ctx->state = State_16; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_16: {
        switch (c) {
        case ' ': ctx->state = State_17; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_17: {
        switch (c) {
        case 'b': ctx->state = State_40; break;
        case 'c': ctx->state = State_30; break;
        case 'm': ctx->state = State_45; break;
        case 's': ctx->state = State_23; break;
        case 'v': ctx->state = State_18; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_18: {
        switch (c) {
        case 'e': ctx->state = State_19; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_19: {
        switch (c) {
        case 'n': ctx->state = State_20; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_20: {
        switch (c) {
        case 't': ctx->state = State_21; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_21: {
        switch (c) {
        case ' ': ctx->state = State_22; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_22: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            if (strcmp(ctx->arg_buffer, "open") == 0 || strcmp(ctx->arg_buffer, "on") == 0) {
                drv->valve_vent(ctx->handler_ctx, true);
            } else if (strcmp(ctx->arg_buffer, "close") == 0 || strcmp(ctx->arg_buffer, "off") == 0) {
                drv->valve_vent(ctx->handler_ctx, false);
            } else if (drv->on_bad_argument != nullptr) {
                drv->on_bad_argument(ctx->handler_ctx);
            }
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_23: {
        switch (c) {
        case 'a': ctx->state = State_24; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_24: {
        switch (c) {
        case 'f': ctx->state = State_25; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_25: {
        switch (c) {
        case 'e': ctx->state = State_26; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_26: {
        switch (c) {
        case 't': ctx->state = State_27; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_27: {
        switch (c) {
        case 'y': ctx->state = State_28; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_28: {
        switch (c) {
        case ' ': ctx->state = State_29; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_29: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            if (strcmp(ctx->arg_buffer, "open") == 0 || strcmp(ctx->arg_buffer, "on") == 0) {
                drv->valve_safety(ctx->handler_ctx, true);
            } else if (strcmp(ctx->arg_buffer, "close") == 0 || strcmp(ctx->arg_buffer, "off") == 0) {
                drv->valve_safety(ctx->handler_ctx, false);
            } else if (drv->on_bad_argument != nullptr) {
                drv->on_bad_argument(ctx->handler_ctx);
            }
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_30: {
        switch (c) {
        case 'o': ctx->state = State_31; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_31: {
        switch (c) {
        case 'p': ctx->state = State_32; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_32: {
        switch (c) {
        case 'v': ctx->state = State_33; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_33: {
        switch (c) {
        case '_': ctx->state = State_34; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_34: {
        switch (c) {
        case 'v': ctx->state = State_35; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_35: {
        switch (c) {
        case 'e': ctx->state = State_36; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_36: {
        switch (c) {
        case 'n': ctx->state = State_37; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_37: {
        switch (c) {
        case 't': ctx->state = State_38; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_38: {
        switch (c) {
        case ' ': ctx->state = State_39; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_39: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            if (strcmp(ctx->arg_buffer, "open") == 0 || strcmp(ctx->arg_buffer, "on") == 0) {
                drv->valve_copv_vent(ctx->handler_ctx, true);
            } else if (strcmp(ctx->arg_buffer, "close") == 0 || strcmp(ctx->arg_buffer, "off") == 0) {
                drv->valve_copv_vent(ctx->handler_ctx, false);
            } else if (drv->on_bad_argument != nullptr) {
                drv->on_bad_argument(ctx->handler_ctx);
            }
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_40: {
        switch (c) {
        case 'a': ctx->state = State_41; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_41: {
        switch (c) {
        case 'l': ctx->state = State_42; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_42: {
        switch (c) {
        case 'l': ctx->state = State_43; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_43: {
        switch (c) {
        case ' ': ctx->state = State_44; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_44: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->valve_ball(ctx->handler_ctx, strtof(ctx->arg_buffer, nullptr));
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_45: {
        switch (c) {
        case 'e': ctx->state = State_48; break;
        case 'o': ctx->state = State_46; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_46: {
        switch (c) {
        case ' ': ctx->state = State_47; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_47: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            if (strcmp(ctx->arg_buffer, "open") == 0 || strcmp(ctx->arg_buffer, "on") == 0) {
                drv->valve_mo(ctx->handler_ctx, true);
            } else if (strcmp(ctx->arg_buffer, "close") == 0 || strcmp(ctx->arg_buffer, "off") == 0) {
                drv->valve_mo(ctx->handler_ctx, false);
            } else if (drv->on_bad_argument != nullptr) {
                drv->on_bad_argument(ctx->handler_ctx);
            }
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_48: {
        switch (c) {
        case ' ': ctx->state = State_49; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_49: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            if (strcmp(ctx->arg_buffer, "open") == 0 || strcmp(ctx->arg_buffer, "on") == 0) {
                drv->valve_me(ctx->handler_ctx, true);
            } else if (strcmp(ctx->arg_buffer, "close") == 0 || strcmp(ctx->arg_buffer, "off") == 0) {
                drv->valve_me(ctx->handler_ctx, false);
            } else if (drv->on_bad_argument != nullptr) {
                drv->on_bad_argument(ctx->handler_ctx);
            }
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_50: {
        switch (c) {
        case 'g': ctx->state = State_51; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_51: {
        switch (c) {
        case 'n': ctx->state = State_52; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_52: {
        switch (c) {
        case 'i': ctx->state = State_53; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_53: {
        switch (c) {
        case 't': ctx->state = State_54; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_54: {
        switch (c) {
        case 'e': ctx->state = State_55; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_55: {
        switch (c) {
        case 'r': ctx->state = State_56; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_56: {
        switch (c) {
        case ' ': ctx->state = State_57; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_57: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            if (strcmp(ctx->arg_buffer, "open") == 0 || strcmp(ctx->arg_buffer, "on") == 0) {
                drv->igniter(ctx->handler_ctx, true);
            } else if (strcmp(ctx->arg_buffer, "close") == 0 || strcmp(ctx->arg_buffer, "off") == 0) {
                drv->igniter(ctx->handler_ctx, false);
            } else if (drv->on_bad_argument != nullptr) {
                drv->on_bad_argument(ctx->handler_ctx);
            }
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_58: {
        switch (c) {
        case 's': ctx->state = State_59; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_59: {
        switch (c) {
        case 'm': ctx->state = State_60; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_60: {
        switch (c) {
        case ' ': ctx->state = State_61; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_61: {
        switch (c) {
        case 'a': ctx->state = State_94; break;
        case 'c': ctx->state = State_73; break;
        case 'i': ctx->state = State_88; break;
        case 'p': ctx->state = State_62; break;
        case 'r': ctx->state = State_107; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_62: {
        switch (c) {
        case 'a': ctx->state = State_99; break;
        case 'r': ctx->state = State_63; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_63: {
        switch (c) {
        case 'e': ctx->state = State_64; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_64: {
        switch (c) {
        case 's': ctx->state = State_65; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_65: {
        switch (c) {
        case 's': ctx->state = State_66; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_66: {
        switch (c) {
        case 'u': ctx->state = State_67; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_67: {
        switch (c) {
        case 'r': ctx->state = State_68; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_68: {
        switch (c) {
        case 'i': ctx->state = State_69; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_69: {
        switch (c) {
        case 'z': ctx->state = State_70; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_70: {
        switch (c) {
        case 'e': ctx->state = State_71; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_71: {
        switch (c) {
        case ' ': ctx->state = State_72; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_72: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            if (strcmp(ctx->arg_buffer, "open") == 0 || strcmp(ctx->arg_buffer, "on") == 0) {
                drv->fsm_pressurize(ctx->handler_ctx, true);
            } else if (strcmp(ctx->arg_buffer, "close") == 0 || strcmp(ctx->arg_buffer, "off") == 0) {
                drv->fsm_pressurize(ctx->handler_ctx, false);
            } else if (drv->on_bad_argument != nullptr) {
                drv->on_bad_argument(ctx->handler_ctx);
            }
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_73: {
        switch (c) {
        case 'l': ctx->state = State_74; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_74: {
        switch (c) {
        case 'e': ctx->state = State_75; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_75: {
        switch (c) {
        case 'a': ctx->state = State_76; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_76: {
        switch (c) {
        case 'r': ctx->state = State_77; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_77: {
        switch (c) {
        case '_': ctx->state = State_78; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_78: {
        switch (c) {
        case 't': ctx->state = State_79; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_79: {
        switch (c) {
        case 'o': ctx->state = State_80; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_80: {
        switch (c) {
        case '_': ctx->state = State_81; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_81: {
        switch (c) {
        case 'i': ctx->state = State_82; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_82: {
        switch (c) {
        case 'g': ctx->state = State_83; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_83: {
        switch (c) {
        case 'n': ctx->state = State_84; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_84: {
        switch (c) {
        case 'i': ctx->state = State_85; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_85: {
        switch (c) {
        case 't': ctx->state = State_86; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_86: {
        switch (c) {
        case 'e': ctx->state = State_87; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_87: {
        if (c == '\n') {
            drv->fsm_clear_to_ignite(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_88: {
        switch (c) {
        case 'g': ctx->state = State_89; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_89: {
        switch (c) {
        case 'n': ctx->state = State_90; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_90: {
        switch (c) {
        case 'i': ctx->state = State_91; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_91: {
        switch (c) {
        case 't': ctx->state = State_92; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_92: {
        switch (c) {
        case 'e': ctx->state = State_93; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_93: {
        if (c == '\n') {
            drv->fsm_ignite(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_94: {
        switch (c) {
        case 'b': ctx->state = State_95; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_95: {
        switch (c) {
        case 'o': ctx->state = State_96; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_96: {
        switch (c) {
        case 'r': ctx->state = State_97; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_97: {
        switch (c) {
        case 't': ctx->state = State_98; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_98: {
        if (c == '\n') {
            drv->fsm_abort(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_99: {
        switch (c) {
        case 's': ctx->state = State_100; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_100: {
        switch (c) {
        case 's': ctx->state = State_101; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_101: {
        switch (c) {
        case 'i': ctx->state = State_102; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_102: {
        switch (c) {
        case 'v': ctx->state = State_103; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_103: {
        switch (c) {
        case 'a': ctx->state = State_104; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_104: {
        switch (c) {
        case 't': ctx->state = State_105; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_105: {
        switch (c) {
        case 'e': ctx->state = State_106; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_106: {
        if (c == '\n') {
            drv->fsm_passivate(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_107: {
        switch (c) {
        case 'e': ctx->state = State_108; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_108: {
        switch (c) {
        case 's': ctx->state = State_109; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_109: {
        switch (c) {
        case 'e': ctx->state = State_110; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_110: {
        switch (c) {
        case 't': ctx->state = State_111; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_111: {
        if (c == '\n') {
            drv->fsm_reset(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_112: {
        switch (c) {
        case 'o': ctx->state = State_113; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_113: {
        switch (c) {
        case 'g': ctx->state = State_114; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_114: {
        switch (c) {
        case 's': ctx->state = State_115; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_115: {
        switch (c) {
        case ' ': ctx->state = State_116; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_116: {
        switch (c) {
        case 'c': ctx->state = State_121; break;
        case 'u': ctx->state = State_117; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_117: {
        switch (c) {
        case 's': ctx->state = State_118; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_118: {
        switch (c) {
        case 'b': ctx->state = State_119; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_119: {
        switch (c) {
        case ' ': ctx->state = State_120; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_120: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            if (strcmp(ctx->arg_buffer, "open") == 0 || strcmp(ctx->arg_buffer, "on") == 0) {
                drv->logs_usb(ctx->handler_ctx, true);
            } else if (strcmp(ctx->arg_buffer, "close") == 0 || strcmp(ctx->arg_buffer, "off") == 0) {
                drv->logs_usb(ctx->handler_ctx, false);
            } else if (drv->on_bad_argument != nullptr) {
                drv->on_bad_argument(ctx->handler_ctx);
            }
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_121: {
        switch (c) {
        case 'a': ctx->state = State_122; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_122: {
        switch (c) {
        case 'n': ctx->state = State_123; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_123: {
        switch (c) {
        case ' ': ctx->state = State_124; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_124: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            if (strcmp(ctx->arg_buffer, "open") == 0 || strcmp(ctx->arg_buffer, "on") == 0) {
                drv->logs_can(ctx->handler_ctx, true);
            } else if (strcmp(ctx->arg_buffer, "close") == 0 || strcmp(ctx->arg_buffer, "off") == 0) {
                drv->logs_can(ctx->handler_ctx, false);
            } else if (drv->on_bad_argument != nullptr) {
                drv->on_bad_argument(ctx->handler_ctx);
            }
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_125: {
        switch (c) {
        case 'o': ctx->state = State_126; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_126: {
        switch (c) {
        case 'n': ctx->state = State_127; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_127: {
        switch (c) {
        case 'f': ctx->state = State_128; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_128: {
        switch (c) {
        case 'i': ctx->state = State_129; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_129: {
        switch (c) {
        case 'g': ctx->state = State_130; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_130: {
        switch (c) {
        case ' ': ctx->state = State_131; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_131: {
        switch (c) {
        case 'c': ctx->state = State_144; break;
        case 'p': ctx->state = State_132; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_132: {
        switch (c) {
        case 'r': ctx->state = State_133; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_133: {
        switch (c) {
        case 'i': ctx->state = State_134; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_134: {
        switch (c) {
        case 'n': ctx->state = State_135; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_135: {
        switch (c) {
        case 't': ctx->state = State_136; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_136: {
        switch (c) {
        case ' ': ctx->state = State_137; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_137: {
        switch (c) {
        case 's': ctx->state = State_138; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_138: {
        switch (c) {
        case 't': ctx->state = State_139; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_139: {
        switch (c) {
        case 'a': ctx->state = State_140; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_140: {
        switch (c) {
        case 't': ctx->state = State_141; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_141: {
        switch (c) {
        case 'u': ctx->state = State_142; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_142: {
        switch (c) {
        case 's': ctx->state = State_143; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_143: {
        if (c == '\n') {
            drv->config_print_status(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_144: {
        switch (c) {
        case 'o': ctx->state = State_145; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_145: {
        switch (c) {
        case 'm': ctx->state = State_146; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_146: {
        switch (c) {
        case 'm': ctx->state = State_147; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_147: {
        switch (c) {
        case 'i': ctx->state = State_148; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_148: {
        switch (c) {
        case 't': ctx->state = State_149; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_149: {
        if (c == '\n') {
            drv->config_commit(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_Sink: {
        if (c == '\n') ctx->state = State_0;
        break;
    }
    }
}

}  // namespace prc_cli
