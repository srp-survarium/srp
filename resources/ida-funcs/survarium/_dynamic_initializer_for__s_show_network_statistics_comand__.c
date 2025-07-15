int __thiscall survarium::_dynamic_initializer_for__s_show_network_statistics_comand__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_show_network_statistics_comand,
    "net_stats",
    1,
    command_type_user_specific,
    execution_filter_general);
  s_show_network_statistics_comand.m_value = &s_show_network_statistics;
  s_show_network_statistics_comand.m_min = 0;
  s_show_network_statistics_comand.m_max = 1;
  s_show_network_statistics_comand.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_show_network_statistics_comand.m_need_args = 1;
  return atexit(survarium::_dynamic_atexit_destructor_for__s_show_network_statistics_comand__);
}
