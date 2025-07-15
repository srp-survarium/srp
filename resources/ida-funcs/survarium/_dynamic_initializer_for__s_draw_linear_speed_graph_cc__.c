int __thiscall survarium::_dynamic_initializer_for__s_draw_linear_speed_graph_cc__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_draw_linear_speed_graph_cc,
    "draw_linear_speed_graph",
    0,
    command_type_user_specific,
    execution_filter_general);
  s_draw_linear_speed_graph_cc.m_value = &s_draw_linear_speed_graph_value;
  s_draw_linear_speed_graph_cc.m_min = 0;
  s_draw_linear_speed_graph_cc.m_max = 1;
  s_draw_linear_speed_graph_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_draw_linear_speed_graph_cc.m_need_args = 1;
  return atexit(survarium::_dynamic_atexit_destructor_for__s_draw_linear_speed_graph_cc__);
}
