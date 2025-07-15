unsigned int *__cdecl floor0_unpack(vorbis_info *vi, oggpack_buffer *opb)
{
  _DWORD *codec_setup; // ebx
  unsigned int *v3; // edi
  signed int v4; // eax
  bool v5; // cc
  signed int v6; // eax
  int *v7; // eax
  int v9; // [esp+Ch] [ebp-4h]
  signed int *i; // [esp+18h] [ebp+8h]

  codec_setup = vi->codec_setup;
  v3 = (unsigned int *)ogg_malloc_impl(0x60u);
  *v3 = oggpack_read(opb, 8u);
  v3[1] = oggpack_read(opb, 0x10u);
  v3[2] = oggpack_read(opb, 0x10u);
  v3[3] = oggpack_read(opb, 6u);
  v3[4] = oggpack_read(opb, 8u);
  v4 = oggpack_read(opb, 4u) + 1;
  v5 = (int)*v3 < 1;
  v3[5] = v4;
  if ( !v5 && (int)v3[1] >= 1 && (int)v3[2] >= 1 && v4 >= 1 )
  {
    v9 = 0;
    for ( i = (signed int *)(v3 + 6); ; ++i )
    {
      v6 = oggpack_read(opb, 8u);
      *i = v6;
      if ( v6 < 0 )
        break;
      if ( v6 >= codec_setup[6] )
        break;
      v7 = (int *)codec_setup[v6 + 456];
      if ( !v7[3] || *v7 < 1 )
        break;
      if ( ++v9 >= (int)v3[5] )
        return v3;
    }
  }
  floor0_free_info((unsigned __int8 *)v3);
  return 0;
}
