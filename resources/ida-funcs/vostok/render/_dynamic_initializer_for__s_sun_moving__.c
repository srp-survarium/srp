int __thiscall vostok::render::_dynamic_initializer_for__s_sun_moving__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_sun_moving,
    "sun_moving",
    0,
    command_type_user_specific,
    execution_filter_general);
  s_sun_moving.m_value = &s_sun_moving_value;
  s_sun_moving.m_min = 0;
  s_sun_moving.m_max = 1;
  s_sun_moving.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_sun_moving.m_need_args = 1;
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_sun_moving__);
}
