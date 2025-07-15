void __stdcall vostok::sound::voice_bridge::OnBufferStart(vostok::sound::voice_bridge *this, void *pBufferContext)
{
  vostok::sound::sound_voice::on_buffer_start(this->m_handler, pBufferContext);
}
