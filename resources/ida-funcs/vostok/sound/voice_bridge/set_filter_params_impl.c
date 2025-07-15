int __userpurge vostok::sound::voice_bridge::set_filter_params_impl@<eax>(
        vostok::sound::voice_bridge *this@<ecx>,
        int result@<eax>,
        int a3@<edx>,
        float a4@<xmm0>,
        enum XAUDIO2_FILTER_TYPE force,
        float a6,
        bool a7)
{
  _DWORD *v7; // ecx
  int v8; // eax

  if ( *(_BYTE *)(result + 9)
    && ((_BYTE)force || fabs(*(float *)(result + 28) - a4) >= 0.0000099999997 || *(_DWORD *)(result + 24) != a3) )
  {
    v7 = (_DWORD *)(result + 24);
    *(float *)(result + 28) = a4;
    v8 = *(_DWORD *)(result + 16);
    *v7 = a3;
    return (*(int (__stdcall **)(int, _DWORD *, _DWORD))(*(_DWORD *)v8 + 32))(v8, v7, 0);
  }
  return result;
}
