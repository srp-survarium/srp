int __thiscall survarium::_dynamic_initializer_for__set_mouse_invert_cc__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&set_mouse_invert_cc,
    "mouse_invertion",
    1,
    command_type_user_specific,
    execution_filter_general);
  set_mouse_invert_cc.m_value = &survarium::g_mouse_invert;
  set_mouse_invert_cc.m_min = 0;
  set_mouse_invert_cc.m_max = 1;
  set_mouse_invert_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  set_mouse_invert_cc.m_need_args = 1;
  return atexit(survarium::_dynamic_atexit_destructor_for__set_mouse_invert_cc__);
}
