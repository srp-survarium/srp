int __thiscall dynamic_initializer_for__s_use_screeen_space_portals_intersection_cc__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_use_screeen_space_portals_intersection_cc,
    "r_use_ss_portals_intersection",
    0,
    command_type_engine_internal,
    execution_filter_general);
  s_use_screeen_space_portals_intersection_cc.m_value = &s_use_screeen_space_portals_intersection_value;
  s_use_screeen_space_portals_intersection_cc.m_min = 0;
  s_use_screeen_space_portals_intersection_cc.m_max = 1;
  s_use_screeen_space_portals_intersection_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_use_screeen_space_portals_intersection_cc.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_use_screeen_space_portals_intersection_cc__);
}
