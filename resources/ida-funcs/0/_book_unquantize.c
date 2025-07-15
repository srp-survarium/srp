float *__usercall _book_unquantize@<eax>(
        const static_codebook *b@<esi>,
        int a2@<edi>,
        __int128 a3@<xmm0>,
        int n,
        int *sparsemap)
{
  int maptype; // eax
  int v6; // ebx
  int j; // edx
  int v9; // eax
  float v10; // xmm1_4
  int k; // ecx
  int dim; // ecx
  float v13; // xmm1_4
  int v14; // edi
  int v15; // [esp+8h] [ebp-18h]
  float v16; // [esp+Ch] [ebp-14h]
  float v17; // [esp+10h] [ebp-10h]
  unsigned __int8 *v18; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  int v20; // [esp+1Ch] [ebp-4h]

  maptype = b->maptype;
  v6 = 0;
  v20 = 0;
  if ( maptype != 1 && maptype != 2 )
    return 0;
  v16 = _float32_unpack(b->q_min);
  v17 = _float32_unpack(b->q_delta);
  v18 = ogg_calloc_impl(n * b->dim, 4u);
  if ( b->maptype == 1 )
  {
    v15 = _book_maptype1_quantvals(b, 0, a2, (int)b, a3);
    for ( i = 0; i < b->entries; ++i )
    {
      if ( !sparsemap || b->lengthlist[i] )
      {
        dim = b->dim;
        v13 = 0.0;
        v14 = 1;
        if ( b->dim > 0 )
        {
          do
          {
            *(double *)&a3 = (float)b->quantlist[i / v14 % v15];
            a3 = (__int128)_mm_and_pd((__m128d)a3, (__m128d)(unsigned __int64)_mask__AbsDouble_);
            *(float *)&a3 = *(double *)&a3 * v17 + v13 + v16;
            if ( b->q_sequencep )
              v13 = *(float *)&a3;
            if ( sparsemap )
              *(_DWORD *)&v18[4 * v6 + 4 * dim * sparsemap[v20]] = a3;
            else
              *(_DWORD *)&v18[4 * v6 + 4 * v20 * dim] = a3;
            v14 *= v15;
            dim = b->dim;
            ++v6;
          }
          while ( v6 < b->dim );
        }
        ++v20;
        v6 = 0;
      }
    }
  }
  else if ( b->maptype == 2 )
  {
    for ( j = 0; j < b->entries; ++j )
    {
      if ( !sparsemap || b->lengthlist[j] )
      {
        v9 = b->dim;
        v10 = 0.0;
        for ( k = 0; k < b->dim; ++k )
        {
          *(double *)&a3 = (float)b->quantlist[k + j * v9];
          a3 = (__int128)_mm_and_pd((__m128d)a3, (__m128d)(unsigned __int64)_mask__AbsDouble_);
          *(float *)&a3 = *(double *)&a3 * v17 + v10 + v16;
          if ( b->q_sequencep )
            v10 = *(float *)&a3;
          if ( sparsemap )
            *(_DWORD *)&v18[4 * k + 4 * v9 * sparsemap[v20]] = a3;
          else
            *(_DWORD *)&v18[4 * k + 4 * v20 * v9] = a3;
          v9 = b->dim;
        }
        ++v20;
      }
    }
  }
  return (float *)v18;
}
