void __cdecl vostok::device_thread(vostok::fs_new::asynchronous_device_interface *device_interface)
{
  while ( !vostok::vfs::s_global_unmounts_counter.m_flags.m_flags )
  {
    vostok::fs_new::asynchronous_device_interface::tick(device_interface, 1);
    vostok::threading::yield(0);
  }
  vostok::fs_new::asynchronous_device_interface::finalize(device_interface);
  vostok::threading::interlocked_exchange_pointer(&vostok::s_device_thread_exited, 1);
}
