// GENERATED FILE -- do not edit by hand. Regenerate with generate_commands.py.
#include "fc_commands_generated.hpp"

#include <cstdlib>

void push_char(context* ctx, const driver* drv, char c) {
    switch (ctx->state) {
    case State_0: {
        switch (c) {
        case 'm': ctx->state = State_20; break;
        case 'p': ctx->state = State_1; break;
        case 'v': ctx->state = State_34; break;
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
        case 'e': ctx->state = State_53; break;
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
        switch (c) {
        case 'e': ctx->state = State_16; break;
        case 'l': ctx->state = State_12; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_12: {
        switch (c) {
        case 'o': ctx->state = State_13; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_13: {
        switch (c) {
        case 'x': ctx->state = State_14; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_14: {
        switch (c) {
        case ' ': ctx->state = State_15; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_15: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->p_lox(ctx->handler_ctx, strtof(ctx->arg_buffer, nullptr));
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_16: {
        switch (c) {
        case 't': ctx->state = State_17; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_17: {
        switch (c) {
        case 'h': ctx->state = State_18; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_18: {
        switch (c) {
        case ' ': ctx->state = State_19; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_19: {
        if (c == '\n') {
            ctx->arg_buffer[ctx->arg_len] = '\0';
            drv->p_eth(ctx->handler_ctx, strtof(ctx->arg_buffer, nullptr));
            ctx->state = State_0;
            ctx->arg_len = 0;
        } else if (ctx->arg_len < 32) {
            ctx->arg_buffer[ctx->arg_len++] = c;
        }
        break;
    }
    case State_20: {
        switch (c) {
        case 'a': ctx->state = State_21; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_21: {
        switch (c) {
        case 'i': ctx->state = State_22; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_22: {
        switch (c) {
        case 'n': ctx->state = State_23; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_23: {
        switch (c) {
        case ' ': ctx->state = State_24; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_24: {
        switch (c) {
        case 'f': ctx->state = State_29; break;
        case 'l': ctx->state = State_25; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_25: {
        switch (c) {
        case 'o': ctx->state = State_26; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_26: {
        switch (c) {
        case 'x': ctx->state = State_27; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_27: {
        switch (c) {
        case ' ': ctx->state = State_28; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_28: {
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
    case State_29: {
        switch (c) {
        case 'u': ctx->state = State_30; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_30: {
        switch (c) {
        case 'e': ctx->state = State_31; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_31: {
        switch (c) {
        case 'l': ctx->state = State_32; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_32: {
        switch (c) {
        case ' ': ctx->state = State_33; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_33: {
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
    case State_34: {
        switch (c) {
        case 'e': ctx->state = State_35; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_35: {
        switch (c) {
        case 'n': ctx->state = State_36; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_36: {
        switch (c) {
        case 't': ctx->state = State_37; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_37: {
        switch (c) {
        case ' ': ctx->state = State_38; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_38: {
        switch (c) {
        case 'c': ctx->state = State_39; break;
        case 'f': ctx->state = State_48; break;
        case 'l': ctx->state = State_44; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_39: {
        switch (c) {
        case 'o': ctx->state = State_40; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_40: {
        switch (c) {
        case 'p': ctx->state = State_41; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_41: {
        switch (c) {
        case 'v': ctx->state = State_42; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_42: {
        switch (c) {
        case ' ': ctx->state = State_43; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_43: {
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
    case State_44: {
        switch (c) {
        case 'o': ctx->state = State_45; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_45: {
        switch (c) {
        case 'x': ctx->state = State_46; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_46: {
        switch (c) {
        case ' ': ctx->state = State_47; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_47: {
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
    case State_48: {
        switch (c) {
        case 'u': ctx->state = State_49; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_49: {
        switch (c) {
        case 'e': ctx->state = State_50; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_50: {
        switch (c) {
        case 'l': ctx->state = State_51; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_51: {
        switch (c) {
        case ' ': ctx->state = State_52; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_52: {
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
    case State_53: {
        switch (c) {
        case ' ': ctx->state = State_54; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_54: {
        switch (c) {
        case 'f': ctx->state = State_59; break;
        case 'l': ctx->state = State_55; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_55: {
        switch (c) {
        case 'o': ctx->state = State_56; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_56: {
        switch (c) {
        case 'x': ctx->state = State_57; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_57: {
        switch (c) {
        case ' ': ctx->state = State_58; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_58: {
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
    case State_59: {
        switch (c) {
        case 'u': ctx->state = State_60; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_60: {
        switch (c) {
        case 'e': ctx->state = State_61; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_61: {
        switch (c) {
        case 'l': ctx->state = State_62; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_62: {
        switch (c) {
        case ' ': ctx->state = State_63; break;
        default: ctx->state = State_0; break;
        }
        break;
    }
    case State_63: {
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
    }
}
