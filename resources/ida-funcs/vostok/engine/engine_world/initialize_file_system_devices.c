void __usercall vostok::engine::engine_world::initialize_file_system_devices(
        vostok::engine::engine_world *this@<ecx>,
        int a2@<edi>)
{
  if ( a2 != -24 )
    vostok::fs_new::asynchronous_device_interface::asynchronous_device_interface(
      (vostok::fs_new::asynchronous_device_interface *)(a2 + 24),
      (vostok::fs_new::device_file_system_interface *)(a2 + 16),
      watcher_enabled_true);
  _InterlockedExchange((volatile __int32 *)(a2 + 228), 1);
  if ( a2 != -240 )
    vostok::fs_new::asynchronous_device_interface::asynchronous_device_interface(
      (vostok::fs_new::asynchronous_device_interface *)(a2 + 240),
      (vostok::fs_new::device_file_system_interface *)(a2 + 20),
      watcher_enabled_true);
  _InterlockedExchange((volatile __int32 *)(a2 + 444), 1);
  vostok::engine::engine_world::initialize_file_system_device(
    6u,
    (vostok::engine::engine_world *)a2,
    *(vostok::fs_new::asynchronous_device_interface **)(a2 + 224),
    "hdd");
  vostok::engine::engine_world::initialize_file_system_device(
    7u,
    (vostok::engine::engine_world *)a2,
    *(vostok::fs_new::asynchronous_device_interface **)(a2 + 440),
    "dvd");
}
