void __thiscall vostok::engine::engine_world::cooker_thread(
        vostok::engine::engine_world *this,
        vostok::apc::threads_enum apc_thread_id)
{
  vostok::threading::event *v3; // ecx
  volatile int *p_m_resources_cooker_destruction_started; // esi
  vostok::resources::resources_manager *v5; // ecx
  vostok::threading::event *v6; // [esp-4h] [ebp-Ch]

  g_threads.m_begin[apc_thread_id].m_thread_id = GetCurrentThreadId();
  vostok::apc::process(apc_thread_id, (vostok::command_line::key *)(48 * apc_thread_id), 1);
  v3 = v6;
  p_m_resources_cooker_destruction_started = &this->m_resources_cooker_destruction_started;
  while ( !*p_m_resources_cooker_destruction_started )
  {
    vostok::threading::event::wait(v3, (HANDLE *)&s_resources_manager_buffer.m_cooker_wakeup_event, 0x12Cu);
    vostok::resources::resources_manager::cooker_thread_tick(v5);
  }
  vostok::apc::process(apc_thread_id, (vostok::command_line::key *)v3, 1);
}
