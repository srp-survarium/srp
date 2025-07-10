const vostok::sound::sound_emitter *__thiscall vostok::sound::sound_collection::get_sound(
        vostok::sound::sound_collection *this)
{
  unsigned int m_previously_played_sound_index; // [esp+34h] [ebp-Ch]
  unsigned int sound_index; // [esp+38h] [ebp-8h]
  unsigned int sounds_size; // [esp+3Ch] [ebp-4h]

  if ( this->m_sounds.m_begin == this->m_sounds.m_end )
    return 0;
  if ( this->m_type == collection_playback_type_sequential )
  {
    m_previously_played_sound_index = this->m_previously_played_sound_index;
    this->m_previously_played_sound_index = m_previously_played_sound_index + 1;
    return this->m_sounds.m_begin[(m_previously_played_sound_index + 1)
                                % (this->m_sounds.m_end - this->m_sounds.m_begin)].m_object;
  }
  else
  {
    sounds_size = this->m_sounds.m_end - this->m_sounds.m_begin;
    do
    {
      this->m_random_number.m_seed = 134775813 * this->m_random_number.m_seed + 1;
      sound_index = (sounds_size * (unsigned __int64)this->m_random_number.m_seed) >> 32;
    }
    while ( sound_index == this->m_previously_played_sound_index && !this->m_can_repeat_successively && sounds_size != 1 );
    this->m_previously_played_sound_index = sound_index;
    return this->m_sounds.m_begin[sound_index].m_object;
  }
}
