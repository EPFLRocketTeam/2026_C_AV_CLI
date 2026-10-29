// GENERATED FILE -- do not edit by hand. Regenerate with generate_commands.py.
#include "fc_commands_generated.hpp"

#include <cstdlib>

void push_char(context* ctx, const driver* drv, char c) {
    switch (ctx->state) {
    case State_0: {
        switch (c) {
        case 'a': ctx->state = State_142; break;
        case 'b': ctx->state = State_61; break;
        case 'c': ctx->state = State_117; break;
        case 'd': ctx->state = State_156; break;
        case 'f': ctx->state = State_126; break;
        case 'l': ctx->state = State_307; break;
        case 'm': ctx->state = State_12; break;
        case 'p': ctx->state = State_1; break;
        case 'r': ctx->state = State_149; break;
        case 's': ctx->state = State_45; break;
        case 'v': ctx->state = State_26; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_1: {
        switch (c) {
        case 'r': ctx->state = State_2; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_2: {
        switch (c) {
        case 'c': ctx->state = State_75; break;
        case 'e': ctx->state = State_3; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_3: {
        switch (c) {
        case 's': ctx->state = State_4; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_4: {
        switch (c) {
        case 's': ctx->state = State_5; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_5: {
        switch (c) {
        case 'u': ctx->state = State_6; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_6: {
        switch (c) {
        case 'r': ctx->state = State_7; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_7: {
        switch (c) {
        case 'i': ctx->state = State_8; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_8: {
        switch (c) {
        case 'z': ctx->state = State_9; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_9: {
        switch (c) {
        case 'e': ctx->state = State_10; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_10: {
        switch (c) {
        case ' ': ctx->state = State_11; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_11: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            if (strcmp(ctx->arg_buffer, "open") == 0 || strcmp(ctx->arg_buffer, "on") == 0) {
                drv->pressurize(ctx->handler_ctx, true);
            } else if (strcmp(ctx->arg_buffer, "close") == 0 || strcmp(ctx->arg_buffer, "off") == 0) {
                drv->pressurize(ctx->handler_ctx, false);
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
        case 'i': ctx->state = State_14; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_14: {
        switch (c) {
        case 'n': ctx->state = State_15; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_15: {
        switch (c) {
        case ' ': ctx->state = State_16; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_16: {
        switch (c) {
        case 'f': ctx->state = State_21; break;
        case 'l': ctx->state = State_17; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_17: {
        switch (c) {
        case 'o': ctx->state = State_18; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_18: {
        switch (c) {
        case 'x': ctx->state = State_19; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_19: {
        switch (c) {
        case ' ': ctx->state = State_20; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_20: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            if (strcmp(ctx->arg_buffer, "open") == 0 || strcmp(ctx->arg_buffer, "on") == 0) {
                drv->main_lox(ctx->handler_ctx, true);
            } else if (strcmp(ctx->arg_buffer, "close") == 0 || strcmp(ctx->arg_buffer, "off") == 0) {
                drv->main_lox(ctx->handler_ctx, false);
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
    case State_21: {
        switch (c) {
        case 'u': ctx->state = State_22; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_22: {
        switch (c) {
        case 'e': ctx->state = State_23; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_23: {
        switch (c) {
        case 'l': ctx->state = State_24; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_24: {
        switch (c) {
        case ' ': ctx->state = State_25; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_25: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            if (strcmp(ctx->arg_buffer, "open") == 0 || strcmp(ctx->arg_buffer, "on") == 0) {
                drv->main_fuel(ctx->handler_ctx, true);
            } else if (strcmp(ctx->arg_buffer, "close") == 0 || strcmp(ctx->arg_buffer, "off") == 0) {
                drv->main_fuel(ctx->handler_ctx, false);
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
    case State_26: {
        switch (c) {
        case 'e': ctx->state = State_27; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_27: {
        switch (c) {
        case 'n': ctx->state = State_28; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_28: {
        switch (c) {
        case 't': ctx->state = State_29; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_29: {
        switch (c) {
        case ' ': ctx->state = State_30; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_30: {
        switch (c) {
        case 'c': ctx->state = State_31; break;
        case 'f': ctx->state = State_40; break;
        case 'l': ctx->state = State_36; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_31: {
        switch (c) {
        case 'o': ctx->state = State_32; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_32: {
        switch (c) {
        case 'p': ctx->state = State_33; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_33: {
        switch (c) {
        case 'v': ctx->state = State_34; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_34: {
        switch (c) {
        case ' ': ctx->state = State_35; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_35: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            if (strcmp(ctx->arg_buffer, "open") == 0 || strcmp(ctx->arg_buffer, "on") == 0) {
                drv->vent_copv(ctx->handler_ctx, true);
            } else if (strcmp(ctx->arg_buffer, "close") == 0 || strcmp(ctx->arg_buffer, "off") == 0) {
                drv->vent_copv(ctx->handler_ctx, false);
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
    case State_36: {
        switch (c) {
        case 'o': ctx->state = State_37; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_37: {
        switch (c) {
        case 'x': ctx->state = State_38; break;
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
                drv->vent_lox(ctx->handler_ctx, true);
            } else if (strcmp(ctx->arg_buffer, "close") == 0 || strcmp(ctx->arg_buffer, "off") == 0) {
                drv->vent_lox(ctx->handler_ctx, false);
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
        case 'u': ctx->state = State_41; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_41: {
        switch (c) {
        case 'e': ctx->state = State_42; break;
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
            if (strcmp(ctx->arg_buffer, "open") == 0 || strcmp(ctx->arg_buffer, "on") == 0) {
                drv->vent_fuel(ctx->handler_ctx, true);
            } else if (strcmp(ctx->arg_buffer, "close") == 0 || strcmp(ctx->arg_buffer, "off") == 0) {
                drv->vent_fuel(ctx->handler_ctx, false);
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
    case State_45: {
        switch (c) {
        case 'a': ctx->state = State_46; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_46: {
        switch (c) {
        case 'f': ctx->state = State_47; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_47: {
        switch (c) {
        case 'e': ctx->state = State_48; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_48: {
        switch (c) {
        case 't': ctx->state = State_49; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_49: {
        switch (c) {
        case 'y': ctx->state = State_50; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_50: {
        switch (c) {
        case ' ': ctx->state = State_51; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_51: {
        switch (c) {
        case 'f': ctx->state = State_56; break;
        case 'l': ctx->state = State_52; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_52: {
        switch (c) {
        case 'o': ctx->state = State_53; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_53: {
        switch (c) {
        case 'x': ctx->state = State_54; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_54: {
        switch (c) {
        case ' ': ctx->state = State_55; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_55: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            if (strcmp(ctx->arg_buffer, "open") == 0 || strcmp(ctx->arg_buffer, "on") == 0) {
                drv->safety_lox(ctx->handler_ctx, true);
            } else if (strcmp(ctx->arg_buffer, "close") == 0 || strcmp(ctx->arg_buffer, "off") == 0) {
                drv->safety_lox(ctx->handler_ctx, false);
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
    case State_56: {
        switch (c) {
        case 'u': ctx->state = State_57; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_57: {
        switch (c) {
        case 'e': ctx->state = State_58; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_58: {
        switch (c) {
        case 'l': ctx->state = State_59; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_59: {
        switch (c) {
        case ' ': ctx->state = State_60; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_60: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            if (strcmp(ctx->arg_buffer, "open") == 0 || strcmp(ctx->arg_buffer, "on") == 0) {
                drv->safety_fuel(ctx->handler_ctx, true);
            } else if (strcmp(ctx->arg_buffer, "close") == 0 || strcmp(ctx->arg_buffer, "off") == 0) {
                drv->safety_fuel(ctx->handler_ctx, false);
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
    case State_61: {
        switch (c) {
        case 'a': ctx->state = State_62; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_62: {
        switch (c) {
        case 'l': ctx->state = State_63; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_63: {
        switch (c) {
        case 'l': ctx->state = State_64; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_64: {
        switch (c) {
        case ' ': ctx->state = State_65; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_65: {
        switch (c) {
        case 'f': ctx->state = State_70; break;
        case 'l': ctx->state = State_66; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_66: {
        switch (c) {
        case 'o': ctx->state = State_67; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_67: {
        switch (c) {
        case 'x': ctx->state = State_68; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_68: {
        switch (c) {
        case ' ': ctx->state = State_69; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_69: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->ball_lox(ctx->handler_ctx, strtof(ctx->arg_buffer, nullptr));
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_70: {
        switch (c) {
        case 'u': ctx->state = State_71; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_71: {
        switch (c) {
        case 'e': ctx->state = State_72; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_72: {
        switch (c) {
        case 'l': ctx->state = State_73; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_73: {
        switch (c) {
        case ' ': ctx->state = State_74; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_74: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->ball_fuel(ctx->handler_ctx, strtof(ctx->arg_buffer, nullptr));
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_75: {
        switch (c) {
        case ' ': ctx->state = State_76; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_76: {
        switch (c) {
        case 'a': ctx->state = State_112; break;
        case 'c': ctx->state = State_77; break;
        case 'i': ctx->state = State_92; break;
        case 'p': ctx->state = State_98; break;
        case 'r': ctx->state = State_107; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_77: {
        switch (c) {
        case 'l': ctx->state = State_78; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_78: {
        switch (c) {
        case 'e': ctx->state = State_79; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_79: {
        switch (c) {
        case 'a': ctx->state = State_80; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_80: {
        switch (c) {
        case 'r': ctx->state = State_81; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_81: {
        switch (c) {
        case '_': ctx->state = State_82; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_82: {
        switch (c) {
        case 't': ctx->state = State_83; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_83: {
        switch (c) {
        case 'o': ctx->state = State_84; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_84: {
        switch (c) {
        case '_': ctx->state = State_85; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_85: {
        switch (c) {
        case 'i': ctx->state = State_86; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_86: {
        switch (c) {
        case 'g': ctx->state = State_87; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_87: {
        switch (c) {
        case 'n': ctx->state = State_88; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_88: {
        switch (c) {
        case 'i': ctx->state = State_89; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_89: {
        switch (c) {
        case 't': ctx->state = State_90; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_90: {
        switch (c) {
        case 'e': ctx->state = State_91; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_91: {
        if (c == '\n') {
            drv->prc_clear_to_ignite(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_92: {
        switch (c) {
        case 'g': ctx->state = State_93; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_93: {
        switch (c) {
        case 'n': ctx->state = State_94; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_94: {
        switch (c) {
        case 'i': ctx->state = State_95; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_95: {
        switch (c) {
        case 't': ctx->state = State_96; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_96: {
        switch (c) {
        case 'e': ctx->state = State_97; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_97: {
        if (c == '\n') {
            drv->prc_ignite(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_98: {
        switch (c) {
        case 'a': ctx->state = State_99; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
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
            drv->prc_passivate(ctx->handler_ctx);
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
            drv->prc_reset(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_112: {
        switch (c) {
        case 'b': ctx->state = State_113; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_113: {
        switch (c) {
        case 'o': ctx->state = State_114; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_114: {
        switch (c) {
        case 'r': ctx->state = State_115; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_115: {
        switch (c) {
        case 't': ctx->state = State_116; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_116: {
        if (c == '\n') {
            drv->prc_abort(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_117: {
        switch (c) {
        case 'a': ctx->state = State_118; break;
        case 'o': ctx->state = State_241; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_118: {
        switch (c) {
        case 'l': ctx->state = State_119; break;
        case 'm': ctx->state = State_254; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_119: {
        switch (c) {
        case 'i': ctx->state = State_120; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_120: {
        switch (c) {
        case 'b': ctx->state = State_121; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_121: {
        switch (c) {
        case 'r': ctx->state = State_122; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_122: {
        switch (c) {
        case 'a': ctx->state = State_123; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_123: {
        switch (c) {
        case 't': ctx->state = State_124; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_124: {
        switch (c) {
        case 'e': ctx->state = State_125; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_125: {
        if (c == '\n') {
            drv->av_calibrate(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_126: {
        switch (c) {
        case 'o': ctx->state = State_127; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_127: {
        switch (c) {
        case 'r': ctx->state = State_128; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_128: {
        switch (c) {
        case 'c': ctx->state = State_129; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_129: {
        switch (c) {
        case 'e': ctx->state = State_130; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_130: {
        switch (c) {
        case '_': ctx->state = State_131; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_131: {
        switch (c) {
        case 'c': ctx->state = State_132; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_132: {
        switch (c) {
        case 'a': ctx->state = State_133; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_133: {
        switch (c) {
        case 'l': ctx->state = State_134; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_134: {
        switch (c) {
        case 'i': ctx->state = State_135; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_135: {
        switch (c) {
        case 'b': ctx->state = State_136; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_136: {
        switch (c) {
        case 'r': ctx->state = State_137; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_137: {
        switch (c) {
        case 'a': ctx->state = State_138; break;
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
        case 'e': ctx->state = State_140; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_140: {
        switch (c) {
        case 'd': ctx->state = State_141; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_141: {
        if (c == '\n') {
            drv->av_force_calibrated(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_142: {
        switch (c) {
        case 'b': ctx->state = State_145; break;
        case 'r': ctx->state = State_143; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_143: {
        switch (c) {
        case 'm': ctx->state = State_144; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_144: {
        if (c == '\n') {
            drv->av_arm(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_145: {
        switch (c) {
        case 'o': ctx->state = State_146; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_146: {
        switch (c) {
        case 'r': ctx->state = State_147; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_147: {
        switch (c) {
        case 't': ctx->state = State_148; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_148: {
        if (c == '\n') {
            drv->av_abort(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_149: {
        switch (c) {
        case 'e': ctx->state = State_150; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_150: {
        switch (c) {
        case 'c': ctx->state = State_151; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_151: {
        switch (c) {
        case 'o': ctx->state = State_152; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_152: {
        switch (c) {
        case 'v': ctx->state = State_153; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_153: {
        switch (c) {
        case 'e': ctx->state = State_154; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_154: {
        switch (c) {
        case 'r': ctx->state = State_155; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_155: {
        if (c == '\n') {
            drv->av_recover(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_156: {
        switch (c) {
        case 'p': ctx->state = State_157; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_157: {
        switch (c) {
        case 'r': ctx->state = State_158; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_158: {
        switch (c) {
        case ' ': ctx->state = State_159; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_159: {
        switch (c) {
        case 'b': ctx->state = State_226; break;
        case 'e': ctx->state = State_193; break;
        case 'l': ctx->state = State_160; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_160: {
        switch (c) {
        case 'o': ctx->state = State_161; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_161: {
        switch (c) {
        case 'x': ctx->state = State_162; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_162: {
        switch (c) {
        case ' ': ctx->state = State_163; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_163: {
        switch (c) {
        case 'a': ctx->state = State_175; break;
        case 'p': ctx->state = State_164; break;
        case 'r': ctx->state = State_188; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_164: {
        switch (c) {
        case 'a': ctx->state = State_180; break;
        case 'r': ctx->state = State_165; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_165: {
        switch (c) {
        case 'e': ctx->state = State_166; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_166: {
        switch (c) {
        case 's': ctx->state = State_167; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_167: {
        switch (c) {
        case 's': ctx->state = State_168; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_168: {
        switch (c) {
        case 'u': ctx->state = State_169; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_169: {
        switch (c) {
        case 'r': ctx->state = State_170; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_170: {
        switch (c) {
        case 'i': ctx->state = State_171; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_171: {
        switch (c) {
        case 'z': ctx->state = State_172; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_172: {
        switch (c) {
        case 'e': ctx->state = State_173; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_173: {
        switch (c) {
        case ' ': ctx->state = State_174; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_174: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            if (strcmp(ctx->arg_buffer, "open") == 0 || strcmp(ctx->arg_buffer, "on") == 0) {
                drv->dpr_lox_pressurize(ctx->handler_ctx, true);
            } else if (strcmp(ctx->arg_buffer, "close") == 0 || strcmp(ctx->arg_buffer, "off") == 0) {
                drv->dpr_lox_pressurize(ctx->handler_ctx, false);
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
    case State_175: {
        switch (c) {
        case 'b': ctx->state = State_176; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_176: {
        switch (c) {
        case 'o': ctx->state = State_177; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_177: {
        switch (c) {
        case 'r': ctx->state = State_178; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_178: {
        switch (c) {
        case 't': ctx->state = State_179; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_179: {
        if (c == '\n') {
            drv->dpr_lox_abort(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_180: {
        switch (c) {
        case 's': ctx->state = State_181; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_181: {
        switch (c) {
        case 's': ctx->state = State_182; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_182: {
        switch (c) {
        case 'i': ctx->state = State_183; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_183: {
        switch (c) {
        case 'v': ctx->state = State_184; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_184: {
        switch (c) {
        case 'a': ctx->state = State_185; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_185: {
        switch (c) {
        case 't': ctx->state = State_186; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_186: {
        switch (c) {
        case 'e': ctx->state = State_187; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_187: {
        if (c == '\n') {
            drv->dpr_lox_passivate(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_188: {
        switch (c) {
        case 'e': ctx->state = State_189; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_189: {
        switch (c) {
        case 's': ctx->state = State_190; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_190: {
        switch (c) {
        case 'e': ctx->state = State_191; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_191: {
        switch (c) {
        case 't': ctx->state = State_192; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_192: {
        if (c == '\n') {
            drv->dpr_lox_reset(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_193: {
        switch (c) {
        case 't': ctx->state = State_194; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_194: {
        switch (c) {
        case 'h': ctx->state = State_195; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_195: {
        switch (c) {
        case ' ': ctx->state = State_196; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_196: {
        switch (c) {
        case 'a': ctx->state = State_208; break;
        case 'p': ctx->state = State_197; break;
        case 'r': ctx->state = State_221; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_197: {
        switch (c) {
        case 'a': ctx->state = State_213; break;
        case 'r': ctx->state = State_198; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_198: {
        switch (c) {
        case 'e': ctx->state = State_199; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_199: {
        switch (c) {
        case 's': ctx->state = State_200; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_200: {
        switch (c) {
        case 's': ctx->state = State_201; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_201: {
        switch (c) {
        case 'u': ctx->state = State_202; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_202: {
        switch (c) {
        case 'r': ctx->state = State_203; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_203: {
        switch (c) {
        case 'i': ctx->state = State_204; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_204: {
        switch (c) {
        case 'z': ctx->state = State_205; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_205: {
        switch (c) {
        case 'e': ctx->state = State_206; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_206: {
        switch (c) {
        case ' ': ctx->state = State_207; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_207: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            if (strcmp(ctx->arg_buffer, "open") == 0 || strcmp(ctx->arg_buffer, "on") == 0) {
                drv->dpr_eth_pressurize(ctx->handler_ctx, true);
            } else if (strcmp(ctx->arg_buffer, "close") == 0 || strcmp(ctx->arg_buffer, "off") == 0) {
                drv->dpr_eth_pressurize(ctx->handler_ctx, false);
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
    case State_208: {
        switch (c) {
        case 'b': ctx->state = State_209; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_209: {
        switch (c) {
        case 'o': ctx->state = State_210; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_210: {
        switch (c) {
        case 'r': ctx->state = State_211; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_211: {
        switch (c) {
        case 't': ctx->state = State_212; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_212: {
        if (c == '\n') {
            drv->dpr_eth_abort(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_213: {
        switch (c) {
        case 's': ctx->state = State_214; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_214: {
        switch (c) {
        case 's': ctx->state = State_215; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_215: {
        switch (c) {
        case 'i': ctx->state = State_216; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_216: {
        switch (c) {
        case 'v': ctx->state = State_217; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_217: {
        switch (c) {
        case 'a': ctx->state = State_218; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_218: {
        switch (c) {
        case 't': ctx->state = State_219; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_219: {
        switch (c) {
        case 'e': ctx->state = State_220; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_220: {
        if (c == '\n') {
            drv->dpr_eth_passivate(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_221: {
        switch (c) {
        case 'e': ctx->state = State_222; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_222: {
        switch (c) {
        case 's': ctx->state = State_223; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_223: {
        switch (c) {
        case 'e': ctx->state = State_224; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_224: {
        switch (c) {
        case 't': ctx->state = State_225; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_225: {
        if (c == '\n') {
            drv->dpr_eth_reset(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_226: {
        switch (c) {
        case 'r': ctx->state = State_227; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_227: {
        switch (c) {
        case 'o': ctx->state = State_228; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_228: {
        switch (c) {
        case 'a': ctx->state = State_229; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_229: {
        switch (c) {
        case 'd': ctx->state = State_230; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_230: {
        switch (c) {
        case 'c': ctx->state = State_231; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_231: {
        switch (c) {
        case 'a': ctx->state = State_232; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_232: {
        switch (c) {
        case 's': ctx->state = State_233; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_233: {
        switch (c) {
        case 't': ctx->state = State_234; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_234: {
        switch (c) {
        case '_': ctx->state = State_235; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_235: {
        switch (c) {
        case 'a': ctx->state = State_236; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_236: {
        switch (c) {
        case 'b': ctx->state = State_237; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_237: {
        switch (c) {
        case 'o': ctx->state = State_238; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_238: {
        switch (c) {
        case 'r': ctx->state = State_239; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_239: {
        switch (c) {
        case 't': ctx->state = State_240; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_240: {
        if (c == '\n') {
            drv->dpr_broadcast_abort(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_241: {
        switch (c) {
        case 'l': ctx->state = State_242; break;
        case 'n': ctx->state = State_354; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_242: {
        switch (c) {
        case 'd': ctx->state = State_243; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_243: {
        switch (c) {
        case 'f': ctx->state = State_244; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_244: {
        switch (c) {
        case 'l': ctx->state = State_245; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_245: {
        switch (c) {
        case 'o': ctx->state = State_246; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_246: {
        switch (c) {
        case 'w': ctx->state = State_247; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_247: {
        switch (c) {
        case ' ': ctx->state = State_248; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_248: {
        switch (c) {
        case 'r': ctx->state = State_249; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_249: {
        switch (c) {
        case 'e': ctx->state = State_250; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_250: {
        switch (c) {
        case 'a': ctx->state = State_251; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_251: {
        switch (c) {
        case 'r': ctx->state = State_252; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_252: {
        switch (c) {
        case 'm': ctx->state = State_253; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_253: {
        if (c == '\n') {
            drv->coldflow_rearm(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_254: {
        switch (c) {
        case 'e': ctx->state = State_255; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_255: {
        switch (c) {
        case 'r': ctx->state = State_256; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_256: {
        switch (c) {
        case 'a': ctx->state = State_257; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_257: {
        switch (c) {
        case 's': ctx->state = State_258; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_258: {
        switch (c) {
        case ' ': ctx->state = State_259; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_259: {
        switch (c) {
        case 'a': ctx->state = State_295; break;
        case 'd': ctx->state = State_260; break;
        case 'r': ctx->state = State_300; break;
        case 's': ctx->state = State_288; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_260: {
        switch (c) {
        case 'i': ctx->state = State_261; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_261: {
        switch (c) {
        case 's': ctx->state = State_262; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_262: {
        switch (c) {
        case 'p': ctx->state = State_263; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_263: {
        switch (c) {
        case 'l': ctx->state = State_264; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_264: {
        switch (c) {
        case 'a': ctx->state = State_265; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_265: {
        switch (c) {
        case 'y': ctx->state = State_266; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_266: {
        switch (c) {
        case ' ': ctx->state = State_267; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_267: {
        switch (c) {
        case 'a': ctx->state = State_268; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_268: {
        switch (c) {
        case 'e': ctx->state = State_269; break;
        case 'l': ctx->state = State_286; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_269: {
        switch (c) {
        case 'r': ctx->state = State_270; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_270: {
        switch (c) {
        case 'o': ctx->state = State_271; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_271: {
        switch (c) {
        case '_': ctx->state = State_272; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_272: {
        switch (c) {
        case 'b': ctx->state = State_273; break;
        case 's': ctx->state = State_279; break;
        case 't': ctx->state = State_276; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_273: {
        switch (c) {
        case 'o': ctx->state = State_274; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_274: {
        switch (c) {
        case 't': ctx->state = State_275; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_275: {
        if (c == '\n') {
            drv->cameras_display_aero_bot(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_276: {
        switch (c) {
        case 'o': ctx->state = State_277; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_277: {
        switch (c) {
        case 'p': ctx->state = State_278; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_278: {
        if (c == '\n') {
            drv->cameras_display_aero_top(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_279: {
        switch (c) {
        case 'e': ctx->state = State_280; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_280: {
        switch (c) {
        case 'p': ctx->state = State_281; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_281: {
        switch (c) {
        case 'm': ctx->state = State_282; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_282: {
        switch (c) {
        case 'e': ctx->state = State_283; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_283: {
        switch (c) {
        case 'c': ctx->state = State_284; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_284: {
        switch (c) {
        case 'h': ctx->state = State_285; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_285: {
        if (c == '\n') {
            drv->cameras_display_sepmech(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_286: {
        switch (c) {
        case 'l': ctx->state = State_287; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_287: {
        if (c == '\n') {
            drv->cameras_display_all(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_288: {
        switch (c) {
        case 't': ctx->state = State_289; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_289: {
        switch (c) {
        case 'a': ctx->state = State_290; break;
        case 'o': ctx->state = State_293; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_290: {
        switch (c) {
        case 'r': ctx->state = State_291; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_291: {
        switch (c) {
        case 't': ctx->state = State_292; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_292: {
        if (c == '\n') {
            drv->cameras_start(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_293: {
        switch (c) {
        case 'p': ctx->state = State_294; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_294: {
        if (c == '\n') {
            drv->cameras_stop(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_295: {
        switch (c) {
        case 'b': ctx->state = State_296; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_296: {
        switch (c) {
        case 'o': ctx->state = State_297; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_297: {
        switch (c) {
        case 'r': ctx->state = State_298; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_298: {
        switch (c) {
        case 't': ctx->state = State_299; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_299: {
        if (c == '\n') {
            drv->cameras_abort(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_300: {
        switch (c) {
        case 'e': ctx->state = State_301; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_301: {
        switch (c) {
        case 'c': ctx->state = State_302; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_302: {
        switch (c) {
        case 'o': ctx->state = State_303; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_303: {
        switch (c) {
        case 'v': ctx->state = State_304; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_304: {
        switch (c) {
        case 'e': ctx->state = State_305; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_305: {
        switch (c) {
        case 'r': ctx->state = State_306; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_306: {
        if (c == '\n') {
            drv->cameras_recover(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_307: {
        switch (c) {
        case 'o': ctx->state = State_308; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_308: {
        switch (c) {
        case 'g': ctx->state = State_309; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_309: {
        switch (c) {
        case 's': ctx->state = State_310; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_310: {
        switch (c) {
        case ' ': ctx->state = State_311; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_311: {
        switch (c) {
        case 'c': ctx->state = State_312; break;
        case 'u': ctx->state = State_333; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_312: {
        switch (c) {
        case 'a': ctx->state = State_313; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_313: {
        switch (c) {
        case 'n': ctx->state = State_314; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_314: {
        switch (c) {
        case ' ': ctx->state = State_315; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_315: {
        switch (c) {
        case 'e': ctx->state = State_319; break;
        case 'f': ctx->state = State_316; break;
        case 'l': ctx->state = State_323; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_316: {
        switch (c) {
        case 'c': ctx->state = State_317; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_317: {
        switch (c) {
        case ' ': ctx->state = State_318; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_318: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            if (strcmp(ctx->arg_buffer, "open") == 0 || strcmp(ctx->arg_buffer, "on") == 0) {
                drv->logs_can_fc(ctx->handler_ctx, true);
            } else if (strcmp(ctx->arg_buffer, "close") == 0 || strcmp(ctx->arg_buffer, "off") == 0) {
                drv->logs_can_fc(ctx->handler_ctx, false);
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
    case State_319: {
        switch (c) {
        case 'n': ctx->state = State_327; break;
        case 't': ctx->state = State_320; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_320: {
        switch (c) {
        case 'h': ctx->state = State_321; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_321: {
        switch (c) {
        case ' ': ctx->state = State_322; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_322: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            if (strcmp(ctx->arg_buffer, "open") == 0 || strcmp(ctx->arg_buffer, "on") == 0) {
                drv->logs_can_eth(ctx->handler_ctx, true);
            } else if (strcmp(ctx->arg_buffer, "close") == 0 || strcmp(ctx->arg_buffer, "off") == 0) {
                drv->logs_can_eth(ctx->handler_ctx, false);
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
    case State_323: {
        switch (c) {
        case 'o': ctx->state = State_324; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_324: {
        switch (c) {
        case 'x': ctx->state = State_325; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_325: {
        switch (c) {
        case ' ': ctx->state = State_326; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_326: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            if (strcmp(ctx->arg_buffer, "open") == 0 || strcmp(ctx->arg_buffer, "on") == 0) {
                drv->logs_can_lox(ctx->handler_ctx, true);
            } else if (strcmp(ctx->arg_buffer, "close") == 0 || strcmp(ctx->arg_buffer, "off") == 0) {
                drv->logs_can_lox(ctx->handler_ctx, false);
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
    case State_327: {
        switch (c) {
        case 'g': ctx->state = State_328; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_328: {
        switch (c) {
        case 'i': ctx->state = State_329; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_329: {
        switch (c) {
        case 'n': ctx->state = State_330; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_330: {
        switch (c) {
        case 'e': ctx->state = State_331; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_331: {
        switch (c) {
        case ' ': ctx->state = State_332; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_332: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            if (strcmp(ctx->arg_buffer, "open") == 0 || strcmp(ctx->arg_buffer, "on") == 0) {
                drv->logs_can_engine(ctx->handler_ctx, true);
            } else if (strcmp(ctx->arg_buffer, "close") == 0 || strcmp(ctx->arg_buffer, "off") == 0) {
                drv->logs_can_engine(ctx->handler_ctx, false);
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
    case State_333: {
        switch (c) {
        case 's': ctx->state = State_334; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_334: {
        switch (c) {
        case 'b': ctx->state = State_335; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_335: {
        switch (c) {
        case ' ': ctx->state = State_336; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_336: {
        switch (c) {
        case 'e': ctx->state = State_340; break;
        case 'f': ctx->state = State_337; break;
        case 'l': ctx->state = State_344; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_337: {
        switch (c) {
        case 'c': ctx->state = State_338; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_338: {
        switch (c) {
        case ' ': ctx->state = State_339; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_339: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            if (strcmp(ctx->arg_buffer, "open") == 0 || strcmp(ctx->arg_buffer, "on") == 0) {
                drv->logs_usb_fc(ctx->handler_ctx, true);
            } else if (strcmp(ctx->arg_buffer, "close") == 0 || strcmp(ctx->arg_buffer, "off") == 0) {
                drv->logs_usb_fc(ctx->handler_ctx, false);
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
    case State_340: {
        switch (c) {
        case 'n': ctx->state = State_348; break;
        case 't': ctx->state = State_341; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_341: {
        switch (c) {
        case 'h': ctx->state = State_342; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_342: {
        switch (c) {
        case ' ': ctx->state = State_343; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_343: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            if (strcmp(ctx->arg_buffer, "open") == 0 || strcmp(ctx->arg_buffer, "on") == 0) {
                drv->logs_usb_eth(ctx->handler_ctx, true);
            } else if (strcmp(ctx->arg_buffer, "close") == 0 || strcmp(ctx->arg_buffer, "off") == 0) {
                drv->logs_usb_eth(ctx->handler_ctx, false);
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
    case State_344: {
        switch (c) {
        case 'o': ctx->state = State_345; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_345: {
        switch (c) {
        case 'x': ctx->state = State_346; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_346: {
        switch (c) {
        case ' ': ctx->state = State_347; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_347: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            if (strcmp(ctx->arg_buffer, "open") == 0 || strcmp(ctx->arg_buffer, "on") == 0) {
                drv->logs_usb_lox(ctx->handler_ctx, true);
            } else if (strcmp(ctx->arg_buffer, "close") == 0 || strcmp(ctx->arg_buffer, "off") == 0) {
                drv->logs_usb_lox(ctx->handler_ctx, false);
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
    case State_348: {
        switch (c) {
        case 'g': ctx->state = State_349; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_349: {
        switch (c) {
        case 'i': ctx->state = State_350; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_350: {
        switch (c) {
        case 'n': ctx->state = State_351; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_351: {
        switch (c) {
        case 'e': ctx->state = State_352; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_352: {
        switch (c) {
        case ' ': ctx->state = State_353; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_353: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            if (strcmp(ctx->arg_buffer, "open") == 0 || strcmp(ctx->arg_buffer, "on") == 0) {
                drv->logs_usb_engine(ctx->handler_ctx, true);
            } else if (strcmp(ctx->arg_buffer, "close") == 0 || strcmp(ctx->arg_buffer, "off") == 0) {
                drv->logs_usb_engine(ctx->handler_ctx, false);
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
    case State_354: {
        switch (c) {
        case 'f': ctx->state = State_355; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_355: {
        switch (c) {
        case 'i': ctx->state = State_356; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_356: {
        switch (c) {
        case 'g': ctx->state = State_357; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_357: {
        switch (c) {
        case ' ': ctx->state = State_358; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_358: {
        switch (c) {
        case 'b': ctx->state = State_627; break;
        case 'c': ctx->state = State_688; break;
        case 'i': ctx->state = State_569; break;
        case 'p': ctx->state = State_359; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_359: {
        switch (c) {
        case 'r': ctx->state = State_360; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_360: {
        switch (c) {
        case 'e': ctx->state = State_361; break;
        case 'i': ctx->state = State_697; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_361: {
        switch (c) {
        case 's': ctx->state = State_362; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_362: {
        switch (c) {
        case 's': ctx->state = State_363; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_363: {
        switch (c) {
        case 'u': ctx->state = State_364; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_364: {
        switch (c) {
        case 'r': ctx->state = State_365; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_365: {
        switch (c) {
        case 'i': ctx->state = State_366; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_366: {
        switch (c) {
        case 'z': ctx->state = State_367; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_367: {
        switch (c) {
        case 'e': ctx->state = State_368; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_368: {
        switch (c) {
        case ' ': ctx->state = State_369; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_369: {
        switch (c) {
        case 'b': ctx->state = State_381; break;
        case 'h': ctx->state = State_370; break;
        case 'm': ctx->state = State_476; break;
        case 'p': ctx->state = State_425; break;
        case 's': ctx->state = State_401; break;
        case 't': ctx->state = State_451; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_370: {
        switch (c) {
        case 'o': ctx->state = State_371; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_371: {
        switch (c) {
        case 'l': ctx->state = State_372; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_372: {
        switch (c) {
        case 'd': ctx->state = State_373; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_373: {
        switch (c) {
        case '_': ctx->state = State_374; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_374: {
        switch (c) {
        case 'd': ctx->state = State_375; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_375: {
        switch (c) {
        case 'e': ctx->state = State_376; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_376: {
        switch (c) {
        case 'l': ctx->state = State_377; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_377: {
        switch (c) {
        case 'a': ctx->state = State_378; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_378: {
        switch (c) {
        case 'y': ctx->state = State_379; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_379: {
        switch (c) {
        case ' ': ctx->state = State_380; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_380: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->config_pressurize_hold_delay(ctx->handler_ctx, strtol(ctx->arg_buffer, nullptr, 10));
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_381: {
        switch (c) {
        case 'v': ctx->state = State_382; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_382: {
        switch (c) {
        case '_': ctx->state = State_383; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_383: {
        switch (c) {
        case 'o': ctx->state = State_384; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_384: {
        switch (c) {
        case 'p': ctx->state = State_385; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_385: {
        switch (c) {
        case 'e': ctx->state = State_386; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_386: {
        switch (c) {
        case 'n': ctx->state = State_387; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_387: {
        switch (c) {
        case 'i': ctx->state = State_388; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_388: {
        switch (c) {
        case 'n': ctx->state = State_389; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_389: {
        switch (c) {
        case 'g': ctx->state = State_390; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_390: {
        switch (c) {
        case '_': ctx->state = State_391; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_391: {
        switch (c) {
        case 'f': ctx->state = State_396; break;
        case 'l': ctx->state = State_392; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_392: {
        switch (c) {
        case 'o': ctx->state = State_393; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_393: {
        switch (c) {
        case 'x': ctx->state = State_394; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_394: {
        switch (c) {
        case ' ': ctx->state = State_395; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_395: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->config_pressurize_bv_opening_lox(ctx->handler_ctx, strtof(ctx->arg_buffer, nullptr));
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_396: {
        switch (c) {
        case 'u': ctx->state = State_397; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_397: {
        switch (c) {
        case 'e': ctx->state = State_398; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_398: {
        switch (c) {
        case 'l': ctx->state = State_399; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_399: {
        switch (c) {
        case ' ': ctx->state = State_400; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_400: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->config_pressurize_bv_opening_fuel(ctx->handler_ctx, strtof(ctx->arg_buffer, nullptr));
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_401: {
        switch (c) {
        case 't': ctx->state = State_402; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_402: {
        switch (c) {
        case 'a': ctx->state = State_403; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_403: {
        switch (c) {
        case 'b': ctx->state = State_404; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_404: {
        switch (c) {
        case 'l': ctx->state = State_405; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_405: {
        switch (c) {
        case 'e': ctx->state = State_406; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_406: {
        switch (c) {
        case '_': ctx->state = State_407; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_407: {
        switch (c) {
        case 'o': ctx->state = State_408; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_408: {
        switch (c) {
        case 'p': ctx->state = State_409; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_409: {
        switch (c) {
        case 'e': ctx->state = State_410; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_410: {
        switch (c) {
        case 'n': ctx->state = State_411; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_411: {
        switch (c) {
        case 'i': ctx->state = State_412; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_412: {
        switch (c) {
        case 'n': ctx->state = State_413; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_413: {
        switch (c) {
        case 'g': ctx->state = State_414; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_414: {
        switch (c) {
        case '_': ctx->state = State_415; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_415: {
        switch (c) {
        case 'f': ctx->state = State_420; break;
        case 'l': ctx->state = State_416; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_416: {
        switch (c) {
        case 'o': ctx->state = State_417; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_417: {
        switch (c) {
        case 'x': ctx->state = State_418; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_418: {
        switch (c) {
        case ' ': ctx->state = State_419; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_419: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->config_pressurize_stable_opening_lox(ctx->handler_ctx, strtof(ctx->arg_buffer, nullptr));
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_420: {
        switch (c) {
        case 'u': ctx->state = State_421; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_421: {
        switch (c) {
        case 'e': ctx->state = State_422; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_422: {
        switch (c) {
        case 'l': ctx->state = State_423; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_423: {
        switch (c) {
        case ' ': ctx->state = State_424; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_424: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->config_pressurize_stable_opening_fuel(ctx->handler_ctx, strtof(ctx->arg_buffer, nullptr));
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_425: {
        switch (c) {
        case 'r': ctx->state = State_426; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_426: {
        switch (c) {
        case 'e': ctx->state = State_427; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_427: {
        switch (c) {
        case 'b': ctx->state = State_428; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_428: {
        switch (c) {
        case 'u': ctx->state = State_429; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_429: {
        switch (c) {
        case 'r': ctx->state = State_430; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_430: {
        switch (c) {
        case 'n': ctx->state = State_431; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_431: {
        switch (c) {
        case '_': ctx->state = State_432; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_432: {
        switch (c) {
        case 'd': ctx->state = State_433; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_433: {
        switch (c) {
        case 'u': ctx->state = State_434; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_434: {
        switch (c) {
        case 'r': ctx->state = State_435; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_435: {
        switch (c) {
        case 'a': ctx->state = State_436; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_436: {
        switch (c) {
        case 't': ctx->state = State_437; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_437: {
        switch (c) {
        case 'i': ctx->state = State_438; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_438: {
        switch (c) {
        case 'o': ctx->state = State_439; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_439: {
        switch (c) {
        case 'n': ctx->state = State_440; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_440: {
        switch (c) {
        case '_': ctx->state = State_441; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_441: {
        switch (c) {
        case 'f': ctx->state = State_446; break;
        case 'l': ctx->state = State_442; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_442: {
        switch (c) {
        case 'o': ctx->state = State_443; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_443: {
        switch (c) {
        case 'x': ctx->state = State_444; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_444: {
        switch (c) {
        case ' ': ctx->state = State_445; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_445: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->config_pressurize_preburn_duration_lox(ctx->handler_ctx, strtof(ctx->arg_buffer, nullptr));
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_446: {
        switch (c) {
        case 'u': ctx->state = State_447; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_447: {
        switch (c) {
        case 'e': ctx->state = State_448; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_448: {
        switch (c) {
        case 'l': ctx->state = State_449; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_449: {
        switch (c) {
        case ' ': ctx->state = State_450; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_450: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->config_pressurize_preburn_duration_fuel(ctx->handler_ctx, strtof(ctx->arg_buffer, nullptr));
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_451: {
        switch (c) {
        case 'a': ctx->state = State_452; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_452: {
        switch (c) {
        case 'r': ctx->state = State_453; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_453: {
        switch (c) {
        case 'g': ctx->state = State_454; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_454: {
        switch (c) {
        case 'e': ctx->state = State_455; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_455: {
        switch (c) {
        case 't': ctx->state = State_456; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_456: {
        switch (c) {
        case '_': ctx->state = State_457; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_457: {
        switch (c) {
        case 'p': ctx->state = State_458; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_458: {
        switch (c) {
        case 'r': ctx->state = State_459; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_459: {
        switch (c) {
        case 'e': ctx->state = State_460; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_460: {
        switch (c) {
        case 's': ctx->state = State_461; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_461: {
        switch (c) {
        case 's': ctx->state = State_462; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_462: {
        switch (c) {
        case 'u': ctx->state = State_463; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_463: {
        switch (c) {
        case 'r': ctx->state = State_464; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_464: {
        switch (c) {
        case 'e': ctx->state = State_465; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_465: {
        switch (c) {
        case '_': ctx->state = State_466; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_466: {
        switch (c) {
        case 'f': ctx->state = State_471; break;
        case 'l': ctx->state = State_467; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_467: {
        switch (c) {
        case 'o': ctx->state = State_468; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_468: {
        switch (c) {
        case 'x': ctx->state = State_469; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_469: {
        switch (c) {
        case ' ': ctx->state = State_470; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_470: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->config_pressurize_target_pressure_lox(ctx->handler_ctx, strtof(ctx->arg_buffer, nullptr));
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_471: {
        switch (c) {
        case 'u': ctx->state = State_472; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_472: {
        switch (c) {
        case 'e': ctx->state = State_473; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_473: {
        switch (c) {
        case 'l': ctx->state = State_474; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_474: {
        switch (c) {
        case ' ': ctx->state = State_475; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_475: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->config_pressurize_target_pressure_fuel(ctx->handler_ctx, strtof(ctx->arg_buffer, nullptr));
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_476: {
        switch (c) {
        case 'a': ctx->state = State_477; break;
        case 'i': ctx->state = State_501; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_477: {
        switch (c) {
        case 'x': ctx->state = State_478; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_478: {
        switch (c) {
        case '_': ctx->state = State_479; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_479: {
        switch (c) {
        case 'f': ctx->state = State_525; break;
        case 'l': ctx->state = State_480; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_480: {
        switch (c) {
        case 'o': ctx->state = State_481; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_481: {
        switch (c) {
        case 'x': ctx->state = State_482; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_482: {
        switch (c) {
        case '_': ctx->state = State_483; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_483: {
        switch (c) {
        case 'n': ctx->state = State_484; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_484: {
        switch (c) {
        case 'o': ctx->state = State_485; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_485: {
        switch (c) {
        case 'm': ctx->state = State_486; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_486: {
        switch (c) {
        case 'i': ctx->state = State_487; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_487: {
        switch (c) {
        case 'n': ctx->state = State_488; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_488: {
        switch (c) {
        case 'a': ctx->state = State_489; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_489: {
        switch (c) {
        case 'l': ctx->state = State_490; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_490: {
        switch (c) {
        case '_': ctx->state = State_491; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_491: {
        switch (c) {
        case 'p': ctx->state = State_492; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_492: {
        switch (c) {
        case 'r': ctx->state = State_493; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_493: {
        switch (c) {
        case 'e': ctx->state = State_494; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_494: {
        switch (c) {
        case 's': ctx->state = State_495; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_495: {
        switch (c) {
        case 's': ctx->state = State_496; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_496: {
        switch (c) {
        case 'u': ctx->state = State_497; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_497: {
        switch (c) {
        case 'r': ctx->state = State_498; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_498: {
        switch (c) {
        case 'e': ctx->state = State_499; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_499: {
        switch (c) {
        case ' ': ctx->state = State_500; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_500: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->config_pressurize_max_lox_nominal_pressure(ctx->handler_ctx, strtof(ctx->arg_buffer, nullptr));
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_501: {
        switch (c) {
        case 'n': ctx->state = State_502; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_502: {
        switch (c) {
        case '_': ctx->state = State_503; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_503: {
        switch (c) {
        case 'f': ctx->state = State_547; break;
        case 'l': ctx->state = State_504; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_504: {
        switch (c) {
        case 'o': ctx->state = State_505; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_505: {
        switch (c) {
        case 'x': ctx->state = State_506; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_506: {
        switch (c) {
        case '_': ctx->state = State_507; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_507: {
        switch (c) {
        case 'n': ctx->state = State_508; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_508: {
        switch (c) {
        case 'o': ctx->state = State_509; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_509: {
        switch (c) {
        case 'm': ctx->state = State_510; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_510: {
        switch (c) {
        case 'i': ctx->state = State_511; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_511: {
        switch (c) {
        case 'n': ctx->state = State_512; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_512: {
        switch (c) {
        case 'a': ctx->state = State_513; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_513: {
        switch (c) {
        case 'l': ctx->state = State_514; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_514: {
        switch (c) {
        case '_': ctx->state = State_515; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_515: {
        switch (c) {
        case 'p': ctx->state = State_516; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_516: {
        switch (c) {
        case 'r': ctx->state = State_517; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_517: {
        switch (c) {
        case 'e': ctx->state = State_518; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_518: {
        switch (c) {
        case 's': ctx->state = State_519; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_519: {
        switch (c) {
        case 's': ctx->state = State_520; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_520: {
        switch (c) {
        case 'u': ctx->state = State_521; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_521: {
        switch (c) {
        case 'r': ctx->state = State_522; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_522: {
        switch (c) {
        case 'e': ctx->state = State_523; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_523: {
        switch (c) {
        case ' ': ctx->state = State_524; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_524: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->config_pressurize_min_lox_nominal_pressure(ctx->handler_ctx, strtof(ctx->arg_buffer, nullptr));
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_525: {
        switch (c) {
        case 'u': ctx->state = State_526; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_526: {
        switch (c) {
        case 'e': ctx->state = State_527; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_527: {
        switch (c) {
        case 'l': ctx->state = State_528; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_528: {
        switch (c) {
        case '_': ctx->state = State_529; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_529: {
        switch (c) {
        case 'n': ctx->state = State_530; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_530: {
        switch (c) {
        case 'o': ctx->state = State_531; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_531: {
        switch (c) {
        case 'm': ctx->state = State_532; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_532: {
        switch (c) {
        case 'i': ctx->state = State_533; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_533: {
        switch (c) {
        case 'n': ctx->state = State_534; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_534: {
        switch (c) {
        case 'a': ctx->state = State_535; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_535: {
        switch (c) {
        case 'l': ctx->state = State_536; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_536: {
        switch (c) {
        case '_': ctx->state = State_537; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_537: {
        switch (c) {
        case 'p': ctx->state = State_538; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_538: {
        switch (c) {
        case 'r': ctx->state = State_539; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_539: {
        switch (c) {
        case 'e': ctx->state = State_540; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_540: {
        switch (c) {
        case 's': ctx->state = State_541; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_541: {
        switch (c) {
        case 's': ctx->state = State_542; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_542: {
        switch (c) {
        case 'u': ctx->state = State_543; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_543: {
        switch (c) {
        case 'r': ctx->state = State_544; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_544: {
        switch (c) {
        case 'e': ctx->state = State_545; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_545: {
        switch (c) {
        case ' ': ctx->state = State_546; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_546: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->config_pressurize_max_fuel_nominal_pressure(ctx->handler_ctx, strtof(ctx->arg_buffer, nullptr));
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_547: {
        switch (c) {
        case 'u': ctx->state = State_548; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_548: {
        switch (c) {
        case 'e': ctx->state = State_549; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_549: {
        switch (c) {
        case 'l': ctx->state = State_550; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_550: {
        switch (c) {
        case '_': ctx->state = State_551; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_551: {
        switch (c) {
        case 'n': ctx->state = State_552; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_552: {
        switch (c) {
        case 'o': ctx->state = State_553; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_553: {
        switch (c) {
        case 'm': ctx->state = State_554; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_554: {
        switch (c) {
        case 'i': ctx->state = State_555; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_555: {
        switch (c) {
        case 'n': ctx->state = State_556; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_556: {
        switch (c) {
        case 'a': ctx->state = State_557; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_557: {
        switch (c) {
        case 'l': ctx->state = State_558; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_558: {
        switch (c) {
        case '_': ctx->state = State_559; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_559: {
        switch (c) {
        case 'p': ctx->state = State_560; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_560: {
        switch (c) {
        case 'r': ctx->state = State_561; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_561: {
        switch (c) {
        case 'e': ctx->state = State_562; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_562: {
        switch (c) {
        case 's': ctx->state = State_563; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_563: {
        switch (c) {
        case 's': ctx->state = State_564; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_564: {
        switch (c) {
        case 'u': ctx->state = State_565; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_565: {
        switch (c) {
        case 'r': ctx->state = State_566; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_566: {
        switch (c) {
        case 'e': ctx->state = State_567; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_567: {
        switch (c) {
        case ' ': ctx->state = State_568; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_568: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->config_pressurize_min_fuel_nominal_pressure(ctx->handler_ctx, strtof(ctx->arg_buffer, nullptr));
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_569: {
        switch (c) {
        case 'g': ctx->state = State_570; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_570: {
        switch (c) {
        case 'n': ctx->state = State_571; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_571: {
        switch (c) {
        case 'i': ctx->state = State_572; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_572: {
        switch (c) {
        case 't': ctx->state = State_573; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_573: {
        switch (c) {
        case 'i': ctx->state = State_574; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_574: {
        switch (c) {
        case 'o': ctx->state = State_575; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_575: {
        switch (c) {
        case 'n': ctx->state = State_576; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_576: {
        switch (c) {
        case ' ': ctx->state = State_577; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_577: {
        switch (c) {
        case 'd': ctx->state = State_613; break;
        case 'i': ctx->state = State_596; break;
        case 'p': ctx->state = State_578; break;
        case 'r': ctx->state = State_619; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_578: {
        switch (c) {
        case 'r': ctx->state = State_579; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_579: {
        switch (c) {
        case 'e': ctx->state = State_580; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_580: {
        switch (c) {
        case 'c': ctx->state = State_581; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_581: {
        switch (c) {
        case 'h': ctx->state = State_582; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_582: {
        switch (c) {
        case 'i': ctx->state = State_583; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_583: {
        switch (c) {
        case 'l': ctx->state = State_584; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_584: {
        switch (c) {
        case 'l': ctx->state = State_585; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_585: {
        switch (c) {
        case '_': ctx->state = State_586; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_586: {
        switch (c) {
        case 'd': ctx->state = State_587; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_587: {
        switch (c) {
        case 'u': ctx->state = State_588; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_588: {
        switch (c) {
        case 'r': ctx->state = State_589; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_589: {
        switch (c) {
        case 'a': ctx->state = State_590; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_590: {
        switch (c) {
        case 't': ctx->state = State_591; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_591: {
        switch (c) {
        case 'i': ctx->state = State_592; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_592: {
        switch (c) {
        case 'o': ctx->state = State_593; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_593: {
        switch (c) {
        case 'n': ctx->state = State_594; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_594: {
        switch (c) {
        case ' ': ctx->state = State_595; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_595: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->config_ignition_prechill_duration(ctx->handler_ctx, strtol(ctx->arg_buffer, nullptr, 10));
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_596: {
        switch (c) {
        case 'g': ctx->state = State_597; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_597: {
        switch (c) {
        case 'n': ctx->state = State_598; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_598: {
        switch (c) {
        case 'i': ctx->state = State_599; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_599: {
        switch (c) {
        case 't': ctx->state = State_600; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_600: {
        switch (c) {
        case 'e': ctx->state = State_601; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_601: {
        switch (c) {
        case 'r': ctx->state = State_602; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_602: {
        switch (c) {
        case '_': ctx->state = State_603; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_603: {
        switch (c) {
        case 'd': ctx->state = State_604; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_604: {
        switch (c) {
        case 'u': ctx->state = State_605; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_605: {
        switch (c) {
        case 'r': ctx->state = State_606; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_606: {
        switch (c) {
        case 'a': ctx->state = State_607; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_607: {
        switch (c) {
        case 't': ctx->state = State_608; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_608: {
        switch (c) {
        case 'i': ctx->state = State_609; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_609: {
        switch (c) {
        case 'o': ctx->state = State_610; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_610: {
        switch (c) {
        case 'n': ctx->state = State_611; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_611: {
        switch (c) {
        case ' ': ctx->state = State_612; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_612: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->config_ignition_igniter_duration(ctx->handler_ctx, strtol(ctx->arg_buffer, nullptr, 10));
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_613: {
        switch (c) {
        case 'e': ctx->state = State_614; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_614: {
        switch (c) {
        case 'l': ctx->state = State_615; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_615: {
        switch (c) {
        case 'a': ctx->state = State_616; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_616: {
        switch (c) {
        case 'y': ctx->state = State_617; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_617: {
        switch (c) {
        case ' ': ctx->state = State_618; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_618: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->config_ignition_delay(ctx->handler_ctx, strtol(ctx->arg_buffer, nullptr, 10));
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_619: {
        switch (c) {
        case 'a': ctx->state = State_620; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_620: {
        switch (c) {
        case 'm': ctx->state = State_621; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_621: {
        switch (c) {
        case 'p': ctx->state = State_622; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_622: {
        switch (c) {
        case '_': ctx->state = State_623; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_623: {
        switch (c) {
        case 'u': ctx->state = State_624; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_624: {
        switch (c) {
        case 'p': ctx->state = State_625; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_625: {
        switch (c) {
        case ' ': ctx->state = State_626; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_626: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->config_ignition_ramp_up(ctx->handler_ctx, strtol(ctx->arg_buffer, nullptr, 10));
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_627: {
        switch (c) {
        case 'u': ctx->state = State_628; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_628: {
        switch (c) {
        case 'r': ctx->state = State_629; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_629: {
        switch (c) {
        case 'n': ctx->state = State_630; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_630: {
        switch (c) {
        case ' ': ctx->state = State_631; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_631: {
        switch (c) {
        case 'c': ctx->state = State_632; break;
        case 'i': ctx->state = State_658; break;
        case 'm': ctx->state = State_645; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_632: {
        switch (c) {
        case 'u': ctx->state = State_633; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_633: {
        switch (c) {
        case 't': ctx->state = State_634; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_634: {
        switch (c) {
        case 'o': ctx->state = State_635; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_635: {
        switch (c) {
        case 'f': ctx->state = State_636; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_636: {
        switch (c) {
        case 'f': ctx->state = State_637; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_637: {
        switch (c) {
        case '_': ctx->state = State_638; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_638: {
        switch (c) {
        case 'd': ctx->state = State_639; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_639: {
        switch (c) {
        case 'e': ctx->state = State_640; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_640: {
        switch (c) {
        case 'l': ctx->state = State_641; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_641: {
        switch (c) {
        case 'a': ctx->state = State_642; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_642: {
        switch (c) {
        case 'y': ctx->state = State_643; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_643: {
        switch (c) {
        case ' ': ctx->state = State_644; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_644: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->config_burn_cutoff_delay(ctx->handler_ctx, strtol(ctx->arg_buffer, nullptr, 10));
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_645: {
        switch (c) {
        case 'a': ctx->state = State_666; break;
        case 'i': ctx->state = State_646; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_646: {
        switch (c) {
        case 'n': ctx->state = State_647; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_647: {
        switch (c) {
        case '_': ctx->state = State_648; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_648: {
        switch (c) {
        case 'd': ctx->state = State_649; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_649: {
        switch (c) {
        case 'u': ctx->state = State_650; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_650: {
        switch (c) {
        case 'r': ctx->state = State_651; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_651: {
        switch (c) {
        case 'a': ctx->state = State_652; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_652: {
        switch (c) {
        case 't': ctx->state = State_653; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_653: {
        switch (c) {
        case 'i': ctx->state = State_654; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_654: {
        switch (c) {
        case 'o': ctx->state = State_655; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_655: {
        switch (c) {
        case 'n': ctx->state = State_656; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_656: {
        switch (c) {
        case ' ': ctx->state = State_657; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_657: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->config_burn_min_duration(ctx->handler_ctx, strtol(ctx->arg_buffer, nullptr, 10));
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_658: {
        switch (c) {
        case 'm': ctx->state = State_659; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_659: {
        switch (c) {
        case 'p': ctx->state = State_660; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_660: {
        switch (c) {
        case 'u': ctx->state = State_661; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_661: {
        switch (c) {
        case 'l': ctx->state = State_662; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_662: {
        switch (c) {
        case 's': ctx->state = State_663; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_663: {
        switch (c) {
        case 'e': ctx->state = State_664; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_664: {
        switch (c) {
        case ' ': ctx->state = State_665; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_665: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->config_burn_impulse(ctx->handler_ctx, strtof(ctx->arg_buffer, nullptr));
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_666: {
        switch (c) {
        case 'x': ctx->state = State_667; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_667: {
        switch (c) {
        case '_': ctx->state = State_668; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_668: {
        switch (c) {
        case 'd': ctx->state = State_669; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_669: {
        switch (c) {
        case 'u': ctx->state = State_670; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_670: {
        switch (c) {
        case 'r': ctx->state = State_671; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_671: {
        switch (c) {
        case 'a': ctx->state = State_672; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_672: {
        switch (c) {
        case 't': ctx->state = State_673; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_673: {
        switch (c) {
        case 'i': ctx->state = State_674; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_674: {
        switch (c) {
        case 'o': ctx->state = State_675; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_675: {
        switch (c) {
        case 'n': ctx->state = State_676; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_676: {
        switch (c) {
        case ' ': ctx->state = State_677; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_677: {
        switch (c) {
        case 'e': ctx->state = State_681; break;
        case 'f': ctx->state = State_678; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_678: {
        switch (c) {
        case 'c': ctx->state = State_679; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_679: {
        switch (c) {
        case ' ': ctx->state = State_680; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_680: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->config_burn_max_duration_fc(ctx->handler_ctx, strtol(ctx->arg_buffer, nullptr, 10));
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_681: {
        switch (c) {
        case 'n': ctx->state = State_682; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_682: {
        switch (c) {
        case 'g': ctx->state = State_683; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_683: {
        switch (c) {
        case 'i': ctx->state = State_684; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_684: {
        switch (c) {
        case 'n': ctx->state = State_685; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_685: {
        switch (c) {
        case 'e': ctx->state = State_686; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_686: {
        switch (c) {
        case ' ': ctx->state = State_687; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_687: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->config_burn_max_duration_engine(ctx->handler_ctx, strtol(ctx->arg_buffer, nullptr, 10));
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_688: {
        switch (c) {
        case 'o': ctx->state = State_689; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_689: {
        switch (c) {
        case 'l': ctx->state = State_690; break;
        case 'm': ctx->state = State_721; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_690: {
        switch (c) {
        case 'd': ctx->state = State_691; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_691: {
        switch (c) {
        case 'f': ctx->state = State_692; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_692: {
        switch (c) {
        case 'l': ctx->state = State_693; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_693: {
        switch (c) {
        case 'o': ctx->state = State_694; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_694: {
        switch (c) {
        case 'w': ctx->state = State_695; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_695: {
        switch (c) {
        case ' ': ctx->state = State_696; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_696: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            if (strcmp(ctx->arg_buffer, "open") == 0 || strcmp(ctx->arg_buffer, "on") == 0) {
                drv->config_set_coldflow_mode(ctx->handler_ctx, true);
            } else if (strcmp(ctx->arg_buffer, "close") == 0 || strcmp(ctx->arg_buffer, "off") == 0) {
                drv->config_set_coldflow_mode(ctx->handler_ctx, false);
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
    case State_697: {
        switch (c) {
        case 'n': ctx->state = State_698; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_698: {
        switch (c) {
        case 't': ctx->state = State_699; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_699: {
        switch (c) {
        case ' ': ctx->state = State_700; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_700: {
        switch (c) {
        case 'b': ctx->state = State_701; break;
        case 'c': ctx->state = State_707; break;
        case 's': ctx->state = State_715; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_701: {
        switch (c) {
        case 'u': ctx->state = State_702; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_702: {
        switch (c) {
        case 'f': ctx->state = State_703; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_703: {
        switch (c) {
        case 'f': ctx->state = State_704; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_704: {
        switch (c) {
        case 'e': ctx->state = State_705; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_705: {
        switch (c) {
        case 'r': ctx->state = State_706; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_706: {
        if (c == '\n') {
            drv->config_print_buffer(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_707: {
        switch (c) {
        case 'o': ctx->state = State_708; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_708: {
        switch (c) {
        case 'm': ctx->state = State_709; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_709: {
        switch (c) {
        case 'm': ctx->state = State_710; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_710: {
        switch (c) {
        case 'i': ctx->state = State_711; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_711: {
        switch (c) {
        case 't': ctx->state = State_712; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_712: {
        switch (c) {
        case 'e': ctx->state = State_713; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_713: {
        switch (c) {
        case 'd': ctx->state = State_714; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_714: {
        if (c == '\n') {
            drv->config_print_commited(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_715: {
        switch (c) {
        case 't': ctx->state = State_716; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_716: {
        switch (c) {
        case 'a': ctx->state = State_717; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_717: {
        switch (c) {
        case 't': ctx->state = State_718; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_718: {
        switch (c) {
        case 'u': ctx->state = State_719; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_719: {
        switch (c) {
        case 's': ctx->state = State_720; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_720: {
        if (c == '\n') {
            drv->config_print_status(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_Sink;
        }
        break;
    }
    case State_721: {
        switch (c) {
        case 'm': ctx->state = State_722; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_722: {
        switch (c) {
        case 'i': ctx->state = State_723; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_723: {
        switch (c) {
        case 't': ctx->state = State_724; break;
        case '\n': ctx->state = State_0; break;
        default: ctx->state = State_Sink; break;
        }
        break;
    }
    case State_724: {
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
