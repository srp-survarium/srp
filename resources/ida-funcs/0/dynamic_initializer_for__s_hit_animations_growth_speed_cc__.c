int __thiscall dynamic_initializer_for__s_hit_animations_growth_speed_cc__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_hit_animations_growth_speed_cc,
    "hit_animations_growth_speed",
    1,
    command_type_engine_internal,
    execution_filter_general);
  s_hit_animations_growth_speed_cc.m_min = FLOAT_0_1;
  s_hit_animations_growth_speed_cc.m_value = &s_hit_animations_growth_speed;
  s_hit_animations_growth_speed_cc.m_max = s_spot_max_distance;
  s_hit_animations_growth_speed_cc.m_need_args = 1;
  s_hit_animations_growth_speed_cc.__vftable = (vostok::console_commands::cc_float_vtbl *)&vostok::console_commands::cc_float::`vftable';
  return atexit(dynamic_atexit_destructor_for__s_hit_animations_growth_speed_cc__);
}
