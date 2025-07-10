void __thiscall vostok::sound::voice_bridge::submit_source_buff(
        vostok::sound::voice_bridge *this,
        vostok::sound::sound_buffer *buffer)
{
  this->m_source_voice->SubmitSourceBuffer(this->m_source_voice, &buffer->m_xaudio_buffer, 0);
}
