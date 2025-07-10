void __thiscall vostok::fs_new::synchronous_device_interface::synchronous_device_interface(
        vostok::fs_new::synchronous_device_interface *this,
        vostok::fs_new::device_file_system_no_watcher_proxy device)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_synchronize_query = 0;
  this->m_device = device;
  this->m_out_of_memory = 0;
}
