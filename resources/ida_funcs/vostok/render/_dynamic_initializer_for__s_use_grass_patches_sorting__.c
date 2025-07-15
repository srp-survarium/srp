int vostok::render::_dynamic_initializer_for__s_use_grass_patches_sorting__()
{
  s_use_grass_patches_sorting.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_use_grass_patches_sorting;
  vostok::console_commands::s_console_command_root = &s_use_grass_patches_sorting;
  s_use_grass_patches_sorting.m_value = &s_use_grass_patches_sorting_value;
  s_use_grass_patches_sorting.m_min = 0;
  s_use_grass_patches_sorting.m_max = 1;
  s_use_grass_patches_sorting.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  s_use_grass_patches_sorting.m_need_args = 1;
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_use_grass_patches_sorting__);
}
