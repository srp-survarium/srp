void __thiscall vostok::sound::voice_bridge::OnVoiceError(
        vostok::sound::sound_voice *ecx0,
        vostok::sound::voice_bridge *this,
        void *pBufferContext,
        HRESULT Error)
{
  if ( this->m_handler_ )
    vostok::sound::sound_voice::on_voice_error(ecx0, pBufferContext, Error);
}
