void __thiscall vostok::sound::new_sound_propagator::stop_propagation(vostok::sound::new_sound_propagator *this)
{
  this->m_propagation_state = propagating_finished;
  vostok::sound::new_sound_propagator::detach_voices(this, 4u);
}
