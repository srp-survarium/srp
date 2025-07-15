void __cdecl vorbis_dsp_clear(vorbis_dsp_state *v)
{
  vorbis_info *vi; // eax
  _DWORD *codec_setup; // edi
  char *backend_state; // ebx
  mdct_lookup **v4; // eax
  mdct_lookup **v5; // eax
  int v6; // esi
  int v7; // esi
  void *v8; // edx
  int v9; // esi
  void **v10; // eax
  void *v11; // [esp-4h] [ebp-20h]
  vorbis_info *v12; // [esp+10h] [ebp-Ch]
  int v13; // [esp+14h] [ebp-8h]
  _DWORD *v14; // [esp+18h] [ebp-4h]
  _DWORD *v15; // [esp+18h] [ebp-4h]
  int v16; // [esp+18h] [ebp-4h]

  if ( v )
  {
    vi = v->vi;
    v12 = vi;
    if ( vi )
      codec_setup = vi->codec_setup;
    else
      codec_setup = 0;
    backend_state = (char *)v->backend_state;
    if ( backend_state )
    {
      if ( *(_DWORD *)backend_state )
      {
        _ve_envelope_clear(*(envelope_lookup **)backend_state);
        ogg_free_impl(*(void **)backend_state);
      }
      v4 = (mdct_lookup **)*((_DWORD *)backend_state + 3);
      if ( v4 )
      {
        mdct_clear(*v4);
        ogg_free_impl(**((void ***)backend_state + 3));
        ogg_free_impl(*((void **)backend_state + 3));
      }
      v5 = (mdct_lookup **)*((_DWORD *)backend_state + 4);
      if ( v5 )
      {
        mdct_clear(*v5);
        ogg_free_impl(**((void ***)backend_state + 4));
        ogg_free_impl(*((void **)backend_state + 4));
      }
      v6 = 0;
      if ( *((_DWORD *)backend_state + 12) )
      {
        if ( codec_setup && (int)codec_setup[4] > 0 )
        {
          v14 = codec_setup + 200;
          do
            _floor_P[*v14++]->free_look(*(void **)(*((_DWORD *)backend_state + 12) + 4 * v6++));
          while ( v6 < codec_setup[4] );
        }
        ogg_free_impl(*((void **)backend_state + 12));
      }
      v7 = 0;
      if ( *((_DWORD *)backend_state + 13) )
      {
        if ( codec_setup && (int)codec_setup[5] > 0 )
        {
          v15 = codec_setup + 328;
          do
            _residue_P[*v15++]->free_look(*(void **)(*((_DWORD *)backend_state + 13) + 4 * v7++));
          while ( v7 < codec_setup[5] );
        }
        ogg_free_impl(*((void **)backend_state + 13));
      }
      if ( *((_DWORD *)backend_state + 14) )
      {
        if ( codec_setup )
        {
          v13 = 0;
          if ( (int)codec_setup[7] > 0 )
          {
            v16 = 0;
            do
            {
              _vp_psy_clear((vorbis_look_psy *)(v16 + *((_DWORD *)backend_state + 14)));
              ++v13;
              v16 += 52;
            }
            while ( v13 < codec_setup[7] );
          }
        }
        ogg_free_impl(*((void **)backend_state + 14));
      }
      v8 = (void *)*((_DWORD *)backend_state + 15);
      if ( v8 )
      {
        v11 = (void *)*((_DWORD *)backend_state + 15);
        memset(v8, 0, 0x24u);
        ogg_free_impl(v11);
      }
      memset((int)(backend_state + 80), 0, 0x30u);
      drft_clear((drft_lookup *)(backend_state + 20));
      drft_clear((drft_lookup *)(backend_state + 32));
      vi = v12;
    }
    v9 = 0;
    if ( v->pcm )
    {
      if ( vi && v12->channels > 0 )
      {
        do
        {
          v10 = (void **)&v->pcm[v9];
          if ( *v10 )
            ogg_free_impl(*v10);
          ++v9;
        }
        while ( v9 < v12->channels );
      }
      ogg_free_impl(v->pcm);
      if ( v->pcmret )
        ogg_free_impl(v->pcmret);
    }
    if ( backend_state )
    {
      if ( *((_DWORD *)backend_state + 16) )
        ogg_free_impl(*((void **)backend_state + 16));
      if ( *((_DWORD *)backend_state + 17) )
        ogg_free_impl(*((void **)backend_state + 17));
      if ( *((_DWORD *)backend_state + 18) )
        ogg_free_impl(*((void **)backend_state + 18));
      ogg_free_impl(backend_state);
    }
    memset((int)v, 0, sizeof(vorbis_dsp_state));
  }
}
