int __cdecl 01forward(oggpack_buffer *opb, vorbis_block *vb, int **vl, int **in, int **ch)
{
  int v5; // ebp
  int v6; // ebx
  int v7; // edi
  int v8; // eax
  int *v9; // eax
  int v10; // esi
  int *v11; // ecx
  int v12; // eax
  _DWORD *v13; // ecx
  unsigned __int8 *ptr; // ebx
  int v15; // eax
  int v16; // esi
  int v17; // eax
  char *v18; // ebx
  int v19; // edx
  int **v20; // esi
  int v21; // eax
  codebook *v22; // eax
  int v23; // eax
  int *v24; // ecx
  bool v25; // cc
  int s; // [esp+10h] [ebp-428h]
  int j; // [esp+14h] [ebp-424h]
  int **ja; // [esp+14h] [ebp-424h]
  int samples_per_partition; // [esp+18h] [ebp-420h]
  int partvals; // [esp+1Ch] [ebp-41Ch]
  int k; // [esp+20h] [ebp-418h]
  float **info; // [esp+24h] [ebp-414h]
  int v34; // [esp+28h] [ebp-410h]
  int v35; // [esp+2Ch] [ebp-40Ch]
  int partitions_per_word; // [esp+30h] [ebp-408h]
  int possible_partitions; // [esp+34h] [ebp-404h]
  int resvals[128]; // [esp+38h] [ebp-400h] BYREF
  int resbits[128]; // [esp+238h] [ebp-200h] BYREF

  v5 = *(_DWORD *)vb->opb.ptr;
  possible_partitions = *((_DWORD *)vb->pcm + 3);
  info = vb->pcm;
  samples_per_partition = *((_DWORD *)vb->pcm + 2);
  partitions_per_word = v5;
  v6 = (signed int)(*((_DWORD *)vb->pcm + 1) - (unsigned int)*vb->pcm) / samples_per_partition;
  partvals = v6;
  memset((int)resbits, 0, sizeof(resbits));
  memset((int)resvals, 0, sizeof(resvals));
  for ( s = 0; s < vb->opb.endbit; ++s )
  {
    v7 = 0;
    if ( v6 > 0 )
    {
      while ( 1 )
      {
        if ( !s )
        {
          v8 = 0;
          for ( j = 0; j < (int)in; ++j )
          {
            v9 = ch[v8];
            v10 = v9[v7];
            v11 = &v9[v7];
            v12 = 1;
            if ( v5 > 1 )
            {
              v13 = v11 + 1;
              do
              {
                v10 *= possible_partitions;
                if ( v12 + v7 < v6 )
                  v10 += *v13;
                ++v12;
                ++v13;
              }
              while ( v12 < v5 );
            }
            ptr = vb->opb.ptr;
            if ( v10 < *((_DWORD *)ptr + 1) )
            {
              if ( v10 < 0 || (v15 = *((_DWORD *)ptr + 3), v10 >= *(_DWORD *)(v15 + 4)) )
              {
                v16 = 0;
              }
              else
              {
                oggpack_write(
                  opb,
                  *(_DWORD *)(*((_DWORD *)ptr + 5) + 4 * v10),
                  *(_DWORD *)(*(_DWORD *)(v15 + 8) + 4 * v10));
                v16 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)ptr + 3) + 8) + 4 * v10);
              }
              vb->pcmend += v16;
            }
            v6 = partvals;
            v8 = j + 1;
          }
        }
        k = 0;
        if ( v5 > 0 )
          break;
LABEL_30:
        if ( v7 >= v6 )
          goto LABEL_31;
      }
      v17 = samples_per_partition * v7;
      v34 = samples_per_partition * v7;
      while ( v7 < v6 )
      {
        v18 = (char *)*info + v17;
        v19 = __ROL4__(1, s);
        v35 = v19;
        if ( (int)in > 0 )
        {
          v20 = ch;
          ja = in;
          do
          {
            if ( !s )
              resvals[(*v20)[v7]] += samples_per_partition;
            v21 = (*v20)[v7];
            if ( (v19 & (unsigned int)info[v21 + 6]) != 0 )
            {
              v22 = *(codebook **)(*(_DWORD *)(vb->opb.storage + 4 * v21) + 4 * s);
              if ( v22 )
              {
                v23 = encodepart(
                        opb,
                        &(*(int **)((char *)v20 + (char *)vl - (char *)ch))[(_DWORD)v18],
                        samples_per_partition,
                        v22,
                        0);
                vb->nW += v23;
                v19 = v35;
                v24 = &resbits[(*v20)[v7]];
                *v24 += v23;
              }
            }
            ++v20;
            ja = (int **)((char *)ja - 1);
          }
          while ( ja );
          v5 = partitions_per_word;
          v17 = v34;
        }
        v17 += samples_per_partition;
        v6 = partvals;
        ++v7;
        v25 = ++k < v5;
        v34 = v17;
        if ( !v25 )
          goto LABEL_30;
      }
    }
LABEL_31:
    ;
  }
  return 0;
}
