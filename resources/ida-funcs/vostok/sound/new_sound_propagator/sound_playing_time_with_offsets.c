unsigned int __thiscall vostok::sound::new_sound_propagator::sound_playing_time_with_offsets(
        vostok::sound::new_sound_propagator *this)
{
  unsigned int offset; // [esp+4h] [ebp-4h]

  if ( this->m_propagation_time < this->m_time_to_listener )
    return -1;
  offset = this->m_propagation_time - this->m_time_to_listener;
  if ( this->m_mode )
    return (this->m_playing_offset + offset) % this->m_sound_length_with_offsets;
  else
    return this->m_playing_offset + offset;
}
