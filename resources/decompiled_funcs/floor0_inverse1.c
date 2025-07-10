float *__cdecl floor0_inverse1(vorbis_block *vb, _DWORD *i)
{
  _DWORD *v3; // ebp
  oggpack_buffer *p_opb; // edi
  unsigned int v6; // ecx
  unsigned int v7; // eax
  signed int v8; // eax
  int v9; // ebp
  vostok::memory::doug_lea_mt_allocator *v10; // ecx
  codebook *v11; // ebp
  float *v12; // esi
  int v13; // edx
  int j; // eax
  int v15; // ecx
  double v16; // st6
  float amp; // [esp+14h] [ebp+4h]
  signed int last; // [esp+18h] [ebp+8h]
  float lasta; // [esp+18h] [ebp+8h]

  v3 = (_DWORD *)i[5];
  p_opb = &vb->opb;
  last = oggpack_read(&vb->opb, v3[3]);
  if ( last <= 0 )
    return 0;
  v6 = v3[5];
  v7 = 0;
  for ( amp = (double)last / (double)((1 << v3[3]) - 1) * (double)(int)v3[4]; v6; v6 >>= 1 )
    ++v7;
  v8 = oggpack_read(p_opb, v7);
  if ( v8 == -1 )
    return 0;
  if ( v8 >= v3[5] )
    return 0;
  v9 = v3[v8 + 6];
  lasta = 0.0;
  v10 = (vostok::memory::doug_lea_mt_allocator *)(7 * v9);
  v11 = (codebook *)(*((_DWORD *)vb->vd->vi->codec_setup + 712) + 56 * v9);
  v12 = (float *)_vorbis_block_alloc(vb, 4 * (i[1] + v11->dim) + 4, v10);
  if ( vorbis_book_decodev_set(v11, v12, p_opb, i[1]) == -1 )
    return 0;
  v13 = i[1];
  for ( j = 0; j < v13; lasta = v12[j - 1] )
  {
    v15 = 0;
    if ( j < v13 )
    {
      do
      {
        if ( v15 >= v11->dim )
          break;
        v16 = v12[j++];
        ++v15;
        v12[j - 1] = v16 + lasta;
      }
      while ( j < i[1] );
    }
    v13 = i[1];
  }
  v12[i[1]] = amp;
  return v12;
}
