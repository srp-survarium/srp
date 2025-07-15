unsigned __int8 *__cdecl mapping0_unpack(vorbis_info *vi, oggpack_buffer *opb)
{
  unsigned __int8 *v2; // edi
  signed int v3; // eax
  signed int v4; // eax
  signed int v6; // eax
  signed int v7; // eax
  int channels; // ecx
  unsigned int v9; // eax
  unsigned int i; // ecx
  signed int v11; // ebx
  int v12; // ecx
  unsigned int v13; // eax
  unsigned int j; // ecx
  signed int v15; // eax
  int v16; // ecx
  signed int *v17; // ebx
  signed int v18; // eax
  signed int *k; // ebx
  signed int v20; // eax
  signed int v21; // eax
  _DWORD *codec_setup; // [esp+Ch] [ebp-Ch]
  signed int *v23; // [esp+10h] [ebp-8h]
  int v24; // [esp+14h] [ebp-4h]
  int v25; // [esp+14h] [ebp-4h]
  int v26; // [esp+14h] [ebp-4h]

  v2 = ogg_calloc_impl(1u, 0xC88u);
  codec_setup = vi->codec_setup;
  memset((int)v2, 0, 0xC88u);
  v3 = oggpack_read(opb, 1u);
  if ( v3 < 0 )
    goto err_out_3;
  if ( v3 )
  {
    v4 = oggpack_read(opb, 4u) + 1;
    *(_DWORD *)v2 = v4;
    if ( v4 <= 0 )
      goto err_out_3;
  }
  else
  {
    *(_DWORD *)v2 = 1;
  }
  v6 = oggpack_read(opb, 1u);
  if ( v6 < 0 )
    goto err_out_3;
  if ( v6 )
  {
    v7 = oggpack_read(opb, 8u) + 1;
    *((_DWORD *)v2 + 289) = v7;
    if ( v7 > 0 )
    {
      v24 = 0;
      v23 = (signed int *)(v2 + 2184);
      while ( 1 )
      {
        channels = vi->channels;
        v9 = 0;
        if ( channels )
        {
          for ( i = channels - 1; i; i >>= 1 )
            ++v9;
        }
        v11 = oggpack_read(opb, v9);
        *(v23 - 256) = v11;
        v12 = vi->channels;
        v13 = 0;
        if ( v12 )
        {
          for ( j = v12 - 1; j; j >>= 1 )
            ++v13;
        }
        v15 = oggpack_read(opb, v13);
        *v23 = v15;
        if ( v11 < 0 )
          break;
        if ( v15 < 0 )
          break;
        if ( v11 == v15 )
          break;
        v16 = vi->channels;
        if ( v11 >= v16 || v15 >= v16 )
          break;
        ++v24;
        ++v23;
        if ( v24 >= *((_DWORD *)v2 + 289) )
          goto LABEL_22;
      }
    }
    goto err_out_3;
  }
LABEL_22:
  if ( oggpack_read(opb, 2u) )
  {
err_out_3:
    mapping0_free_info(v2);
    return 0;
  }
  if ( *(int *)v2 > 1 )
  {
    v25 = 0;
    if ( vi->channels > 0 )
    {
      v17 = (signed int *)(v2 + 4);
      do
      {
        v18 = oggpack_read(opb, 4u);
        *v17 = v18;
        if ( v18 >= *(_DWORD *)v2 || v18 < 0 )
          goto err_out_3;
        ++v25;
        ++v17;
      }
      while ( v25 < vi->channels );
    }
  }
  v26 = 0;
  if ( *(int *)v2 > 0 )
  {
    for ( k = (signed int *)(v2 + 1092); ; ++k )
    {
      oggpack_read(opb, 8u);
      v20 = oggpack_read(opb, 8u);
      *(k - 16) = v20;
      if ( v20 >= codec_setup[4] )
        break;
      if ( v20 < 0 )
        break;
      v21 = oggpack_read(opb, 8u);
      *k = v21;
      if ( v21 >= codec_setup[5] || v21 < 0 )
        break;
      if ( ++v26 >= *(_DWORD *)v2 )
        return v2;
    }
    goto err_out_3;
  }
  return v2;
}
