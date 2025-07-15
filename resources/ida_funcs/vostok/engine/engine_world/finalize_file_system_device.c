void __thiscall vostok::engine::engine_world::finalize_file_system_device(
        vostok::engine::engine_world *this,
        vostok::fs_new::asynchronous_device_interface *const device)
{
  vostok::fs_new::asynchronous_device_interface::finalize(device);
}
