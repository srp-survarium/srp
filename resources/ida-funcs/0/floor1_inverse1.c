char *__cdecl floor1_inverse1(vorbis_block *vb, _DWORD *in)
{
  int *v2; // edi
  char *v3; // ebx
  unsigned int v4; // eax
  unsigned int v5; // eax
  int v6; // eax
  int v7; // ecx
  int v8; // edx
  int v9; // eax
  int v10; // esi
  int v11; // eax
  _DWORD *v13; // esi
  int v14; // eax
  int v15; // ecx
  int v16; // edx
  int v17; // edx
  char v18; // [esp+Ch] [ebp-2Ch]
  int v19; // [esp+10h] [ebp-28h]
  int v20; // [esp+14h] [ebp-24h]
  int v21; // [esp+18h] [ebp-20h]
  int v22; // [esp+18h] [ebp-20h]
  int *v23; // [esp+1Ch] [ebp-1Ch]
  int v24; // [esp+20h] [ebp-18h]
  int *v25; // [esp+20h] [ebp-18h]
  int v26; // [esp+24h] [ebp-14h]
  int v27; // [esp+28h] [ebp-10h]
  int v28; // [esp+28h] [ebp-10h]
  int v29; // [esp+2Ch] [ebp-Ch]
  int *v30; // [esp+2Ch] [ebp-Ch]
  oggpack_buffer *b; // [esp+30h] [ebp-8h]
  int v32; // [esp+34h] [ebp-4h]
  int v33; // [esp+40h] [ebp+8h]
  int v34; // [esp+40h] [ebp+8h]

  v2 = (int *)in[324];
  v21 = *((_DWORD *)vb->vd->vi->codec_setup + 712);
  b = &vb->opb;
  if ( oggpack_read(&vb->opb, 1u) != 1 )
    return 0;
  v3 = _vorbis_block_alloc(vb, 4 * in[321]);
  v4 = _ilog(in[323] - 1);
  *(_DWORD *)v3 = oggpack_read(b, v4);
  v5 = _ilog(in[323] - 1);
  v33 = 0;
  *((_DWORD *)v3 + 1) = oggpack_read(b, v5);
  v24 = 2;
  if ( *v2 > 0 )
  {
    v23 = v2 + 1;
    do
    {
      v6 = *v23;
      v32 = 0;
      v26 = v2[*v23 + 32];
      v7 = v2[*v23 + 48];
      v8 = 1 << v7;
      v27 = *v23;
      v18 = v7;
      v29 = 1 << v7;
      if ( v7 )
      {
        v32 = vorbis_book_decode((codebook *)(v21 + 56 * v2[v6 + 64]), b);
        if ( v32 == -1 )
          return 0;
        v6 = v27;
        v8 = v29;
      }
      v28 = 0;
      if ( v26 > 0 )
      {
        v19 = 8 * v6 + 80;
        v20 = v8 - 1;
        v30 = (int *)&v3[4 * v24];
        do
        {
          v9 = v19 + (v32 & v20);
          v32 >>= v18;
          v10 = v2[v9];
          if ( v10 < 0 )
          {
            *v30 = 0;
          }
          else
          {
            v11 = vorbis_book_decode((codebook *)(v21 + 56 * v10), b);
            *v30 = v11;
            if ( v11 == -1 )
              return 0;
          }
          ++v28;
          ++v30;
        }
        while ( v28 < v26 );
      }
      v24 += v26;
      ++v33;
      ++v23;
    }
    while ( v33 < *v2 );
  }
  v34 = 2;
  if ( (int)in[321] > 2 )
  {
    v13 = in + 195;
    v25 = v2 + 211;
    do
    {
      v14 = render_point(*(_DWORD *)&v3[4 * *v13], *v25, v2[v13[63] + 209], v2[*v13 + 209], *(_DWORD *)&v3[4 * v13[63]]);
      v15 = in[323] - v14;
      v22 = v15;
      if ( v15 >= v14 )
        v22 = v14;
      v16 = *(_DWORD *)&v3[4 * v34];
      if ( v16 )
      {
        if ( v16 < 2 * v22 )
        {
          if ( (v16 & 1) != 0 )
            v17 = -((v16 + 1) >> 1);
          else
            v17 = v16 >> 1;
        }
        else if ( v15 <= v14 )
        {
          v17 = v15 - v16 - 1;
        }
        else
        {
          v17 = v16 - v14;
        }
        *(_DWORD *)&v3[4 * v34] = (v14 + v17) & 0x7FFF;
        *(_DWORD *)&v3[4 * v13[63]] &= 0x7FFFu;
        *(_DWORD *)&v3[4 * *v13] &= 0x7FFFu;
      }
      else
      {
        *(_DWORD *)&v3[4 * v34] = v14 | 0x8000;
      }
      ++v34;
      ++v25;
      ++v13;
    }
    while ( v34 < in[321] );
  }
  return v3;
}
