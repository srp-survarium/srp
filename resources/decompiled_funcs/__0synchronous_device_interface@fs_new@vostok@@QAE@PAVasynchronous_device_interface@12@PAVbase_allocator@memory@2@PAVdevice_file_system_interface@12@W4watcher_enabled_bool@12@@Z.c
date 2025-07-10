void __thiscall vostok::fs_new::synchronous_device_interface::synchronous_device_interface(
        vostok::fs_new::synchronous_device_interface *this,
        vostok::fs_new::asynchronous_device_interface *adi,
        vostok::memory::base_allocator *allocator,
        vostok::fs_new::device_file_system_interface *device,
        vostok::fs_new::watcher_enabled_bool watcher_enabled)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_synchronize_query = 0;
  this->m_device.m_device_file_system = device;
  this->m_out_of_memory = 0;
  if ( !device )
    vostok::fs_new::synchronous_device_interface::get_synchronous_access(this, adi, allocator);
}
