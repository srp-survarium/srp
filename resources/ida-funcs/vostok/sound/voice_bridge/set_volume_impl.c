void __userpurge vostok::sound::voice_bridge::set_volume_impl(
        vostok::sound::voice_bridge *this@<eax>,
        float a2@<xmm1>,
        bool force)
{
  float v3; // xmm0_4
  unsigned int v4; // [esp+4h] [ebp-4h]
  float v5; // [esp+10h] [ebp+8h]

  if ( force || fabs(this->m_volume - a2) >= 0.0000099999997 )
  {
    v3 = 0.0;
    if ( a2 <= 0.0 || (v3 = s_bm_current_air_resistance, s_bm_current_air_resistance < a2) )
      v5 = v3;
    else
      v5 = a2;
    v4 = vostok::sound::voice_bridge::operation_set;
    this->m_volume = v5;
    ((void (__stdcall *)(IXAudio2SourceVoice *, _DWORD, unsigned int))this->m_source_voice->SetVolume)(
      this->m_source_voice,
      LODWORD(v5),
      v4);
  }
}
