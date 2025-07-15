void __thiscall vostok::fs_new::synchronize_device_query::on_synchronized_ended(
        vostok::fs_new::synchronize_device_query *this)
{
  vostok::threading::event *v1; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::fs_new::asynchronous_device_interface::set_synchronous_thread_id(this->m_device, 0xFFFFFFFF);
  vostok::threading::event::set(v1, (HANDLE *)&this->m_synchronization_ended_event, 1);
}
