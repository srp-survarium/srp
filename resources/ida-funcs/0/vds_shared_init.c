int __usercall vds_shared_init@<eax>(__int128 a1@<xmm0>, vorbis_dsp_state *v, vorbis_info *vi)
{
  _DWORD *codec_setup; // ebx
  vorbis_dsp_state *v5; // esi
  unsigned __int8 *v6; // edi
  int v7; // ecx
  int v8; // eax
  unsigned int i; // ecx
  int v10; // ecx
  unsigned int v11; // eax
  int v12; // eax
  int v13; // ecx
  unsigned int j; // eax
  unsigned __int8 *v15; // eax
  bool v16; // cc
  int v17; // eax
  void **v18; // eax
  static_codebook **v19; // edi
  void *v20; // eax
  void **v21; // edx
  void **v22; // eax
  void *v23; // eax
  char *v24; // ecx
  int v25; // [esp+10h] [ebp-10h]
  int v26; // [esp+10h] [ebp-10h]
  int v27; // [esp+10h] [ebp-10h]
  int v28; // [esp+10h] [ebp-10h]
  static_codebook **v29; // [esp+14h] [ebp-Ch]
  void **k; // [esp+14h] [ebp-Ch]
  void **m; // [esp+14h] [ebp-Ch]
  int v32; // [esp+18h] [ebp-8h]
  int v33; // [esp+18h] [ebp-8h]
  int v34; // [esp+18h] [ebp-8h]

  codec_setup = vi->codec_setup;
  if ( !codec_setup )
    return 1;
  v5 = v;
  v32 = codec_setup[914];
  memset((int)v, 0, sizeof(vorbis_dsp_state));
  v6 = ogg_calloc_impl(1u, 0x88u);
  v->vi = vi;
  v->backend_state = v6;
  v7 = codec_setup[2];
  v8 = 0;
  if ( v7 )
  {
    for ( i = v7 - 1; i; i >>= 1 )
      ++v8;
  }
  *((_DWORD *)v6 + 11) = v8;
  *((_DWORD *)v6 + 3) = ogg_calloc_impl(1u, 4u);
  *((_DWORD *)v6 + 4) = ogg_calloc_impl(1u, 4u);
  **((_DWORD **)v6 + 3) = ogg_calloc_impl(1u, 0x14u);
  **((_DWORD **)v6 + 4) = ogg_calloc_impl(1u, 0x14u);
  mdct_init((int)*codec_setup >> v32, **((mdct_lookup ***)v6 + 3));
  mdct_init((int)codec_setup[1] >> v32, **((mdct_lookup ***)v6 + 4));
  v10 = 0;
  if ( *codec_setup )
  {
    v11 = *codec_setup - 1;
    if ( *codec_setup != 1 )
    {
      do
      {
        ++v10;
        v11 >>= 1;
      }
      while ( v11 );
    }
  }
  *((_DWORD *)v6 + 1) = v10 - 6;
  v12 = codec_setup[1];
  v13 = 0;
  if ( v12 )
  {
    for ( j = v12 - 1; j; j >>= 1 )
      ++v13;
  }
  *((_DWORD *)v6 + 2) = v13 - 6;
  if ( codec_setup[712]
    || (v15 = ogg_calloc_impl(codec_setup[6], 0x38u), v25 = 0, v16 = codec_setup[6] <= 0, codec_setup[712] = v15, v16) )
  {
LABEL_18:
    v5->pcm_storage = codec_setup[1];
    v5->pcm = (float **)ogg_malloc_impl(4 * vi->channels);
    v34 = 0;
    for ( v5->pcmret = (float **)ogg_malloc_impl(4 * vi->channels); v34 < vi->channels; ++v34 )
      v5->pcm[v34] = (float *)ogg_calloc_impl(v5->pcm_storage, 4u);
    v5->lW = 0;
    v5->W = 0;
    v17 = codec_setup[1] / 2;
    v5->centerW = v17;
    v5->pcm_current = v17;
    *((_DWORD *)v6 + 12) = ogg_calloc_impl(codec_setup[4], 4u);
    v26 = 0;
    *((_DWORD *)v6 + 13) = ogg_calloc_impl(codec_setup[5], 4u);
    if ( (int)codec_setup[4] > 0 )
    {
      v18 = (void **)(codec_setup + 264);
      for ( k = (void **)(codec_setup + 264); ; v18 = k )
      {
        v20 = _floor_P[(_DWORD)*(v18 - 64)]->look(v5, *v18);
        v21 = k++;
        ++v26;
        *(void **)((char *)v21 + *((_DWORD *)v6 + 12) - (_DWORD)codec_setup - 1056) = v20;
        if ( v26 >= codec_setup[4] )
          break;
      }
    }
    v28 = 0;
    if ( (int)codec_setup[5] > 0 )
    {
      v22 = (void **)(codec_setup + 392);
      for ( m = (void **)(codec_setup + 392); ; v22 = m )
      {
        v23 = _residue_P[(_DWORD)*(v22 - 64)]->look(v5, *v22);
        v24 = (char *)m + *((_DWORD *)v6 + 13);
        ++v28;
        ++m;
        *(_DWORD *)&v24[-1568 - (_DWORD)codec_setup] = v23;
        if ( v28 >= codec_setup[5] )
          break;
      }
    }
    return 0;
  }
  else
  {
    v33 = 0;
    v29 = (static_codebook **)(codec_setup + 456);
    while ( *v29 && !vorbis_book_init_decode((codebook *)(v33 + codec_setup[712]), *v29, a1) )
    {
      vorbis_staticbook_destroy(*v29);
      *v29 = 0;
      ++v25;
      ++v29;
      v33 += 56;
      v5 = v;
      if ( v25 >= codec_setup[6] )
        goto LABEL_18;
    }
    v27 = 0;
    if ( (int)codec_setup[6] > 0 )
    {
      v19 = (static_codebook **)(codec_setup + 456);
      do
      {
        if ( *v19 )
        {
          vorbis_staticbook_destroy(*v19);
          *v19 = 0;
          v5 = v;
        }
        ++v27;
        ++v19;
      }
      while ( v27 < codec_setup[6] );
    }
    vorbis_dsp_clear(v5);
    return -1;
  }
}
