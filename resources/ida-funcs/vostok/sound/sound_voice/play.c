void __thiscall vostok::sound::sound_voice::play(vostok::sound::sound_voice *this, vostok::sound::playback_mode mode)
{
  this->m_mode = mode;
  if ( this->m_mode )
  {
    if ( this->m_mode == looped )
    {
      if ( this->m_playing_offset >= (signed int)this->m_before_playing_quiet )
      {
        if ( this->m_playing_offset >= this->m_current_sound_quality.m_object->m_length_in_msec
                                     + this->m_before_playing_quiet )
        {
          vostok::sound::sound_voice::submit_muted_buffers(
            this,
            LODWORD(this->m_current_sound_quality.m_object->m_length_in_msec)
          + this->m_after_playing_quiet
          + 2 * this->m_before_playing_quiet
          - this->m_playing_offset);
        }
        else
        {
          this->m_playing_offset -= this->m_before_playing_quiet;
          this->m_stream_cursor_pcm = vostok::sound::sound_voice::find_nearest_adjective_pcm_offset(this);
        }
      }
      else
      {
        vostok::sound::sound_voice::submit_muted_buffers(this, this->m_before_playing_quiet - this->m_playing_offset);
      }
    }
  }
  else if ( this->m_playing_offset <= 10 )
  {
    this->m_stream_cursor_pcm = 0;
  }
  else
  {
    this->m_stream_cursor_pcm = vostok::sound::sound_voice::find_nearest_adjective_pcm_offset(this);
  }
  this->m_is_playing = 1;
  vostok::sound::sound_voice::refill_buffers(this);
  vostok::sound::voice_bridge::start(this->m_voice);
}
