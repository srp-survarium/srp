int vostok::render::_dynamic_initializer_for__s_use_one_material__()
{
  s_use_one_material.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_use_one_material;
  vostok::console_commands::s_console_command_root = &s_use_one_material;
  s_use_one_material.m_value = &s_use_one_material_value;
  s_use_one_material.m_min = 0;
  s_use_one_material.m_max = 1;
  s_use_one_material.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  s_use_one_material.m_need_args = 1;
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_use_one_material__);
}
