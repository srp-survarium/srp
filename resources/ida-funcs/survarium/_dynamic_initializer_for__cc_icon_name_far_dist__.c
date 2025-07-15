int __thiscall survarium::_dynamic_initializer_for__cc_icon_name_far_dist__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&cc_icon_name_far_dist,
    "icon_name_far_dist",
    1,
    command_type_engine_internal,
    execution_filter_general);
  cc_icon_name_far_dist.m_min = s_bm_current_air_resistance;
  cc_icon_name_far_dist.m_value = &survarium::g_icon_name_far_dist;
  cc_icon_name_far_dist.m_max = s_spot_max_distance;
  cc_icon_name_far_dist.m_need_args = 1;
  cc_icon_name_far_dist.__vftable = (vostok::console_commands::cc_float_vtbl *)&vostok::console_commands::cc_float::`vftable';
  return atexit(survarium::_dynamic_atexit_destructor_for__cc_icon_name_far_dist__);
}
