void __cdecl vorbis_info_clear(vorbis_info *vi)
{
  char *codec_setup; // ebx
  int v2; // edi
  void **v3; // esi
  int v4; // edi
  void **v5; // esi
  int v6; // edi
  void **v7; // esi
  int v8; // edi
  void **v9; // esi
  static_codebook **v10; // edi
  int v11; // eax
  void **v12; // esi
  void *v13; // edi
  int v14; // [esp+8h] [ebp-8h]
  int v15; // [esp+Ch] [ebp-4h]
  int v16; // [esp+Ch] [ebp-4h]

  codec_setup = (char *)vi->codec_setup;
  v2 = 0;
  if ( codec_setup )
  {
    if ( *((int *)codec_setup + 2) > 0 )
    {
      v3 = (void **)(codec_setup + 32);
      do
      {
        if ( *v3 )
          ogg_free_impl(*v3);
        ++v2;
        ++v3;
      }
      while ( v2 < *((_DWORD *)codec_setup + 2) );
    }
    v4 = 0;
    if ( *((int *)codec_setup + 3) > 0 )
    {
      v5 = (void **)(codec_setup + 544);
      do
      {
        if ( *v5 )
          _mapping_P[(_DWORD)*(v5 - 64)]->free_info(*v5);
        ++v4;
        ++v5;
      }
      while ( v4 < *((_DWORD *)codec_setup + 3) );
    }
    v6 = 0;
    if ( *((int *)codec_setup + 4) > 0 )
    {
      v7 = (void **)(codec_setup + 1056);
      do
      {
        if ( *v7 )
          _floor_P[(_DWORD)*(v7 - 64)]->free_info(*v7);
        ++v6;
        ++v7;
      }
      while ( v6 < *((_DWORD *)codec_setup + 4) );
    }
    v8 = 0;
    if ( *((int *)codec_setup + 5) > 0 )
    {
      v9 = (void **)(codec_setup + 1568);
      do
      {
        if ( *v9 )
          _residue_P[(_DWORD)*(v9 - 64)]->free_info(*v9);
        ++v8;
        ++v9;
      }
      while ( v8 < *((_DWORD *)codec_setup + 5) );
    }
    v15 = 0;
    if ( *((int *)codec_setup + 6) > 0 )
    {
      v14 = 0;
      v10 = (static_codebook **)(codec_setup + 1824);
      do
      {
        if ( *v10 )
          vorbis_staticbook_destroy(*v10);
        v11 = *((_DWORD *)codec_setup + 712);
        if ( v11 )
          vorbis_book_clear((codebook *)(v14 + v11));
        ++v15;
        v14 += 56;
        ++v10;
      }
      while ( v15 < *((_DWORD *)codec_setup + 6) );
    }
    if ( *((_DWORD *)codec_setup + 712) )
      ogg_free_impl(*((void **)codec_setup + 712));
    v16 = 0;
    if ( *((int *)codec_setup + 7) > 0 )
    {
      v12 = (void **)(codec_setup + 2852);
      do
      {
        v13 = *v12;
        if ( *v12 )
        {
          memset((int)v13, 0, 0x208u);
          ogg_free_impl(v13);
        }
        ++v16;
        ++v12;
      }
      while ( v16 < *((_DWORD *)codec_setup + 7) );
    }
    ogg_free_impl(codec_setup);
  }
  memset(vi, 0, sizeof(vorbis_info));
}
