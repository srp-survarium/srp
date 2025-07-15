void __thiscall vostok::sound::sound_voice::start_impl(vostok::sound::sound_voice *this, int a2)
{
  int v2; // esi
  unsigned int v3; // edi
  unsigned int v4; // eax
  vostok::sound::voice_bridge *v5; // esi
  IXAudio2SubmixVoice *m_output_voice; // eax
  IXAudio2SourceVoice *m_source_voice; // eax
  char v8[4]; // [esp+10h] [ebp-1Ch] BYREF
  int v9; // [esp+14h] [ebp-18h]
  _DWORD v10[2]; // [esp+18h] [ebp-14h] BYREF
  _DWORD v11[3]; // [esp+20h] [ebp-Ch] BYREF

  (*(void (__stdcall **)(_DWORD, char *))(**(_DWORD **)(*(_DWORD *)(a2 + 20) + 16) + 100))(
    *(_DWORD *)(*(_DWORD *)(a2 + 20) + 16),
    v8);
  if ( v9 )
    (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 20) + 16) + 88))(*(_DWORD *)(*(_DWORD *)(a2 + 20) + 16));
  v2 = *(_DWORD *)(a2 + 32);
  v3 = ((unsigned int)&loc_15887 + 1) / *(_DWORD *)(v2 + 284);
  v4 = *(_DWORD *)(v2 + 280)
     * (*(_DWORD *)(*(_DWORD *)(a2 + 24) + 32) - *(_DWORD *)(*(_DWORD *)(a2 + 24) + 28))
     / 0x3E8u;
  *(_BYTE *)(a2 + 8) = 1;
  *(_DWORD *)(a2 + 28) = v3 * (v4 / v3);
  vostok::sound::sound_voice::refill_buffers((vostok::sound::sound_voice *)0x3E8, a2);
  v5 = *(vostok::sound::voice_bridge **)(a2 + 20);
  m_output_voice = v5->m_output_voice;
  v11[0] = 0;
  v11[1] = m_output_voice;
  v10[1] = v11;
  m_source_voice = v5->m_source_voice;
  v10[0] = 1;
  m_source_voice->SetOutputVoices(m_source_voice, (const XAUDIO2_VOICE_SENDS *)v10);
  vostok::sound::voice_bridge::set_volume_impl(v5, v5->m_volume, 1);
  vostok::sound::voice_bridge::set_output_matrix_impl(v5, v5->m_output_level_matrix, 1);
  if ( v5->m_params.enable_filter )
    v5->m_source_voice->SetFilterParameters(v5->m_source_voice, &v5->m_flter_params, 0);
  (*(void (__stdcall **)(_DWORD, _DWORD, unsigned int))(**(_DWORD **)(*(_DWORD *)(a2 + 20) + 16) + 76))(
    *(_DWORD *)(*(_DWORD *)(a2 + 20) + 16),
    0,
    vostok::sound::voice_bridge::operation_set);
}
