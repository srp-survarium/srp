int **__usercall 2class@<eax>(vorbis_block *vb@<eax>, _DWORD *vl, int **in, int ch)
{
  _DWORD *v5; // edi
  int v6; // ebx
  char *v7; // eax
  char *v8; // esi
  signed int v9; // eax
  int j; // ecx
  __int64 v11; // rax
  int v12; // eax
  int v13; // ecx
  _DWORD *v14; // eax
  int v16; // [esp+Ch] [ebp-20h]
  char *v17; // [esp+10h] [ebp-1Ch]
  int v18; // [esp+10h] [ebp-1Ch]
  int v19; // [esp+14h] [ebp-18h]
  int v20; // [esp+14h] [ebp-18h]
  int v21; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  int v23; // [esp+20h] [ebp-Ch]
  signed int v24; // [esp+24h] [ebp-8h]
  int v25; // [esp+28h] [ebp-4h]

  v5 = (_DWORD *)*vl;
  v19 = *(_DWORD *)(*vl + 12);
  v21 = *(_DWORD *)(*vl + 8);
  v6 = (v5[1] - *v5) / v21;
  v16 = v6;
  v17 = _vorbis_block_alloc(vb, 4);
  v6 *= 4;
  v7 = _vorbis_block_alloc(vb, v6);
  v8 = v17;
  *(_DWORD *)v17 = v7;
  memset((int)v7, 0, v6);
  v18 = 0;
  v25 = *v5 / ch;
  if ( v16 > 0 )
  {
    v20 = v19 - 1;
    do
    {
      v24 = 0;
      v23 = 0;
      for ( i = 0; i < v21; i += ch )
      {
        v9 = abs32((*in)[v25]);
        if ( v9 > v24 )
          v24 = v9;
        for ( j = 1; j < ch; ++j )
        {
          v11 = in[j][v25];
          v12 = (HIDWORD(v11) ^ v11) - HIDWORD(v11);
          if ( v12 > v23 )
            v23 = v12;
        }
        ++v25;
      }
      v13 = 0;
      if ( v20 > 0 )
      {
        v14 = v5 + 646;
        do
        {
          if ( v24 <= *(v14 - 64) && v23 <= *v14 )
            break;
          ++v13;
          ++v14;
        }
        while ( v13 < v20 );
      }
      *(_DWORD *)(*(_DWORD *)v8 + 4 * v18++) = v13;
    }
    while ( v18 < v16 );
  }
  ++vl[10];
  return (int **)v8;
}
