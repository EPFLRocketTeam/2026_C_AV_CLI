// GENERATED FILE -- do not edit by hand. Regenerate with generate_commands.py.
#pragma once

#include <cstdint>

#include <cstdlib>

#include <cstring>

namespace prc_cli {

enum State {
    State_0,
    State_1,
    State_2,
    State_3,
    State_4,
    State_6,
    State_7,
    State_8,
    State_9,
    State_10,
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
    State_23,
    State_24,
    State_25,
    State_26,
    State_27,
    State_28,
    State_30,
    State_31,
    State_32,
    State_33,
    State_34,
    State_35,
    State_36,
    State_37,
    State_38,
    State_40,
    State_41,
    State_42,
    State_43,
    State_45,
    State_46,
    State_48,
    State_50,
    State_51,
    State_52,
    State_53,
    State_54,
    State_55,
    State_56,
    State_58,
    State_59,
    State_60,
    State_61,
    State_62,
    State_63,
    State_64,
    State_65,
    State_66,
    State_67,
    State_68,
    State_69,
    State_70,
    State_71,
    State_73,
    State_74,
    State_75,
    State_76,
    State_77,
    State_78,
    State_79,
    State_80,
    State_81,
    State_82,
    State_83,
    State_84,
    State_85,
    State_86,
    State_88,
    State_89,
    State_90,
    State_91,
    State_92,
    State_94,
    State_95,
    State_96,
    State_97,
    State_99,
    State_100,
    State_101,
    State_102,
    State_103,
    State_104,
    State_105,
    State_107,
    State_108,
    State_109,
    State_110,
    State_112,
    State_113,
    State_114,
    State_115,
    State_116,
    State_117,
    State_118,
    State_119,
    State_121,
    State_122,
    State_123,
    State_125,
    State_126,
    State_127,
    State_128,
    State_129,
    State_130,
    State_131,
    State_132,
    State_133,
    State_134,
    State_135,
    State_136,
    State_137,
    State_138,
    State_139,
    State_140,
    State_141,
    State_142,
    State_144,
    State_145,
    State_146,
    State_147,
    State_148,
    State_150,
    State_151,
    State_152,
    State_153,
    State_154,
    State_155,
    State_156,
    State_157,
    State_159,
    State_160,
    State_161,
    State_162,
    State_163,
    State_165,
    State_166,
    State_167,
    State_168,
    State_169,
    State_170,
    State_5,
    State_11,
    State_87,
    State_93,
    State_98,
    State_106,
    State_111,
    State_143,
    State_149,
    State_158,
    State_164,
    State_171,
    State_22,
    State_29,
    State_39,
    State_44,
    State_47,
    State_49,
    State_57,
    State_72,
    State_120,
    State_124,
    State_Sink,
};

struct driver {
    void (*config_commit)(void* ctx);
    void (*config_print_status)(void* ctx);
    void (*fsm_abort)(void* ctx);
    void (*fsm_clear_to_ignite)(void* ctx);
    void (*fsm_ignite)(void* ctx);
    void (*fsm_passivate)(void* ctx);
    void (*fsm_pressurize)(void* ctx, bool value);
    void (*fsm_reset)(void* ctx);
    void (*igniter)(void* ctx, bool value);
    void (*logs_can)(void* ctx, bool value);
    void (*logs_usb)(void* ctx, bool value);
    void (*sensors_print)(void* ctx);
    void (*state_print)(void* ctx);
    void (*system_confirm)(void* ctx);
    void (*system_dfu)(void* ctx);
    void (*system_reboot)(void* ctx);
    void (*valve_ball)(void* ctx, float value);
    void (*valve_copv_vent)(void* ctx, bool value);
    void (*valve_me)(void* ctx, bool value);
    void (*valve_mo)(void* ctx, bool value);
    void (*valve_safety)(void* ctx, bool value);
    void (*valve_vent)(void* ctx, bool value);
    // Optional: called when a bool argument is not open, close, on or off.
    void (*on_bad_argument)(void* ctx) = nullptr;
    // Optional: called when a non-empty line matches no command.
    void (*on_unknown_command)(void* ctx) = nullptr;
};

struct context {
    State state = State_0;
    char arg_buffer[33];
    uint8_t arg_len = 0;
    void* handler_ctx = nullptr;
};

void push_char(context* ctx, const driver* drv, char c);

}  // namespace prc_cli
