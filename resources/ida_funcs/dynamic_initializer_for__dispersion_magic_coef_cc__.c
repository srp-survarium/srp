int dynamic_initializer_for__dispersion_magic_coef_cc__()
{
  dispersion_magic_coef_cc.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &dispersion_magic_coef_cc;
  dispersion_magic_coef_cc.m_min = 0.0;
  vostok::console_commands::s_console_command_root = &dispersion_magic_coef_cc;
  dispersion_magic_coef_cc.m_value = &s_dispersion_gui_scale_coef_value;
  dispersion_magic_coef_cc.m_max = 10000.0;
  dispersion_magic_coef_cc.m_need_args = 1;
  dispersion_magic_coef_cc.__vftable = (vostok::console_commands::cc_float_vtbl *)&stru_95AF78.m_key_bindings[48];
  return atexit(dynamic_atexit_destructor_for__dispersion_magic_coef_cc__);
}
