void __thiscall vostok::sound::voice_bridge::voice_bridge(
        vostok::sound::voice_bridge *this,
        vostok::sound::voice_bridge::creation_parametrs *params)
{
  tWAVEFORMATEX wfx_standard; // [esp+1Ch] [ebp-18h] BYREF

  this->__vftable = (vostok::sound::voice_bridge_vtbl *)&vostok::sound::voice_bridge::`vftable';
  this->m_next = 0;
  this->m_handler = 0;
  this->m_source_voice = 0;
  this->m_master_channels_num = params->master_channels_num;
  wfx_standard.nChannels = 0;
  LOWORD(wfx_standard.nAvgBytesPerSec) = 0;
  *(unsigned int *)((char *)&wfx_standard.nAvgBytesPerSec + 2) = 0;
  wfx_standard.wFormatTag = 1;
  wfx_standard.nSamplesPerSec = 44100;
  wfx_standard.wBitsPerSample = 16;
  wfx_standard.cbSize = 0;
  wfx_standard.nChannels = params->channels_num;
  wfx_standard.nBlockAlign = 2 * wfx_standard.nChannels;
  wfx_standard.nAvgBytesPerSec = 44100 * (unsigned __int16)(2 * wfx_standard.nChannels);
  this->m_sample_rate = 44100;
  this->m_channels_num = params->channels_num;
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))params->xaudio_engine->CreateSourceVoice)(
    params->xaudio_engine,
    &this->m_source_voice,
    &wfx_standard,
    6u,
    params->max_frequency_ratio,
    this,
    0,
    0);
}
