unsigned int __thiscall vostok::sound::new_sound_propagator::sound_playing_time(
        vostok::sound::new_sound_propagator *this)
{
  unsigned int offset; // [esp+8h] [ebp-4h]

  offset = vostok::sound::new_sound_propagator::sound_playing_time_with_offsets(this);
  if ( offset == -1 )
    return -1;
  if ( offset >= this->m_before_playing_offsets && offset <= this->m_sound_length + this->m_before_playing_offsets )
    return offset - this->m_before_playing_offsets;
  return -1;
}
