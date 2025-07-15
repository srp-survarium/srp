void __thiscall vostok::resources::tick(vostok::resources::resources_manager *ecx0)
{
  vostok::resources::resources_manager *v1; // ecx

  if ( vostok::threading::g_debug_single_thread.m_type == type_unset )
  {
    vostok::threading::g_debug_single_thread.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  if ( vostok::threading::g_debug_single_thread.m_type != type_recursive )
  {
    vostok::resources::resources_manager::resources_thread_tick(ecx0);
    vostok::resources::resources_manager::cooker_thread_tick(v1);
  }
}
