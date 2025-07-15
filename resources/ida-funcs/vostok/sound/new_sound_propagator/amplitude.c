double __thiscall vostok::sound::new_sound_propagator::amplitude(vostok::sound::new_sound_propagator *this)
{
  vostok::sound::new_sound_propagator *m_master_propagator; // ecx

  m_master_propagator = this->m_master_propagator;
  if ( m_master_propagator )
    return (float)vostok::sound::new_sound_propagator::amplitude(m_master_propagator);
  else
    return this->m_out_amplitude_value;
}
