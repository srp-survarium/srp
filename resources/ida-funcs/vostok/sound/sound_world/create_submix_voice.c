IXAudio2SubmixVoice *__usercall vostok::sound::sound_world::create_submix_voice@<eax>(
        vostok::sound::sound_world *this@<ecx>,
        int a2@<eax>)
{
  int v3; // [esp+4h] [ebp-4h] BYREF

  if ( !*(_BYTE *)(a2 + 18649) )
    return 0;
  (*(void (__stdcall **)(_DWORD, int *, int, int, _DWORD, int, _DWORD, _DWORD))(**(_DWORD **)(a2 + 192) + 36))(
    *(_DWORD *)(a2 + 192),
    &v3,
    2,
    44100,
    0,
    2,
    0,
    0);
  (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)v3 + 4))(v3, 0);
  return (IXAudio2SubmixVoice *)v3;
}
