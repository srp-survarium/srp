void __thiscall vostok::network::enqueue_order::execute(vostok::network::enqueue_order *this)
{
  survarium::game_camera *v1; // ecx

  boost::function1<void,vostok::ai::sensors::sensed_object const &>::operator()(
    (boost::function1<void,vostok::ai::sensors::sensed_object const &> *)&this->m_enqueuer,
    (const vostok::ai::sensors::sensed_object *)this->m_packet);
  survarium::weapon_user_dead_state::finalize(v1);
  qmemcpy(&this->m_copied_stats, this->m_source_stats, sizeof(this->m_copied_stats));
}
