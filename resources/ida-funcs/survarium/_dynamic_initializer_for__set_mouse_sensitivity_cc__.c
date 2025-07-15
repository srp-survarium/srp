int __thiscall survarium::_dynamic_initializer_for__set_mouse_sensitivity_cc__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&set_mouse_sensitivity_cc,
    "sensitivity",
    1,
    command_type_user_specific,
    execution_filter_general);
  set_mouse_sensitivity_cc.m_min = FLOAT_0_0099999998;
  set_mouse_sensitivity_cc.m_value = &survarium::g_mouse_sensitivity;
  set_mouse_sensitivity_cc.m_max = FLOAT_10_0;
  set_mouse_sensitivity_cc.m_need_args = 1;
  set_mouse_sensitivity_cc.__vftable = (vostok::console_commands::cc_float_vtbl *)&vostok::console_commands::cc_float::`vftable';
  return atexit(survarium::_dynamic_atexit_destructor_for__set_mouse_sensitivity_cc__);
}
