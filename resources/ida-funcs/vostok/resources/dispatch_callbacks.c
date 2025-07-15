void __thiscall vostok::resources::dispatch_callbacks(vostok::resources::resources_manager *ecx0)
{
  if ( vostok::resources::g_resources_manager.m_initialized )
  {
    if ( vostok::threading::g_debug_single_thread.m_type == type_unset )
    {
      vostok::threading::g_debug_single_thread.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( vostok::threading::g_debug_single_thread.m_type != type_recursive )
      vostok::resources::tick(ecx0);
    vostok::resources::resources_manager::dispatch_callbacks(vostok::resources::g_resources_manager.m_variable, 0);
  }
}
