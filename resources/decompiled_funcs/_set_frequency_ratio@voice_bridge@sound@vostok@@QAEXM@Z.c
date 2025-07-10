void __thiscall vostok::sound::voice_bridge::set_frequency_ratio(vostok::sound::voice_bridge *this, float ratio)
{
  ((void (__stdcall *)(IXAudio2SourceVoice *, _DWORD, _DWORD))this->m_source_voice->SetFrequencyRatio)(
    this->m_source_voice,
    LODWORD(ratio),
    0);
}
