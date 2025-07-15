void __thiscall vostok::resources::resources_manager::wait_and_dispatch_callbacks(
        vostok::resources::resources_manager *this,
        bool call_from_main_thread,
        vostok::resources::allocate_functionality *finalizing_thread)
{
  BOOL i; // eax
  vostok::command_line::key *v4; // ecx
  vostok::command_line::key *v5; // ecx
  vostok::command_line::key *v6; // ecx
  vostok::command_line::key *v7; // ecx

  if ( call_from_main_thread || vostok::threading::core_count(this) != 1 )
  {
    for ( i = TryEnterCriticalSection((LPCRITICAL_SECTION)&s_resources_manager_buffer.m_wait_and_dispatch_callbacks_mutex);
          !i;
          i = TryEnterCriticalSection((LPCRITICAL_SECTION)&s_resources_manager_buffer.m_wait_and_dispatch_callbacks_mutex) )
    {
      if ( vostok::command_line::key::is_set(v4, (int)&vostok::threading::g_debug_single_thread) )
        vostok::resources::tick(v5);
      vostok::resources::resources_manager::dispatch_callbacks(
        &s_resources_manager_buffer,
        (vostok::resources::allocate_functionality *)1);
    }
    while ( !vostok::resources::resources_manager::thread_can_exit((vostok::resources::resources_manager *)v4) )
    {
      if ( vostok::command_line::key::is_set(v7, (int)&vostok::threading::g_debug_single_thread) )
        vostok::resources::tick(v6);
      vostok::resources::resources_manager::dispatch_callbacks(&s_resources_manager_buffer, finalizing_thread);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&s_resources_manager_buffer.m_wait_and_dispatch_callbacks_mutex);
  }
}
