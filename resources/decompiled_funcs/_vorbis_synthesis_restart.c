int __cdecl vorbis_synthesis_restart(vorbis_dsp_state *v)
{
  vorbis_info *vi; // ecx
  _DWORD *backend_state; // edi
  _DWORD *codec_setup; // edx
  int v5; // esi
  int v6; // edx

  vi = v->vi;
  backend_state = v->backend_state;
  if ( !backend_state )
    return -1;
  if ( !vi )
    return -1;
  codec_setup = vi->codec_setup;
  if ( !codec_setup )
    return -1;
  v5 = codec_setup[914];
  v6 = (int)codec_setup[1] >> (v5 + 1);
  v->eofflag = 0;
  v->centerW = v6;
  v->pcm_returned = -1;
  LODWORD(v->granulepos) = -1;
  v->pcm_current = v6 >> v5;
  HIDWORD(v->granulepos) = -1;
  v->sequence = -1;
  backend_state[32] = -1;
  backend_state[33] = -1;
  return 0;
}
