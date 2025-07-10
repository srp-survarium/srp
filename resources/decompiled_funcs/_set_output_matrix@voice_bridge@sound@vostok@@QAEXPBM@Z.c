void __thiscall vostok::sound::voice_bridge::set_output_matrix(
        vostok::sound::voice_bridge *this,
        const float *level_matrix)
{
  XAUDIO2_VOICE_DETAILS voice_details; // [esp+4h] [ebp-Ch] BYREF

  ((void (__thiscall *)(IXAudio2SourceVoice *, IXAudio2SourceVoice *, XAUDIO2_VOICE_DETAILS *))this->m_source_voice->GetVoiceDetails)(
    this->m_source_voice,
    this->m_source_voice,
    &voice_details);
  this->m_source_voice->SetOutputMatrix(
    this->m_source_voice,
    0,
    voice_details.InputChannels,
    this->m_master_channels_num,
    level_matrix,
    0);
}
