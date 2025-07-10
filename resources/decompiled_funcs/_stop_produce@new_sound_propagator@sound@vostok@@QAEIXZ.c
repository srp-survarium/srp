unsigned int __thiscall vostok::sound::new_sound_propagator::stop_produce(vostok::sound::new_sound_propagator *this)
{
  unsigned int producing_time; // [esp+4h] [ebp-4h]

  producing_time = this->m_playing_offset + this->m_propagation_time;
  this->m_end_propagation_time = this->m_time_to_listener + this->m_propagation_time;
  return producing_time;
}
