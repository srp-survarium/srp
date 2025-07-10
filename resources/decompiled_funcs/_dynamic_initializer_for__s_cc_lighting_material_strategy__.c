int dynamic_initializer_for__s_cc_lighting_material_strategy__()
{
  s_cc_lighting_material_strategy.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_cc_lighting_material_strategy;
  vostok::console_commands::s_console_command_root = &s_cc_lighting_material_strategy;
  s_cc_lighting_material_strategy.m_value = &s_lighting_material_strategy;
  s_cc_lighting_material_strategy.m_min = 0;
  s_cc_lighting_material_strategy.m_max = 4;
  s_cc_lighting_material_strategy.m_need_args = 1;
  s_cc_lighting_material_strategy.__vftable = (vostok::console_commands::cc_u32_vtbl *)&stru_95AF78.m_key_bindings[50].m_keyboard[1];
  return atexit(dynamic_atexit_destructor_for__s_cc_lighting_material_strategy__);
}
