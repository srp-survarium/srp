void __thiscall vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(
        vostok::fs_new::synchronous_device_interface *this)
{
  if ( this->m_synchronize_query )
    vostok::fs_new::synchronize_device_query::on_synchronized_ended(this->m_synchronize_query);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
