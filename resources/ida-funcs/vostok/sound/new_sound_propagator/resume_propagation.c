void __thiscall vostok::sound::new_sound_propagator::resume_propagation(vostok::sound::new_sound_propagator *this)
{
  if ( this->m_propagation_state == propagating_paused )
    this->m_propagation_state = propagating;
}
