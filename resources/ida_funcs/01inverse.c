int __cdecl 01inverse(
        vorbis_block *vb,
        vorbis_info_residue0 **vl,
        float **in,
        int ch,
        int (__cdecl *decodepart)(codebook *, float *, oggpack_buffer *, int))
{
  vorbis_info_residue0 *v5; // edx
  int begin; // esi
  int end; // ecx
  int grouping; // edi
  int v9; // eax
  int v10; // eax
  int v11; // esi
  void *v12; // esp
  int v13; // edi
  int v14; // ecx
  bool v15; // cc
  int v16; // edx
  int v17; // eax
  int v18; // esi
  codebook *v19; // edi
  int v20; // eax
  int v21; // ecx
  int *v22; // ecx
  int ***v23; // edi
  int v24; // esi
  int v25; // ebx
  int v26; // ecx
  codebook *v27; // ecx
  _DWORD v29[3]; // [esp+0h] [ebp-38h] BYREF
  int partitions_per_word; // [esp+Ch] [ebp-2Ch]
  int j; // [esp+10h] [ebp-28h]
  int partvals; // [esp+14h] [ebp-24h]
  int v33; // [esp+18h] [ebp-20h]
  int samples_per_partition; // [esp+1Ch] [ebp-1Ch]
  int i; // [esp+20h] [ebp-18h]
  int k; // [esp+24h] [ebp-14h]
  vorbis_info_residue0 *info; // [esp+28h] [ebp-10h]
  int s; // [esp+2Ch] [ebp-Ch]
  unsigned int v39; // [esp+30h] [ebp-8h]
  int ***partword; // [esp+34h] [ebp-4h]

  v5 = *vl;
  begin = vl[4]->begin;
  end = (*vl)->end;
  grouping = (*vl)->grouping;
  v9 = vb->pcmend >> 1;
  info = *vl;
  samples_per_partition = grouping;
  partitions_per_word = begin;
  if ( end < v9 )
    v9 = end;
  v10 = v9 - v5->begin;
  if ( v10 > 0 )
  {
    partvals = v10 / grouping;
    v11 = (v10 / grouping + begin - 1) / begin;
    v12 = alloca(4 * ch);
    v13 = 0;
    for ( partword = (int ***)v29; v13 < ch; ++v13 )
      v29[v13] = _vorbis_block_alloc(vb, 4 * v11);
    v14 = 0;
    v15 = (int)vl[2] <= 0;
    s = 0;
    if ( !v15 )
    {
      v16 = partvals;
      while ( 1 )
      {
        v17 = 0;
        i = 0;
        if ( v16 > 0 )
          break;
LABEL_32:
        v15 = ++v14 < (int)vl[2];
        s = v14;
        if ( !v15 )
          return 0;
      }
      v39 = 0;
      while ( 1 )
      {
        if ( !v14 )
        {
          v18 = 0;
          if ( ch > 0 )
            break;
        }
LABEL_19:
        k = 0;
        if ( partitions_per_word <= 0 )
        {
LABEL_30:
          v16 = partvals;
        }
        else
        {
          v33 = samples_per_partition * v17;
          while ( 1 )
          {
            v16 = partvals;
            if ( v17 >= partvals )
              break;
            j = 0;
            if ( ch > 0 )
            {
              v23 = partword;
              v24 = 1 << v14;
              v25 = (char *)in - (char *)partword;
              while ( 1 )
              {
                v26 = (*v23)[v39 / 4][k];
                if ( (v24 & info->secondstages[v26]) != 0 )
                {
                  v27 = *(codebook **)(*(&vl[5]->begin + v26) + 4 * s);
                  if ( v27 )
                  {
                    if ( decodepart(
                           v27,
                           (float *)&(&(*(int ***)((char *)v23 + v25))[v33])[info->begin],
                           &vb->opb,
                           samples_per_partition) == -1 )
                      return 0;
                  }
                }
                ++v23;
                if ( ++j >= ch )
                {
                  v17 = i;
                  v14 = s;
                  break;
                }
              }
            }
            v33 += samples_per_partition;
            ++v17;
            v15 = ++k < partitions_per_word;
            i = v17;
            if ( !v15 )
              goto LABEL_30;
          }
        }
        v39 += 4;
        if ( v17 >= v16 )
          goto LABEL_32;
      }
      while ( 1 )
      {
        v19 = (codebook *)vl[4];
        if ( v19->used_entries <= 0 )
          break;
        v20 = decode_packed_entry_number(v19, &vb->opb);
        if ( v20 < 0 )
          break;
        v21 = v19->dec_index[v20];
        if ( v21 == -1 )
          break;
        if ( v21 >= info->partvals )
          break;
        v22 = (int *)*(&vl[7]->begin + v21);
        partword[v18][v39 / 4] = v22;
        if ( !v22 )
          break;
        if ( ++v18 >= ch )
        {
          v17 = i;
          v14 = s;
          goto LABEL_19;
        }
      }
    }
  }
  return 0;
}
