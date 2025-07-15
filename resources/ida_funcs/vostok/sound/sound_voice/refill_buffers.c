void __thiscall vostok::sound::sound_voice::refill_buffers(vostok::sound::sound_voice *this)
{
  vostok::sound::sound_buffer *buffer; // [esp+20h] [ebp-Ch]
  unsigned __int64 pcm_total; // [esp+24h] [ebp-8h]

  pcm_total = this->m_current_sound_quality.m_object->m_length_in_pcm;
  while ( this->m_buffers_queued < 3 && this->m_stream_cursor_pcm < pcm_total )
  {
    buffer = vostok::sound::sound_world::get_sound_buffer(
               this->m_world_user->m_owner_world,
               &this->m_current_sound_quality,
               this->m_stream_cursor_pcm,
               &this->m_stream_cursor_pcm);
    vostok::sound::voice_bridge::submit_source_buff(this->m_voice, buffer);
    if ( this->m_mode == looped && pcm_total == this->m_stream_cursor_pcm )
    {
      vostok::sound::sound_voice::submit_muted_buffers(this, this->m_after_playing_quiet + this->m_before_playing_quiet);
      this->m_stream_cursor_pcm = 0;
    }
    _InterlockedExchangeAdd(&this->m_buffers_queued, 1u);
  }
}
