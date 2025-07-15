void __thiscall vostok::fs_new::synchronous_device_interface::initialize_private(
        vostok::fs_new::synchronous_device_interface *this,
        const vostok::fs_new::device_file_system_no_watcher_proxy *device,
        vostok::fs_new::synchronize_device_query *synchronize_query)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_device = (vostok::fs_new::device_file_system_no_watcher_proxy)device->m_device_file_system;
  this->m_synchronize_query = synchronize_query;
}
