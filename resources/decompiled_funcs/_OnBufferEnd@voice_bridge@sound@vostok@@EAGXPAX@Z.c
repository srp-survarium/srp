void __stdcall vostok::sound::voice_bridge::OnBufferEnd(vostok::sound::voice_bridge *this, void *pBufferContext)
{
  vostok::sound::sound_voice::on_buffer_end(this->m_handler, pBufferContext);
}
