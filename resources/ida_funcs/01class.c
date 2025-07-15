int **__usercall 01class@<eax>(vorbis_block *vb@<eax>, vorbis_info_residue0 **vl, int **in, int ch)
{
  vorbis_info_residue0 *v5; // ebp
  int v6; // ebx
  int v7; // edi
  int v8; // ebx
  int *v9; // eax
  int v10; // eax
  double v11; // st7
  int v12; // ecx
  int **v13; // ebp
  char *v14; // eax
  int v15; // esi
  int v16; // edi
  int v17; // ebx
  int *v18; // ecx
  signed int v19; // eax
  int v20; // ecx
  int *classmetric2; // edx
  int v22; // edx
  bool v23; // zf
  bool v24; // cc
  int **partword; // [esp+10h] [ebp-2Ch]
  int i; // [esp+14h] [ebp-28h]
  int samples_per_partition; // [esp+18h] [ebp-24h]
  int ent; // [esp+1Ch] [ebp-20h]
  float scalea; // [esp+20h] [ebp-1Ch]
  int scale; // [esp+20h] [ebp-1Ch]
  vorbis_info_residue0 *info; // [esp+24h] [ebp-18h]
  int v33; // [esp+28h] [ebp-14h]
  int v34; // [esp+2Ch] [ebp-10h]
  int offset; // [esp+30h] [ebp-Ch]
  int possible_partitions; // [esp+38h] [ebp-4h]

  v5 = *vl;
  possible_partitions = (*vl)->partitions;
  info = *vl;
  samples_per_partition = (*vl)->grouping;
  v6 = ((*vl)->end - (*vl)->begin) / samples_per_partition;
  v33 = v6;
  v7 = 0;
  partword = (int **)_vorbis_block_alloc(vb, 4 * ch);
  if ( ch > 0 )
  {
    v8 = 4 * v6;
    do
    {
      v9 = (int *)_vorbis_block_alloc(vb, v8);
      partword[v7] = v9;
      memset((int)v9, 0, v8);
      ++v7;
    }
    while ( v7 < ch );
    v6 = v33;
  }
  v10 = 0;
  i = 0;
  if ( v6 > 0 )
  {
    scalea = 100.0 / (double)samples_per_partition;
    v11 = scalea;
    v34 = 0;
    do
    {
      v12 = v10 + v5->begin;
      offset = v12;
      if ( ch > 0 )
      {
        v13 = partword;
        v14 = (char *)((char *)in - (char *)partword);
        scale = ch;
        while ( 1 )
        {
          v15 = samples_per_partition;
          v16 = 0;
          v17 = 0;
          ent = 0;
          if ( samples_per_partition > 0 )
          {
            v18 = &(*(int **)((char *)v13 + (_DWORD)v14))[v12];
            do
            {
              v19 = abs32(*v18);
              if ( v19 > v17 )
                v17 = v19;
              v16 += v19;
              ++v18;
              --v15;
            }
            while ( v15 );
            ent = v16;
          }
          v20 = 0;
          if ( possible_partitions - 1 > 0 )
          {
            classmetric2 = (int *)info->classmetric2;
            do
            {
              if ( v17 <= *(classmetric2 - 64) && (*classmetric2 < 0 || (int)((double)ent * v11) < *classmetric2) )
                break;
              ++v20;
              ++classmetric2;
            }
            while ( v20 < possible_partitions - 1 );
          }
          v22 = (int)*v13++;
          v23 = scale-- == 1;
          *(_DWORD *)(v22 + 4 * i) = v20;
          if ( v23 )
            break;
          v12 = offset;
          v14 = (char *)((char *)in - (char *)partword);
        }
        v5 = info;
        v6 = v33;
      }
      v10 = samples_per_partition + v34;
      v24 = ++i < v6;
      v34 += samples_per_partition;
    }
    while ( v24 );
  }
  vl[10] = (vorbis_info_residue0 *)((char *)vl[10] + 1);
  return partword;
}
