int __thiscall vostok::render::_dynamic_initializer_for__s_draw_most_dips_models_list_cc__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_draw_most_dips_models_list_cc,
    "r_draw_most_dips_models_list_by_lod",
    0,
    command_type_engine_internal,
    execution_filter_general);
  s_draw_most_dips_models_list_cc.m_min = 0;
  s_draw_most_dips_models_list_cc.m_value = &s_draw_most_dips_models_list_value;
  s_draw_most_dips_models_list_cc.m_max = 10;
  s_draw_most_dips_models_list_cc.m_need_args = 1;
  s_draw_most_dips_models_list_cc.__vftable = (vostok::console_commands::cc_u32_vtbl *)&vostok::console_commands::cc_u32::`vftable';
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_draw_most_dips_models_list_cc__);
}
