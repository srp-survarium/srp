int __thiscall vostok::physics::_dynamic_initializer_for__s_cc_old_use_fixed_time_step_cc__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_cc_old_use_fixed_time_step_cc,
    "cc_old_use_fixed_time_step",
    1,
    command_type_user_specific,
    execution_filter_general);
  s_cc_old_use_fixed_time_step_cc.m_value = &s_cc_old_use_fixed_time_step_value;
  s_cc_old_use_fixed_time_step_cc.m_min = 0;
  s_cc_old_use_fixed_time_step_cc.m_max = 1;
  s_cc_old_use_fixed_time_step_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_cc_old_use_fixed_time_step_cc.m_need_args = 1;
  return atexit(vostok::physics::_dynamic_atexit_destructor_for__s_cc_old_use_fixed_time_step_cc__);
}
