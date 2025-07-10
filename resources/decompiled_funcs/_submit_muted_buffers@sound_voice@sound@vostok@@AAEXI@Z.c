void __thiscall vostok::sound::sound_voice::submit_muted_buffers(vostok::sound::sound_voice *this, unsigned int msec)
{
  vostok::sound::sound_buffer *mute_buff; // [esp+28h] [ebp-20h]
  unsigned int i; // [esp+2Ch] [ebp-1Ch]
  unsigned int samples_per_sec; // [esp+30h] [ebp-18h]
  unsigned int mute_buffers_count; // [esp+34h] [ebp-14h]
  unsigned int buffer_length_in_msec; // [esp+3Ch] [ebp-Ch]
  unsigned int mute_buffer_playing_offset; // [esp+40h] [ebp-8h]
  unsigned int samples_in_buffer; // [esp+44h] [ebp-4h]

  if ( msec )
  {
    samples_per_sec = this->m_current_sound_quality.m_object->m_samples_per_sec;
    samples_in_buffer = 0xAC44 / this->m_current_sound_quality.m_object->m_bytes_per_sample;
    this->m_channels_num = this->m_current_sound_quality.m_object->m_channels_num;
    buffer_length_in_msec = 1000 * samples_in_buffer / samples_per_sec / this->m_channels_num;
    mute_buffers_count = msec / buffer_length_in_msec;
    if ( msec / buffer_length_in_msec )
      mute_buffer_playing_offset = mute_buffers_count * buffer_length_in_msec % msec;
    else
      mute_buffer_playing_offset = buffer_length_in_msec - msec;
    if ( mute_buffer_playing_offset )
      ++mute_buffers_count;
    for ( i = 0; i < mute_buffers_count; ++i )
    {
      mute_buff = vostok::sound::sound_world::get_mute_sound_buffer(
                    this->m_proxy->m_user->m_owner_world,
                    &this->m_current_sound_quality);
      vostok::sound::voice_bridge::submit_source_buff(this->m_voice, mute_buff);
      _InterlockedExchangeAdd(&this->m_buffers_queued, 1u);
    }
  }
}
