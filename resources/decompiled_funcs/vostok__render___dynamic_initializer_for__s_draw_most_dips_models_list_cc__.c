int vostok::render::_dynamic_initializer_for__s_draw_most_dips_models_list_cc__()
{
  s_draw_most_dips_models_list_cc.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_draw_most_dips_models_list_cc;
  vostok::console_commands::s_console_command_root = &s_draw_most_dips_models_list_cc;
  s_draw_most_dips_models_list_cc.m_value = &s_draw_most_dips_models_list_value;
  s_draw_most_dips_models_list_cc.m_min = 0;
  s_draw_most_dips_models_list_cc.m_max = 10;
  s_draw_most_dips_models_list_cc.m_need_args = 1;
  s_draw_most_dips_models_list_cc.__vftable = (vostok::console_commands::cc_u32_vtbl *)&stru_95AF78.m_key_bindings[50].m_keyboard[1];
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_draw_most_dips_models_list_cc__);
}
