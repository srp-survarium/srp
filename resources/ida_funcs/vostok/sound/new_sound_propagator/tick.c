void __thiscall vostok::sound::new_sound_propagator::tick(
        vostok::sound::new_sound_propagator *this,
        unsigned int time_delta_in_msec)
{
  if ( this->m_propagation_state == propagating )
  {
    this->m_propagation_time += time_delta_in_msec;
    if ( this->m_propagation_time > this->m_end_propagation_time )
    {
      vostok::sound::new_sound_propagator::stop_propagation(this);
      if ( this->m_is_callback_executer )
        vostok::sound::new_sound_propagator::execute_callback(this);
    }
  }
}
