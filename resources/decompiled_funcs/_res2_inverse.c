int __cdecl res2_inverse(vorbis_block *vb, _DWORD **vl, float **in, int *nonzero, int ch)
{
  _DWORD *v5; // ebp
  int v6; // eax
  int v7; // eax
  int v8; // ebx
  int j; // eax
  _DWORD **v10; // esi
  codebook *v11; // edi
  int v12; // eax
  int v13; // eax
  int *v14; // eax
  int v15; // ebx
  int v16; // edi
  int v17; // eax
  codebook *v18; // eax
  int i; // [esp+10h] [ebp-1Ch]
  int s; // [esp+14h] [ebp-18h]
  int **v22; // [esp+18h] [ebp-14h]
  int partvals; // [esp+1Ch] [ebp-10h]
  int partitions_per_word; // [esp+20h] [ebp-Ch]
  int **partword; // [esp+24h] [ebp-8h]
  int samples_per_partition; // [esp+28h] [ebp-4h]

  v5 = *vl;
  v6 = (ch * vb->pcmend) >> 1;
  samples_per_partition = (*vl)[2];
  partitions_per_word = *vl[4];
  if ( (*vl)[1] < v6 )
    v6 = (*vl)[1];
  v7 = v6 - *v5;
  if ( v7 > 0 )
  {
    v8 = v7 / (*vl)[2];
    partvals = v8;
    partword = (int **)_vorbis_block_alloc(vb, 4 * ((v8 + *vl[4] - 1) / *vl[4]));
    for ( j = 0; j < ch; ++j )
    {
      if ( nonzero[j] )
        break;
    }
    if ( j != ch )
    {
      v10 = vl;
      s = 0;
      if ( (int)vl[2] > 0 )
      {
        while ( 1 )
        {
          i = 0;
          if ( v8 > 0 )
            break;
LABEL_26:
          if ( ++s >= (int)v10[2] )
            return 0;
        }
        v22 = partword;
        while ( 1 )
        {
          if ( !s )
          {
            v11 = (codebook *)v10[4];
            if ( v11->used_entries <= 0 )
              break;
            v12 = decode_packed_entry_number(v11, &vb->opb);
            if ( v12 < 0 )
              break;
            v13 = v11->dec_index[v12];
            if ( v13 == -1 )
              break;
            if ( v13 >= v5[4] )
              break;
            v14 = (int *)v10[7][v13];
            *v22 = v14;
            if ( !v14 )
              break;
          }
          v15 = 0;
          if ( partitions_per_word > 0 )
          {
            v16 = samples_per_partition * i;
            while ( i < partvals )
            {
              v17 = (*v22)[v15];
              if ( ((1 << s) & v5[v17 + 6]) != 0 )
              {
                v18 = *(codebook **)(vl[5][v17] + 4 * s);
                if ( v18 )
                {
                  if ( vorbis_book_decodevv_add(v18, in, v16 + *v5, ch, &vb->opb, samples_per_partition) == -1 )
                    return 0;
                }
              }
              ++i;
              ++v15;
              v16 += samples_per_partition;
              if ( v15 >= partitions_per_word )
                break;
            }
          }
          ++v22;
          v10 = vl;
          if ( i >= partvals )
          {
            v8 = partvals;
            goto LABEL_26;
          }
        }
      }
    }
  }
  return 0;
}
