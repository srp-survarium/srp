void __stdcall vostok::sound::voice_bridge::OnBufferStart(vostok::sound::voice_bridge *this, void *pBufferContext)
{
  this->m_source_voice->GetVolume(this->m_source_voice, (float *)&this);
}
