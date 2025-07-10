void __thiscall vostok::fs_new::synchronous_device_interface::synchronous_device_interface(
        vostok::fs_new::synchronous_device_interface *this,
        vostok::fs_new::asynchronous_device_interface *adi,
        vostok::memory::base_allocator *allocator)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_synchronize_query = 0;
  this->m_device.m_device_file_system = 0;
  this->m_out_of_memory = 0;
  vostok::fs_new::synchronous_device_interface::get_synchronous_access(this, adi, allocator);
}
