int __thiscall survarium::_dynamic_initializer_for__s_local_player_random_input_cc__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_local_player_random_input_cc,
    "local_player_random_input",
    0,
    command_type_user_specific,
    execution_filter_general);
  s_local_player_random_input_cc.m_value = &s_is_local_player_random_input_enabled;
  s_local_player_random_input_cc.m_min = 0;
  s_local_player_random_input_cc.m_max = 1;
  s_local_player_random_input_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_local_player_random_input_cc.m_need_args = 1;
  return atexit(survarium::_dynamic_atexit_destructor_for__s_local_player_random_input_cc__);
}
