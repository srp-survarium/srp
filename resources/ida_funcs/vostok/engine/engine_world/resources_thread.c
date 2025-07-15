void __userpurge vostok::engine::engine_world::resources_thread(
        vostok::engine::engine_world *this@<ecx>,
        double a2@<st0>,
        vostok::apc::threads_enum apc_thread_id)
{
  vostok::resources::resources_manager *v4; // ecx

  g_threads.m_begin[apc_thread_id].m_thread_id = GetCurrentThreadId();
  vostok::apc::process(apc_thread_id);
  while ( !this->m_resources_destruction_started )
  {
    vostok::threading::event::wait(
      (vostok::threading::event *)((char *)&dword_203D0 + (unsigned int)vostok::resources::g_resources_manager.m_variable),
      (vostok::threading::event *)((char *)&dword_203D0 + (unsigned int)vostok::resources::g_resources_manager.m_variable),
      0x12Cu);
    vostok::resources::resources_manager::resources_thread_tick(
      v4,
      vostok::resources::g_resources_manager.m_variable,
      a2);
  }
  vostok::apc::process(apc_thread_id);
}
