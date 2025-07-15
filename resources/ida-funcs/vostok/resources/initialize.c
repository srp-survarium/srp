void __usercall vostok::resources::initialize(
        vostok::resources::resources_manager *hdd@<ecx>,
        vostok::fs_new::asynchronous_device_interface *dvd@<eax>)
{
  vostok::resources::enable_fs_watcher_bool v2; // [esp+0h] [ebp-4h]

  vostok::resources::resources_manager::resources_manager(
    hdd,
    (vostok::fs_new::asynchronous_device_interface *)hdd,
    dvd,
    v2);
  _InterlockedExchange(&vostok::resources::g_resources_manager.m_initialized, 1);
  vostok::threading::yield(0xAu);
}
