float *__cdecl floor0_inverse1(vorbis_block *vb, _DWORD *i)
{
  int v3; // edi
  signed int v4; // eax
  unsigned int v5; // eax
  signed int v6; // eax
  codebook *v7; // edi
  int v8; // ecx
  int v9; // eax
  float v10; // xmm0_4
  int v11; // edx
  float *v12; // ecx
  float *result; // eax
  float v14; // [esp+Ch] [ebp-8h]
  float *v15; // [esp+1Ch] [ebp+8h]
  oggpack_buffer *p_opb; // [esp+20h] [ebp+Ch]

  v3 = i[5];
  p_opb = &vb->opb;
  v4 = oggpack_read(&vb->opb, *(_DWORD *)(v3 + 12));
  if ( v4 <= 0 )
    return 0;
  v14 = (float)((float)v4 / (float)((1 << *(_DWORD *)(v3 + 12)) - 1)) * (float)*(int *)(v3 + 16);
  v5 = _ilog(*(_DWORD *)(v3 + 20));
  v6 = oggpack_read(&vb->opb, v5);
  if ( v6 == -1 )
    return 0;
  if ( v6 >= *(_DWORD *)(v3 + 20) )
    return 0;
  v7 = (codebook *)(*((_DWORD *)vb->vd->vi->codec_setup + 712) + 56 * *(_DWORD *)(v3 + 4 * v6 + 24));
  v15 = (float *)_vorbis_block_alloc(vb, 4 * (v7->dim + i[1]) + 4);
  if ( vorbis_book_decodev_set(v7, i[1], v15, p_opb) == -1 )
    return 0;
  v8 = i[1];
  v9 = 0;
  if ( v8 > 0 )
  {
    v10 = 0.0;
    do
    {
      v11 = 0;
      if ( v9 < v8 )
      {
        do
        {
          if ( v11 >= v7->dim )
            break;
          v12 = &v15[v9];
          ++v11;
          ++v9;
          *v12 = *v12 + v10;
        }
        while ( v9 < i[1] );
      }
      v10 = v15[v9 - 1];
      v8 = i[1];
    }
    while ( v9 < v8 );
  }
  result = v15;
  v15[i[1]] = v14;
  return result;
}
