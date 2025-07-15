void __stdcall vostok::sound::voice_bridge::OnVoiceError(
        vostok::sound::voice_bridge *this,
        void *pBufferContext,
        HRESULT Error)
{
  vostok::sound::sound_voice::on_voice_error(this->m_handler, pBufferContext, Error);
}
