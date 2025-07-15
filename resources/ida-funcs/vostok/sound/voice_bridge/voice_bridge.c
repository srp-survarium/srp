void __userpurge vostok::sound::voice_bridge::voice_bridge(
        vostok::sound::voice_bridge *this@<ecx>,
        int a2@<esi>,
        vostok::sound::voice_bridge::creation_parametrs *params,
        const unsigned int id)
{
  bool v4; // zf
  float v5; // xmm0_4
  _DWORD v6[5]; // [esp+38h] [ebp-20h] BYREF
  _BYTE v7[12]; // [esp+4Ch] [ebp-Ch] BYREF

  *(_DWORD *)a2 = &vostok::sound::voice_bridge::`vftable';
  *(vostok::sound::voice_bridge::creation_parametrs *)(a2 + 4) = *params;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  *(_DWORD *)(a2 + 36) = id;
  params->world->m_master_voice->GetVoiceDetails(params->world->m_master_voice, (XAUDIO2_VOICE_DETAILS *)v7);
  *(_BYTE *)(a2 + 40) = v7[4];
  *(float *)(a2 + 44) = FLOAT_N1_0;
  *(_DWORD *)(a2 + 48) = 0;
  *(_DWORD *)(a2 + 52) = 0;
  *(_DWORD *)(a2 + 56) = 0;
  *(_DWORD *)(a2 + 60) = 0;
  memset((char *)v6 + 2, 0, 12);
  *(_DWORD *)((char *)&v6[3] + 2) = 16;
  LOWORD(v6[0]) = 1;
  HIWORD(v6[0]) = params->channels_num;
  v6[1] = 44100;
  LOWORD(v6[3]) = 2 * HIWORD(v6[0]);
  v4 = !params->enable_filter;
  v6[2] = 44100 * (unsigned __int16)(2 * HIWORD(v6[0]));
  ((void (__stdcall *)(IXAudio2 *, int, _DWORD *, int, _DWORD, int, _DWORD, _DWORD))params->world->m_xaudio->CreateSourceVoice)(
    params->world->m_xaudio,
    a2 + 16,
    v6,
    2 * !v4 + 6,
    2.0,
    a2,
    0,
    0);
  (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(a2 + 16) + 48))(*(_DWORD *)(a2 + 16), 0.0, 0);
  v5 = s_bm_current_air_resistance;
  *(_DWORD *)(a2 + 24) = 0;
  *(float *)(a2 + 32) = v5;
  *(float *)(a2 + 28) = v5;
}
