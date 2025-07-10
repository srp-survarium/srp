void __thiscall vostok::engine::engine_world::thread_function<vostok::engine::device_ticker>(
        vostok::engine::engine_world *this,
        vostok::apc::threads_enum apc_thread_id,
        const vostok::engine::device_ticker *functor)
{
  g_threads.m_begin[apc_thread_id].m_thread_id = GetCurrentThreadId();
  vostok::apc::process(apc_thread_id);
  while ( !this->m_file_system_devices_destruction_started )
    vostok::fs_new::asynchronous_device_interface::tick(functor->m_device, 1);
  vostok::apc::process(apc_thread_id);
}
