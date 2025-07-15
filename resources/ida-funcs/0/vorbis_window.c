const float *__cdecl vorbis_window(vorbis_dsp_state *v, int W)
{
  int v2; // eax

  v2 = *((_DWORD *)v->backend_state + W + 1);
  if ( v2 - 1 >= 0 )
    return vwin[v2 - *((_DWORD *)v->vi->codec_setup + 914)];
  else
    return 0;
}
