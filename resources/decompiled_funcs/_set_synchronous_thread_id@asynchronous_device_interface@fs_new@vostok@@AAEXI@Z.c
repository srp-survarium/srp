void __thiscall vostok::fs_new::asynchronous_device_interface::set_synchronous_thread_id(
        vostok::fs_new::asynchronous_device_interface *this,
        unsigned int thread_id)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_synchronous_thread_id = thread_id;
}
