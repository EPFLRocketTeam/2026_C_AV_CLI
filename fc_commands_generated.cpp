// GENERATED FILE -- do not edit by hand. Regenerate with generate_commands.py.
#include "fc_commands_generated.hpp"

#include <cstdlib>

void push_char(context* ctx, const driver* drv, char c) {
    switch (ctx->state) {
    case State_0: {
        switch (c) {
        case 'd': ctx->state = State_103; break;
        case 'm': ctx->state = State_12; break;
        case 'p': ctx->state = State_1; break;
        case 'v': ctx->state = State_26; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_1: {
        switch (c) {
        case 'r': ctx->state = State_2; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_2: {
        switch (c) {
        case 'c': ctx->state = State_56; break;
        case 'e': ctx->state = State_3; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_3: {
        switch (c) {
        case 's': ctx->state = State_4; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_4: {
        switch (c) {
        case 's': ctx->state = State_5; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_5: {
        switch (c) {
        case 'u': ctx->state = State_6; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_6: {
        switch (c) {
        case 'r': ctx->state = State_7; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_7: {
        switch (c) {
        case 'e': ctx->state = State_45; break;
        case 'i': ctx->state = State_8; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_8: {
        switch (c) {
        case 'z': ctx->state = State_9; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_9: {
        switch (c) {
        case 'e': ctx->state = State_10; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_10: {
        switch (c) {
        case ' ': ctx->state = State_11; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_11: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->pressurize(ctx->handler_ctx, strcmp(ctx->arg_buffer, "open") == 0);
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
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_13: {
        switch (c) {
        case 'i': ctx->state = State_14; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_14: {
        switch (c) {
        case 'n': ctx->state = State_15; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_15: {
        switch (c) {
        case ' ': ctx->state = State_16; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_16: {
        switch (c) {
        case 'f': ctx->state = State_21; break;
        case 'l': ctx->state = State_17; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_17: {
        switch (c) {
        case 'o': ctx->state = State_18; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_18: {
        switch (c) {
        case 'x': ctx->state = State_19; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_19: {
        switch (c) {
        case ' ': ctx->state = State_20; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_20: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->main_lox(ctx->handler_ctx, strcmp(ctx->arg_buffer, "open") == 0);
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
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_22: {
        switch (c) {
        case 'e': ctx->state = State_23; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_23: {
        switch (c) {
        case 'l': ctx->state = State_24; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_24: {
        switch (c) {
        case ' ': ctx->state = State_25; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_25: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->main_fuel(ctx->handler_ctx, strcmp(ctx->arg_buffer, "open") == 0);
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
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_27: {
        switch (c) {
        case 'n': ctx->state = State_28; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_28: {
        switch (c) {
        case 't': ctx->state = State_29; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_29: {
        switch (c) {
        case ' ': ctx->state = State_30; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_30: {
        switch (c) {
        case 'c': ctx->state = State_31; break;
        case 'f': ctx->state = State_40; break;
        case 'l': ctx->state = State_36; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_31: {
        switch (c) {
        case 'o': ctx->state = State_32; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_32: {
        switch (c) {
        case 'p': ctx->state = State_33; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_33: {
        switch (c) {
        case 'v': ctx->state = State_34; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_34: {
        switch (c) {
        case ' ': ctx->state = State_35; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_35: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->vent_copv(ctx->handler_ctx, strcmp(ctx->arg_buffer, "open") == 0);
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
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_37: {
        switch (c) {
        case 'x': ctx->state = State_38; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_38: {
        switch (c) {
        case ' ': ctx->state = State_39; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_39: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->vent_lox(ctx->handler_ctx, strcmp(ctx->arg_buffer, "open") == 0);
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
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_41: {
        switch (c) {
        case 'e': ctx->state = State_42; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_42: {
        switch (c) {
        case 'l': ctx->state = State_43; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_43: {
        switch (c) {
        case ' ': ctx->state = State_44; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_44: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->vent_fuel(ctx->handler_ctx, strcmp(ctx->arg_buffer, "open") == 0);
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_45: {
        switch (c) {
        case ' ': ctx->state = State_46; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_46: {
        switch (c) {
        case 'f': ctx->state = State_51; break;
        case 'l': ctx->state = State_47; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_47: {
        switch (c) {
        case 'o': ctx->state = State_48; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_48: {
        switch (c) {
        case 'x': ctx->state = State_49; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_49: {
        switch (c) {
        case ' ': ctx->state = State_50; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_50: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->pressure_lox(ctx->handler_ctx, strcmp(ctx->arg_buffer, "open") == 0);
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_51: {
        switch (c) {
        case 'u': ctx->state = State_52; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_52: {
        switch (c) {
        case 'e': ctx->state = State_53; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_53: {
        switch (c) {
        case 'l': ctx->state = State_54; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_54: {
        switch (c) {
        case ' ': ctx->state = State_55; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_55: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->pressure_fuel(ctx->handler_ctx, strcmp(ctx->arg_buffer, "open") == 0);
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_56: {
        switch (c) {
        case ' ': ctx->state = State_57; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_57: {
        switch (c) {
        case 'a': ctx->state = State_97; break;
        case 'c': ctx->state = State_58; break;
        case 'i': ctx->state = State_74; break;
        case 'p': ctx->state = State_81; break;
        case 'r': ctx->state = State_91; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_58: {
        switch (c) {
        case 'l': ctx->state = State_59; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_59: {
        switch (c) {
        case 'e': ctx->state = State_60; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_60: {
        switch (c) {
        case 'a': ctx->state = State_61; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_61: {
        switch (c) {
        case 'r': ctx->state = State_62; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_62: {
        switch (c) {
        case '_': ctx->state = State_63; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_63: {
        switch (c) {
        case 't': ctx->state = State_64; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_64: {
        switch (c) {
        case 'o': ctx->state = State_65; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_65: {
        switch (c) {
        case '_': ctx->state = State_66; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_66: {
        switch (c) {
        case 'i': ctx->state = State_67; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_67: {
        switch (c) {
        case 'g': ctx->state = State_68; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_68: {
        switch (c) {
        case 'n': ctx->state = State_69; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_69: {
        switch (c) {
        case 'i': ctx->state = State_70; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_70: {
        switch (c) {
        case 't': ctx->state = State_71; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_71: {
        switch (c) {
        case 'e': ctx->state = State_72; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_72: {
        switch (c) {
        case ' ': ctx->state = State_73; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_73: {
        if (c == '\n') {
            drv->prc_clear_to_ignite(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_0;
        }
        break;
    }
    case State_74: {
        switch (c) {
        case 'g': ctx->state = State_75; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_75: {
        switch (c) {
        case 'n': ctx->state = State_76; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_76: {
        switch (c) {
        case 'i': ctx->state = State_77; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_77: {
        switch (c) {
        case 't': ctx->state = State_78; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_78: {
        switch (c) {
        case 'e': ctx->state = State_79; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_79: {
        switch (c) {
        case ' ': ctx->state = State_80; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_80: {
        if (c == '\n') {
            drv->prc_ignite(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_0;
        }
        break;
    }
    case State_81: {
        switch (c) {
        case 'a': ctx->state = State_82; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_82: {
        switch (c) {
        case 's': ctx->state = State_83; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_83: {
        switch (c) {
        case 's': ctx->state = State_84; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_84: {
        switch (c) {
        case 'i': ctx->state = State_85; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_85: {
        switch (c) {
        case 'v': ctx->state = State_86; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_86: {
        switch (c) {
        case 'a': ctx->state = State_87; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_87: {
        switch (c) {
        case 't': ctx->state = State_88; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_88: {
        switch (c) {
        case 'e': ctx->state = State_89; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_89: {
        switch (c) {
        case ' ': ctx->state = State_90; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_90: {
        if (c == '\n') {
            drv->prc_passivate(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_0;
        }
        break;
    }
    case State_91: {
        switch (c) {
        case 'e': ctx->state = State_92; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_92: {
        switch (c) {
        case 's': ctx->state = State_93; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_93: {
        switch (c) {
        case 'e': ctx->state = State_94; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_94: {
        switch (c) {
        case 't': ctx->state = State_95; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_95: {
        switch (c) {
        case ' ': ctx->state = State_96; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_96: {
        if (c == '\n') {
            drv->prc_reset(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_0;
        }
        break;
    }
    case State_97: {
        switch (c) {
        case 'b': ctx->state = State_98; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_98: {
        switch (c) {
        case 'o': ctx->state = State_99; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_99: {
        switch (c) {
        case 'r': ctx->state = State_100; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_100: {
        switch (c) {
        case 't': ctx->state = State_101; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_101: {
        switch (c) {
        case ' ': ctx->state = State_102; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_102: {
        if (c == '\n') {
            drv->prc_abort(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_0;
        }
        break;
    }
    case State_103: {
        switch (c) {
        case 'p': ctx->state = State_104; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_104: {
        switch (c) {
        case 'r': ctx->state = State_105; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_105: {
        switch (c) {
        case ' ': ctx->state = State_106; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_106: {
        switch (c) {
        case 'b': ctx->state = State_179; break;
        case 'e': ctx->state = State_143; break;
        case 'l': ctx->state = State_107; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_107: {
        switch (c) {
        case 'o': ctx->state = State_108; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_108: {
        switch (c) {
        case 'x': ctx->state = State_109; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_109: {
        switch (c) {
        case ' ': ctx->state = State_110; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_110: {
        switch (c) {
        case 'a': ctx->state = State_122; break;
        case 'p': ctx->state = State_111; break;
        case 'r': ctx->state = State_137; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_111: {
        switch (c) {
        case 'a': ctx->state = State_128; break;
        case 'r': ctx->state = State_112; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_112: {
        switch (c) {
        case 'e': ctx->state = State_113; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_113: {
        switch (c) {
        case 's': ctx->state = State_114; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_114: {
        switch (c) {
        case 's': ctx->state = State_115; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_115: {
        switch (c) {
        case 'u': ctx->state = State_116; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_116: {
        switch (c) {
        case 'r': ctx->state = State_117; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_117: {
        switch (c) {
        case 'i': ctx->state = State_118; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_118: {
        switch (c) {
        case 'z': ctx->state = State_119; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_119: {
        switch (c) {
        case 'e': ctx->state = State_120; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_120: {
        switch (c) {
        case ' ': ctx->state = State_121; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_121: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->dpr_lox_pressurize(ctx->handler_ctx, strcmp(ctx->arg_buffer, "open") == 0);
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_122: {
        switch (c) {
        case 'b': ctx->state = State_123; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_123: {
        switch (c) {
        case 'o': ctx->state = State_124; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_124: {
        switch (c) {
        case 'r': ctx->state = State_125; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_125: {
        switch (c) {
        case 't': ctx->state = State_126; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_126: {
        switch (c) {
        case ' ': ctx->state = State_127; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_127: {
        if (c == '\n') {
            drv->dpr_lox_abort(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_0;
        }
        break;
    }
    case State_128: {
        switch (c) {
        case 's': ctx->state = State_129; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_129: {
        switch (c) {
        case 's': ctx->state = State_130; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_130: {
        switch (c) {
        case 'i': ctx->state = State_131; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_131: {
        switch (c) {
        case 'v': ctx->state = State_132; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_132: {
        switch (c) {
        case 'a': ctx->state = State_133; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_133: {
        switch (c) {
        case 't': ctx->state = State_134; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_134: {
        switch (c) {
        case 'e': ctx->state = State_135; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_135: {
        switch (c) {
        case ' ': ctx->state = State_136; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_136: {
        if (c == '\n') {
            drv->dpr_lox_passivate(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_0;
        }
        break;
    }
    case State_137: {
        switch (c) {
        case 'e': ctx->state = State_138; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_138: {
        switch (c) {
        case 's': ctx->state = State_139; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_139: {
        switch (c) {
        case 'e': ctx->state = State_140; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_140: {
        switch (c) {
        case 't': ctx->state = State_141; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_141: {
        switch (c) {
        case ' ': ctx->state = State_142; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_142: {
        if (c == '\n') {
            drv->dpr_lox_reset(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_0;
        }
        break;
    }
    case State_143: {
        switch (c) {
        case 't': ctx->state = State_144; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_144: {
        switch (c) {
        case 'h': ctx->state = State_145; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_145: {
        switch (c) {
        case ' ': ctx->state = State_146; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_146: {
        switch (c) {
        case 'a': ctx->state = State_158; break;
        case 'p': ctx->state = State_147; break;
        case 'r': ctx->state = State_173; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_147: {
        switch (c) {
        case 'a': ctx->state = State_164; break;
        case 'r': ctx->state = State_148; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_148: {
        switch (c) {
        case 'e': ctx->state = State_149; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_149: {
        switch (c) {
        case 's': ctx->state = State_150; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_150: {
        switch (c) {
        case 's': ctx->state = State_151; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_151: {
        switch (c) {
        case 'u': ctx->state = State_152; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_152: {
        switch (c) {
        case 'r': ctx->state = State_153; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_153: {
        switch (c) {
        case 'i': ctx->state = State_154; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_154: {
        switch (c) {
        case 'z': ctx->state = State_155; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_155: {
        switch (c) {
        case 'e': ctx->state = State_156; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_156: {
        switch (c) {
        case ' ': ctx->state = State_157; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_157: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->dpr_eth_pressurize(ctx->handler_ctx, strcmp(ctx->arg_buffer, "open") == 0);
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_158: {
        switch (c) {
        case 'b': ctx->state = State_159; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_159: {
        switch (c) {
        case 'o': ctx->state = State_160; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_160: {
        switch (c) {
        case 'r': ctx->state = State_161; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_161: {
        switch (c) {
        case 't': ctx->state = State_162; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_162: {
        switch (c) {
        case ' ': ctx->state = State_163; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_163: {
        if (c == '\n') {
            drv->dpr_eth_abort(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_0;
        }
        break;
    }
    case State_164: {
        switch (c) {
        case 's': ctx->state = State_165; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_165: {
        switch (c) {
        case 's': ctx->state = State_166; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_166: {
        switch (c) {
        case 'i': ctx->state = State_167; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_167: {
        switch (c) {
        case 'v': ctx->state = State_168; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_168: {
        switch (c) {
        case 'a': ctx->state = State_169; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_169: {
        switch (c) {
        case 't': ctx->state = State_170; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_170: {
        switch (c) {
        case 'e': ctx->state = State_171; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_171: {
        switch (c) {
        case ' ': ctx->state = State_172; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_172: {
        if (c == '\n') {
            drv->dpr_eth_passivate(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_0;
        }
        break;
    }
    case State_173: {
        switch (c) {
        case 'e': ctx->state = State_174; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_174: {
        switch (c) {
        case 's': ctx->state = State_175; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_175: {
        switch (c) {
        case 'e': ctx->state = State_176; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_176: {
        switch (c) {
        case 't': ctx->state = State_177; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_177: {
        switch (c) {
        case ' ': ctx->state = State_178; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_178: {
        if (c == '\n') {
            drv->dpr_eth_reset(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_0;
        }
        break;
    }
    case State_179: {
        switch (c) {
        case 'r': ctx->state = State_180; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_180: {
        switch (c) {
        case 'o': ctx->state = State_181; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_181: {
        switch (c) {
        case 'a': ctx->state = State_182; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_182: {
        switch (c) {
        case 'd': ctx->state = State_183; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_183: {
        switch (c) {
        case 'c': ctx->state = State_184; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_184: {
        switch (c) {
        case 'a': ctx->state = State_185; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_185: {
        switch (c) {
        case 's': ctx->state = State_186; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_186: {
        switch (c) {
        case 't': ctx->state = State_187; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_187: {
        switch (c) {
        case '_': ctx->state = State_188; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_188: {
        switch (c) {
        case 'a': ctx->state = State_189; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_189: {
        switch (c) {
        case 'b': ctx->state = State_190; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_190: {
        switch (c) {
        case 'o': ctx->state = State_191; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_191: {
        switch (c) {
        case 'r': ctx->state = State_192; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_192: {
        switch (c) {
        case 't': ctx->state = State_193; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_193: {
        switch (c) {
        case ' ': ctx->state = State_194; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_194: {
        if (c == '\n') {
            drv->dpr_broadcast_abort(ctx->handler_ctx);
            ctx->state = State_0;
        } else {
            ctx->state = State_0;
        }
        break;
    }
    }
}
