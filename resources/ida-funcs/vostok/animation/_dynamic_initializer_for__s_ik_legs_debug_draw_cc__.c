int __thiscall vostok::animation::_dynamic_initializer_for__s_ik_legs_debug_draw_cc__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_ik_legs_debug_draw_cc,
    "ik_legs_debug_draw",
    0,
    command_type_user_specific,
    execution_filter_general);
  s_ik_legs_debug_draw_cc.m_value = &s_ik_legs_debug_draw_value;
  s_ik_legs_debug_draw_cc.m_min = 0;
  s_ik_legs_debug_draw_cc.m_max = 1;
  s_ik_legs_debug_draw_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_ik_legs_debug_draw_cc.m_need_args = 1;
  return atexit(vostok::animation::_dynamic_atexit_destructor_for__s_ik_legs_debug_draw_cc__);
}
