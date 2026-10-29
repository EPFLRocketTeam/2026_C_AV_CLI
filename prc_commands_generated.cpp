// GENERATED FILE -- do not edit by hand. Regenerate with generate_commands.py.
#include "prc_commands_generated.hpp"

#include <cstdlib>

namespace prc_cli {

// 1 for open or on, 0 for close or off, -1 for anything else.
static int parse_bool(const char* arg) {
    if (strcmp(arg, "open") == 0 || strcmp(arg, "on") == 0) return 1;
    if (strcmp(arg, "close") == 0 || strcmp(arg, "off") == 0) return 0;
    return -1;
}

void push_char(context* ctx, const driver* drv, char c) {
    // State enum order: literal states, void argument states, typed
    // argument states, State_Sink.
    const int state = ctx->state;

    if (state >= 140 && state != State_Sink) {
        // typed argument state: buffer until the newline, then parse and call
        if (c != '\n') {
            if (ctx->arg_len < 32) ctx->arg_buffer[ctx->arg_len++] = c;
            return;
        }
        ctx->arg_buffer[ctx->arg_len] = '\0';
        ctx->state = State_0;
        ctx->arg_len = 0;
        void (*fn_bool)(void*, bool) = nullptr;
        void (*fn_float)(void*, float) = nullptr;
        bool is_bool = false;
        switch (state) {
        case State_22: fn_bool = drv->valve_vent; is_bool = true; break;
        case State_29: fn_bool = drv->valve_safety; is_bool = true; break;
        case State_39: fn_bool = drv->valve_copv_vent; is_bool = true; break;
        case State_44: fn_float = drv->valve_ball; break;
        case State_47: fn_bool = drv->valve_mo; is_bool = true; break;
        case State_49: fn_bool = drv->valve_me; is_bool = true; break;
        case State_57: fn_bool = drv->igniter; is_bool = true; break;
        case State_72: fn_bool = drv->fsm_pressurize; is_bool = true; break;
        case State_120: fn_bool = drv->logs_usb; is_bool = true; break;
        case State_124: fn_bool = drv->logs_can; is_bool = true; break;
        }
        if (is_bool) {
            const int value = parse_bool(ctx->arg_buffer);
            if (value < 0) { if (drv->on_bad_argument != nullptr) drv->on_bad_argument(ctx->handler_ctx); }
            else if (fn_bool != nullptr) fn_bool(ctx->handler_ctx, value == 1);
        } else if (fn_float != nullptr) {
            fn_float(ctx->handler_ctx, strtof(ctx->arg_buffer, nullptr));
        }
        return;
    }

    if (c == '\n') {
        ctx->state = State_0;
        if (state >= 131 && state < 140) {
            // void argument state: the newline right after the path fires it
            void (*fn_void)(void*) = nullptr;
            switch (state) {
            case State_5: fn_void = drv->state_print; break;
            case State_11: fn_void = drv->sensors_print; break;
            case State_87: fn_void = drv->fsm_clear_to_ignite; break;
            case State_93: fn_void = drv->fsm_ignite; break;
            case State_98: fn_void = drv->fsm_abort; break;
            case State_106: fn_void = drv->fsm_passivate; break;
            case State_111: fn_void = drv->fsm_reset; break;
            case State_143: fn_void = drv->config_print_status; break;
            case State_149: fn_void = drv->config_commit; break;
            }
            if (fn_void != nullptr) fn_void(ctx->handler_ctx);
            return;
        }
        // a literal state or State_Sink: the line matched no command,
        // unless it was empty (still at the root)
        if (state != State_0 && drv->on_unknown_command != nullptr) drv->on_unknown_command(ctx->handler_ctx);
        return;
    }

    switch (state) {
    case State_0:
        switch (c) {
        case 'c': ctx->state = State_125; return;
        case 'f': ctx->state = State_58; return;
        case 'i': ctx->state = State_50; return;
        case 'l': ctx->state = State_112; return;
        case 's': ctx->state = State_1; return;
        case 'v': ctx->state = State_12; return;
        }
        break;
    case State_1:
        switch (c) {
        case 'e': ctx->state = State_6; return;
        case 't': ctx->state = State_2; return;
        }
        break;
    case State_2:
        switch (c) {
        case 'a': ctx->state = State_3; return;
        }
        break;
    case State_3:
        switch (c) {
        case 't': ctx->state = State_4; return;
        }
        break;
    case State_4:
        switch (c) {
        case 'e': ctx->state = State_5; return;
        }
        break;
    case State_6:
        switch (c) {
        case 'n': ctx->state = State_7; return;
        }
        break;
    case State_7:
        switch (c) {
        case 's': ctx->state = State_8; return;
        }
        break;
    case State_8:
        switch (c) {
        case 'o': ctx->state = State_9; return;
        }
        break;
    case State_9:
        switch (c) {
        case 'r': ctx->state = State_10; return;
        }
        break;
    case State_10:
        switch (c) {
        case 's': ctx->state = State_11; return;
        }
        break;
    case State_12:
        switch (c) {
        case 'a': ctx->state = State_13; return;
        }
        break;
    case State_13:
        switch (c) {
        case 'l': ctx->state = State_14; return;
        }
        break;
    case State_14:
        switch (c) {
        case 'v': ctx->state = State_15; return;
        }
        break;
    case State_15:
        switch (c) {
        case 'e': ctx->state = State_16; return;
        }
        break;
    case State_16:
        switch (c) {
        case ' ': ctx->state = State_17; return;
        }
        break;
    case State_17:
        switch (c) {
        case 'b': ctx->state = State_40; return;
        case 'c': ctx->state = State_30; return;
        case 'm': ctx->state = State_45; return;
        case 's': ctx->state = State_23; return;
        case 'v': ctx->state = State_18; return;
        }
        break;
    case State_18:
        switch (c) {
        case 'e': ctx->state = State_19; return;
        }
        break;
    case State_19:
        switch (c) {
        case 'n': ctx->state = State_20; return;
        }
        break;
    case State_20:
        switch (c) {
        case 't': ctx->state = State_21; return;
        }
        break;
    case State_21:
        switch (c) {
        case ' ': ctx->state = State_22; return;
        }
        break;
    case State_23:
        switch (c) {
        case 'a': ctx->state = State_24; return;
        }
        break;
    case State_24:
        switch (c) {
        case 'f': ctx->state = State_25; return;
        }
        break;
    case State_25:
        switch (c) {
        case 'e': ctx->state = State_26; return;
        }
        break;
    case State_26:
        switch (c) {
        case 't': ctx->state = State_27; return;
        }
        break;
    case State_27:
        switch (c) {
        case 'y': ctx->state = State_28; return;
        }
        break;
    case State_28:
        switch (c) {
        case ' ': ctx->state = State_29; return;
        }
        break;
    case State_30:
        switch (c) {
        case 'o': ctx->state = State_31; return;
        }
        break;
    case State_31:
        switch (c) {
        case 'p': ctx->state = State_32; return;
        }
        break;
    case State_32:
        switch (c) {
        case 'v': ctx->state = State_33; return;
        }
        break;
    case State_33:
        switch (c) {
        case '_': ctx->state = State_34; return;
        }
        break;
    case State_34:
        switch (c) {
        case 'v': ctx->state = State_35; return;
        }
        break;
    case State_35:
        switch (c) {
        case 'e': ctx->state = State_36; return;
        }
        break;
    case State_36:
        switch (c) {
        case 'n': ctx->state = State_37; return;
        }
        break;
    case State_37:
        switch (c) {
        case 't': ctx->state = State_38; return;
        }
        break;
    case State_38:
        switch (c) {
        case ' ': ctx->state = State_39; return;
        }
        break;
    case State_40:
        switch (c) {
        case 'a': ctx->state = State_41; return;
        }
        break;
    case State_41:
        switch (c) {
        case 'l': ctx->state = State_42; return;
        }
        break;
    case State_42:
        switch (c) {
        case 'l': ctx->state = State_43; return;
        }
        break;
    case State_43:
        switch (c) {
        case ' ': ctx->state = State_44; return;
        }
        break;
    case State_45:
        switch (c) {
        case 'e': ctx->state = State_48; return;
        case 'o': ctx->state = State_46; return;
        }
        break;
    case State_46:
        switch (c) {
        case ' ': ctx->state = State_47; return;
        }
        break;
    case State_48:
        switch (c) {
        case ' ': ctx->state = State_49; return;
        }
        break;
    case State_50:
        switch (c) {
        case 'g': ctx->state = State_51; return;
        }
        break;
    case State_51:
        switch (c) {
        case 'n': ctx->state = State_52; return;
        }
        break;
    case State_52:
        switch (c) {
        case 'i': ctx->state = State_53; return;
        }
        break;
    case State_53:
        switch (c) {
        case 't': ctx->state = State_54; return;
        }
        break;
    case State_54:
        switch (c) {
        case 'e': ctx->state = State_55; return;
        }
        break;
    case State_55:
        switch (c) {
        case 'r': ctx->state = State_56; return;
        }
        break;
    case State_56:
        switch (c) {
        case ' ': ctx->state = State_57; return;
        }
        break;
    case State_58:
        switch (c) {
        case 's': ctx->state = State_59; return;
        }
        break;
    case State_59:
        switch (c) {
        case 'm': ctx->state = State_60; return;
        }
        break;
    case State_60:
        switch (c) {
        case ' ': ctx->state = State_61; return;
        }
        break;
    case State_61:
        switch (c) {
        case 'a': ctx->state = State_94; return;
        case 'c': ctx->state = State_73; return;
        case 'i': ctx->state = State_88; return;
        case 'p': ctx->state = State_62; return;
        case 'r': ctx->state = State_107; return;
        }
        break;
    case State_62:
        switch (c) {
        case 'a': ctx->state = State_99; return;
        case 'r': ctx->state = State_63; return;
        }
        break;
    case State_63:
        switch (c) {
        case 'e': ctx->state = State_64; return;
        }
        break;
    case State_64:
        switch (c) {
        case 's': ctx->state = State_65; return;
        }
        break;
    case State_65:
        switch (c) {
        case 's': ctx->state = State_66; return;
        }
        break;
    case State_66:
        switch (c) {
        case 'u': ctx->state = State_67; return;
        }
        break;
    case State_67:
        switch (c) {
        case 'r': ctx->state = State_68; return;
        }
        break;
    case State_68:
        switch (c) {
        case 'i': ctx->state = State_69; return;
        }
        break;
    case State_69:
        switch (c) {
        case 'z': ctx->state = State_70; return;
        }
        break;
    case State_70:
        switch (c) {
        case 'e': ctx->state = State_71; return;
        }
        break;
    case State_71:
        switch (c) {
        case ' ': ctx->state = State_72; return;
        }
        break;
    case State_73:
        switch (c) {
        case 'l': ctx->state = State_74; return;
        }
        break;
    case State_74:
        switch (c) {
        case 'e': ctx->state = State_75; return;
        }
        break;
    case State_75:
        switch (c) {
        case 'a': ctx->state = State_76; return;
        }
        break;
    case State_76:
        switch (c) {
        case 'r': ctx->state = State_77; return;
        }
        break;
    case State_77:
        switch (c) {
        case '_': ctx->state = State_78; return;
        }
        break;
    case State_78:
        switch (c) {
        case 't': ctx->state = State_79; return;
        }
        break;
    case State_79:
        switch (c) {
        case 'o': ctx->state = State_80; return;
        }
        break;
    case State_80:
        switch (c) {
        case '_': ctx->state = State_81; return;
        }
        break;
    case State_81:
        switch (c) {
        case 'i': ctx->state = State_82; return;
        }
        break;
    case State_82:
        switch (c) {
        case 'g': ctx->state = State_83; return;
        }
        break;
    case State_83:
        switch (c) {
        case 'n': ctx->state = State_84; return;
        }
        break;
    case State_84:
        switch (c) {
        case 'i': ctx->state = State_85; return;
        }
        break;
    case State_85:
        switch (c) {
        case 't': ctx->state = State_86; return;
        }
        break;
    case State_86:
        switch (c) {
        case 'e': ctx->state = State_87; return;
        }
        break;
    case State_88:
        switch (c) {
        case 'g': ctx->state = State_89; return;
        }
        break;
    case State_89:
        switch (c) {
        case 'n': ctx->state = State_90; return;
        }
        break;
    case State_90:
        switch (c) {
        case 'i': ctx->state = State_91; return;
        }
        break;
    case State_91:
        switch (c) {
        case 't': ctx->state = State_92; return;
        }
        break;
    case State_92:
        switch (c) {
        case 'e': ctx->state = State_93; return;
        }
        break;
    case State_94:
        switch (c) {
        case 'b': ctx->state = State_95; return;
        }
        break;
    case State_95:
        switch (c) {
        case 'o': ctx->state = State_96; return;
        }
        break;
    case State_96:
        switch (c) {
        case 'r': ctx->state = State_97; return;
        }
        break;
    case State_97:
        switch (c) {
        case 't': ctx->state = State_98; return;
        }
        break;
    case State_99:
        switch (c) {
        case 's': ctx->state = State_100; return;
        }
        break;
    case State_100:
        switch (c) {
        case 's': ctx->state = State_101; return;
        }
        break;
    case State_101:
        switch (c) {
        case 'i': ctx->state = State_102; return;
        }
        break;
    case State_102:
        switch (c) {
        case 'v': ctx->state = State_103; return;
        }
        break;
    case State_103:
        switch (c) {
        case 'a': ctx->state = State_104; return;
        }
        break;
    case State_104:
        switch (c) {
        case 't': ctx->state = State_105; return;
        }
        break;
    case State_105:
        switch (c) {
        case 'e': ctx->state = State_106; return;
        }
        break;
    case State_107:
        switch (c) {
        case 'e': ctx->state = State_108; return;
        }
        break;
    case State_108:
        switch (c) {
        case 's': ctx->state = State_109; return;
        }
        break;
    case State_109:
        switch (c) {
        case 'e': ctx->state = State_110; return;
        }
        break;
    case State_110:
        switch (c) {
        case 't': ctx->state = State_111; return;
        }
        break;
    case State_112:
        switch (c) {
        case 'o': ctx->state = State_113; return;
        }
        break;
    case State_113:
        switch (c) {
        case 'g': ctx->state = State_114; return;
        }
        break;
    case State_114:
        switch (c) {
        case 's': ctx->state = State_115; return;
        }
        break;
    case State_115:
        switch (c) {
        case ' ': ctx->state = State_116; return;
        }
        break;
    case State_116:
        switch (c) {
        case 'c': ctx->state = State_121; return;
        case 'u': ctx->state = State_117; return;
        }
        break;
    case State_117:
        switch (c) {
        case 's': ctx->state = State_118; return;
        }
        break;
    case State_118:
        switch (c) {
        case 'b': ctx->state = State_119; return;
        }
        break;
    case State_119:
        switch (c) {
        case ' ': ctx->state = State_120; return;
        }
        break;
    case State_121:
        switch (c) {
        case 'a': ctx->state = State_122; return;
        }
        break;
    case State_122:
        switch (c) {
        case 'n': ctx->state = State_123; return;
        }
        break;
    case State_123:
        switch (c) {
        case ' ': ctx->state = State_124; return;
        }
        break;
    case State_125:
        switch (c) {
        case 'o': ctx->state = State_126; return;
        }
        break;
    case State_126:
        switch (c) {
        case 'n': ctx->state = State_127; return;
        }
        break;
    case State_127:
        switch (c) {
        case 'f': ctx->state = State_128; return;
        }
        break;
    case State_128:
        switch (c) {
        case 'i': ctx->state = State_129; return;
        }
        break;
    case State_129:
        switch (c) {
        case 'g': ctx->state = State_130; return;
        }
        break;
    case State_130:
        switch (c) {
        case ' ': ctx->state = State_131; return;
        }
        break;
    case State_131:
        switch (c) {
        case 'c': ctx->state = State_144; return;
        case 'p': ctx->state = State_132; return;
        }
        break;
    case State_132:
        switch (c) {
        case 'r': ctx->state = State_133; return;
        }
        break;
    case State_133:
        switch (c) {
        case 'i': ctx->state = State_134; return;
        }
        break;
    case State_134:
        switch (c) {
        case 'n': ctx->state = State_135; return;
        }
        break;
    case State_135:
        switch (c) {
        case 't': ctx->state = State_136; return;
        }
        break;
    case State_136:
        switch (c) {
        case ' ': ctx->state = State_137; return;
        }
        break;
    case State_137:
        switch (c) {
        case 's': ctx->state = State_138; return;
        }
        break;
    case State_138:
        switch (c) {
        case 't': ctx->state = State_139; return;
        }
        break;
    case State_139:
        switch (c) {
        case 'a': ctx->state = State_140; return;
        }
        break;
    case State_140:
        switch (c) {
        case 't': ctx->state = State_141; return;
        }
        break;
    case State_141:
        switch (c) {
        case 'u': ctx->state = State_142; return;
        }
        break;
    case State_142:
        switch (c) {
        case 's': ctx->state = State_143; return;
        }
        break;
    case State_144:
        switch (c) {
        case 'o': ctx->state = State_145; return;
        }
        break;
    case State_145:
        switch (c) {
        case 'm': ctx->state = State_146; return;
        }
        break;
    case State_146:
        switch (c) {
        case 'm': ctx->state = State_147; return;
        }
        break;
    case State_147:
        switch (c) {
        case 'i': ctx->state = State_148; return;
        }
        break;
    case State_148:
        switch (c) {
        case 't': ctx->state = State_149; return;
        }
        break;
    }
    // no edge for c (or a stray character after a void command): wait in
    // State_Sink for the newline, so the rest of the line cannot run
    ctx->state = State_Sink;
}

}  // namespace prc_cli
