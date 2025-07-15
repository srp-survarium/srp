int dynamic_initializer_for__s_speedtree_lod_index__()
{
  s_speedtree_lod_index.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_speedtree_lod_index;
  vostok::console_commands::s_console_command_root = &s_speedtree_lod_index;
  s_speedtree_lod_index.m_value = &s_speedtree_lod_index_value;
  s_speedtree_lod_index.m_min = 0;
  s_speedtree_lod_index.m_max = 10;
  s_speedtree_lod_index.m_need_args = 1;
  s_speedtree_lod_index.__vftable = (vostok::console_commands::cc_u32_vtbl *)&stru_95AF78.m_key_bindings[50].m_keyboard[1];
  return atexit(dynamic_atexit_destructor_for__s_speedtree_lod_index__);
}
