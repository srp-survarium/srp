int **__usercall 2class@<eax>(vorbis_block *vb@<eax>, _DWORD *vl, int **in, int ch)
{
  _DWORD *v5; // ebp
  int v6; // ebx
  int v7; // edi
  int *v8; // eax
  int v9; // esi
  int v10; // edx
  int v11; // edi
  signed int v12; // ebx
  signed int v13; // eax
  int k; // ecx
  __int64 v15; // rax
  int v16; // eax
  int v17; // eax
  _DWORD *v18; // ecx
  int magmax; // [esp+10h] [ebp-20h]
  int **partword; // [esp+14h] [ebp-1Ch]
  int j; // [esp+18h] [ebp-18h]
  int samples_per_partition; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]
  int partvals; // [esp+24h] [ebp-Ch]
  int v26; // [esp+2Ch] [ebp-4h]

  v5 = (_DWORD *)*vl;
  v6 = *(_DWORD *)(*vl + 12);
  samples_per_partition = *(_DWORD *)(*vl + 8);
  v7 = (*(_DWORD *)(*vl + 4) - *(_DWORD *)*vl) / samples_per_partition;
  partvals = v7;
  partword = (int **)_vorbis_block_alloc(vb, 4);
  v7 *= 4;
  v8 = (int *)_vorbis_block_alloc(vb, v7);
  *partword = v8;
  memset((int)v8, 0, v7);
  i = 0;
  v9 = *v5 / ch;
  if ( partvals > 0 )
  {
    v10 = v6 - 1;
    v26 = v6 - 1;
    do
    {
      v11 = 0;
      v12 = 0;
      magmax = 0;
      j = 0;
      if ( samples_per_partition > 0 )
      {
        do
        {
          v13 = abs32((*in)[v9]);
          if ( v13 > v12 )
            magmax = v13;
          for ( k = 1; k < ch; ++k )
          {
            v15 = in[k][v9];
            v16 = (HIDWORD(v15) ^ v15) - HIDWORD(v15);
            if ( v16 > v11 )
              v11 = v16;
          }
          v12 = magmax;
          ++v9;
          j += ch;
        }
        while ( j < samples_per_partition );
        v10 = v26;
      }
      v17 = 0;
      if ( v10 > 0 )
      {
        v18 = v5 + 646;
        do
        {
          if ( v12 <= *(v18 - 64) && v11 <= *v18 )
            break;
          ++v17;
          ++v18;
        }
        while ( v17 < v10 );
      }
      (*partword)[i++] = v17;
    }
    while ( i < partvals );
  }
  ++vl[10];
  return partword;
}
