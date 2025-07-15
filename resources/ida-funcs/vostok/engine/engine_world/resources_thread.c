void __thiscall vostok::engine::engine_world::resources_thread(
        vostok::engine::engine_world *this,
        vostok::apc::threads_enum apc_thread_id)
{
  vostok::resources::resources_manager *v3; // ecx
  vostok::threading::event *v4; // ecx
  vostok::resources::resources_manager *v5; // [esp-4h] [ebp-Ch]

  g_threads.m_begin[apc_thread_id].m_thread_id = GetCurrentThreadId();
  vostok::apc::process(apc_thread_id, (vostok::command_line::key *)(48 * apc_thread_id), 0);
  v3 = v5;
  while ( !this->m_resources_destruction_started )
  {
    vostok::resources::resources_manager::resources_thread_tick(v3);
    vostok::apc::try_process_single_call(res_man);
    vostok::threading::event::wait(v4, (HANDLE *)&s_resources_manager_buffer.m_resources_wakeup_event, 0x12Cu);
  }
  vostok::apc::process(apc_thread_id, (vostok::command_line::key *)v3, 0);
}
