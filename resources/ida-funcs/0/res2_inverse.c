int __cdecl res2_inverse(vorbis_block *vb, int **vl, float **in, int *nonzero, int ch)
{
  _DWORD *v6; // edi
  int v7; // eax
  int v8; // eax
  int i; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  codebook *v14; // esi
  char *v16; // [esp+Ch] [ebp-20h]
  int v17; // [esp+10h] [ebp-1Ch]
  int v18; // [esp+14h] [ebp-18h]
  int v19; // [esp+18h] [ebp-14h]
  int v20; // [esp+1Ch] [ebp-10h]
  _DWORD *v21; // [esp+20h] [ebp-Ch]
  int v22; // [esp+24h] [ebp-8h]
  int v23; // [esp+28h] [ebp-4h]
  int v24; // [esp+38h] [ebp+Ch]

  v6 = *vl;
  v22 = (*vl)[2];
  v7 = (ch * vb->pcmend) >> 1;
  if ( (*vl)[1] < v7 )
    v7 = (*vl)[1];
  v8 = v7 - *v6;
  v17 = *vl[4];
  if ( v8 > 0 )
  {
    v19 = v8 / v22;
    v16 = _vorbis_block_alloc(vb, 4 * ((v8 / v22 + *vl[4] - 1) / *vl[4]));
    for ( i = 0; i < ch; ++i )
    {
      if ( nonzero[i] )
        break;
    }
    if ( i != ch )
    {
      v23 = 0;
      if ( (int)vl[2] > 0 )
      {
        while ( 1 )
        {
          v24 = 0;
          if ( v19 > 0 )
            break;
LABEL_23:
          if ( ++v23 >= (int)vl[2] )
            return 0;
        }
        v21 = v16;
        while ( 1 )
        {
          if ( !v23 )
          {
            v10 = vorbis_book_decode((codebook *)vl[4], &vb->opb);
            if ( v10 == -1 )
              break;
            if ( v10 >= v6[4] )
              break;
            v11 = vl[7][v10];
            *v21 = v11;
            if ( !v11 )
              break;
          }
          v12 = 0;
          v18 = 0;
          if ( v17 > 0 )
          {
            v20 = v22 * v24;
            while ( v24 < v19 )
            {
              v13 = *(_DWORD *)(*v21 + 4 * v12);
              if ( ((1 << v23) & v6[v13 + 6]) != 0 )
              {
                v14 = *(codebook **)(vl[5][v13] + 4 * v23);
                if ( v14 )
                {
                  if ( vorbis_book_decodevv_add(v14, v20 + *v6, in, ch, &vb->opb, v22) == -1 )
                    return 0;
                }
              }
              v20 += v22;
              v12 = v18 + 1;
              ++v24;
              if ( ++v18 >= v17 )
                break;
            }
          }
          ++v21;
          if ( v24 >= v19 )
            goto LABEL_23;
        }
      }
    }
  }
  return 0;
}
