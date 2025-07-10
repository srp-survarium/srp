void __thiscall vostok::fs_new::open_file_device_query::callback_if_needed(
        vostok::fs_new::open_file_device_query *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  boost::function1<void,vostok::ai::sensors::sensed_object const &>::operator()(
    (boost::function1<void,vostok::ai::sensors::sensed_object const &> *)&this->m_callback,
    (const vostok::ai::sensors::sensed_object *)this->m_result_file);
}
