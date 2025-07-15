void __thiscall vostok::sound::new_sound_propagator::attach_voices(
        vostok::sound::new_sound_propagator *this,
        unsigned int count,
        const vostok::vectora<vostok::sound::sound_voice_params> *voices_params)
{
  unsigned int offset; // [esp+10h] [ebp-4h]

  if ( this->m_voice )
  {
    vostok::sound::sound_voice::set_output_matrix(this->m_voice, voices_params->_M_impl._M_start->channel_matrix);
  }
  else
  {
    offset = vostok::sound::new_sound_propagator::sound_playing_time(this);
    if ( offset != -1 )
    {
      this->m_voice = vostok::sound::new_sound_propagator::attach_voice(this, offset);
      vostok::sound::sound_voice::set_output_matrix(this->m_voice, voices_params->_M_impl._M_start->channel_matrix);
      vostok::sound::sound_voice::play(this->m_voice, this->m_mode);
    }
  }
}
