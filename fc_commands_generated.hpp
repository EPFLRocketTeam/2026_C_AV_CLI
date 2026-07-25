// GENERATED FILE -- do not edit by hand. Regenerate with generate_commands.py.
#pragma once

#include <cstdint>

#include <cstdlib>

#include <cstring>

enum State {
    State_0,
    State_1,
    State_2,
    State_3,
    State_4,
    State_5,
    State_6,
    State_7,
    State_8,
    State_9,
    State_10,
    State_11,
    State_12,
    State_13,
    State_14,
    State_15,
    State_16,
    State_17,
    State_18,
    State_19,
    State_20,
    State_21,
    State_22,
    State_23,
    State_24,
    State_25,
    State_26,
    State_27,
    State_28,
    State_29,
    State_30,
    State_31,
    State_32,
    State_33,
    State_34,
    State_35,
    State_36,
    State_37,
    State_38,
    State_39,
    State_40,
    State_41,
    State_42,
    State_43,
    State_44,
    State_45,
    State_46,
    State_47,
    State_48,
    State_49,
    State_50,
    State_51,
    State_52,
    State_53,
    State_54,
    State_55,
    State_56,
    State_57,
    State_58,
    State_59,
    State_60,
    State_61,
    State_62,
    State_63,
};

struct driver {
    void (*main_fuel)(void* ctx, bool value);
    void (*main_lox)(void* ctx, bool value);
    void (*p_eth)(void* ctx, float value);
    void (*p_lox)(void* ctx, float value);
    void (*pressure_fuel)(void* ctx, bool value);
    void (*pressure_lox)(void* ctx, bool value);
    void (*vent_copv)(void* ctx, bool value);
    void (*vent_fuel)(void* ctx, bool value);
    void (*vent_lox)(void* ctx, bool value);
};

struct context {
    State state = State_0;
    char arg_buffer[33];
    uint8_t arg_len = 0;
    void* handler_ctx = nullptr;
};

void push_char(context* ctx, const driver* drv, char c);
