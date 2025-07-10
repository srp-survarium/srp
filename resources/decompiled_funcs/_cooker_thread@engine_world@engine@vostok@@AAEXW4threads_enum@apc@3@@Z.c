void __thiscall vostok::engine::engine_world::cooker_thread(
        vostok::engine::engine_world *this,
        vostok::apc::threads_enum apc_thread_id)
{
  vostok::resources::resources_manager *v3; // ecx

  g_threads.m_begin[apc_thread_id].m_thread_id = GetCurrentThreadId();
  vostok::apc::process(apc_thread_id);
  while ( !this->m_resources_cooker_destruction_started )
  {
    vostok::threading::event::wait(
      (vostok::threading::event *)((char *)&dword_203E0 + (unsigned int)vostok::resources::g_resources_manager.m_variable),
      (vostok::threading::event *)((char *)&dword_203E0 + (unsigned int)vostok::resources::g_resources_manager.m_variable),
      0x12Cu);
    vostok::resources::resources_manager::cooker_thread_tick(v3, vostok::resources::g_resources_manager.m_variable);
  }
  vostok::apc::process(apc_thread_id);
}
