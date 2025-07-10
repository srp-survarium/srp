void __stdcall vostok::sound::voice_bridge::OnLoopEnd(vostok::sound::voice_bridge *this, void *pBufferContext)
{
  vostok::sound::sound_voice::on_loop_end(this->m_handler, pBufferContext);
}
