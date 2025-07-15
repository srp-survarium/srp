void __thiscall vostok::sound::new_sound_propagator::pause_propagation(vostok::sound::new_sound_propagator *this)
{
  if ( this->m_propagation_state == propagating )
  {
    this->m_propagation_state = propagating_paused;
    vostok::sound::new_sound_propagator::detach_voices(this, 4u);
  }
}
