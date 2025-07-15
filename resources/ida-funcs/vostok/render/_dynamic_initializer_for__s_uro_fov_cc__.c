int __thiscall vostok::render::_dynamic_initializer_for__s_uro_fov_cc__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_uro_fov_cc,
    "uro_fov",
    1,
    command_type_user_specific,
    execution_filter_general);
  s_uro_fov_cc.m_min = 0.0;
  s_uro_fov_cc.m_value = &s_uro_fov_value;
  s_uro_fov_cc.m_max = s_spot_max_distance;
  s_uro_fov_cc.m_need_args = 1;
  s_uro_fov_cc.__vftable = (vostok::console_commands::cc_float_vtbl *)&vostok::console_commands::cc_float::`vftable';
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_uro_fov_cc__);
}
