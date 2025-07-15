int __thiscall dynamic_initializer_for__s_cc_lighting_material_strategy__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_cc_lighting_material_strategy,
    "lighting_material_strategy",
    1,
    command_type_engine_internal,
    execution_filter_general);
  s_cc_lighting_material_strategy.m_min = 0;
  s_cc_lighting_material_strategy.m_value = &s_lighting_material_strategy;
  s_cc_lighting_material_strategy.m_max = 4;
  s_cc_lighting_material_strategy.m_need_args = 1;
  s_cc_lighting_material_strategy.__vftable = (vostok::console_commands::cc_u32_vtbl *)&vostok::console_commands::cc_u32::`vftable';
  return atexit(dynamic_atexit_destructor_for__s_cc_lighting_material_strategy__);
}
