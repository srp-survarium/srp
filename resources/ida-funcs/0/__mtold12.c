void __cdecl __mtold12(char *manptr, unsigned int manlen, _LDBL12 *ld12)
{
  int v3; // ecx
  unsigned int v4; // ebx
  unsigned int v5; // esi
  unsigned int v6; // edx
  unsigned int v7; // edi
  int v8; // ebx
  unsigned int v9; // ecx
  unsigned int v10; // ebx
  int v11; // esi
  unsigned int v12; // ecx
  unsigned int v13; // edi
  int v14; // ebx
  unsigned int v15; // edx
  unsigned int v16; // esi
  int v17; // edx
  unsigned int v18; // ecx
  unsigned int v19; // esi
  unsigned int v20; // edi
  int v21; // ecx
  __int16 v22; // [esp+Ch] [ebp-18h]
  int v23; // [esp+10h] [ebp-14h]
  int v24; // [esp+10h] [ebp-14h]
  unsigned int v25; // [esp+18h] [ebp-Ch]
  int v26; // [esp+1Ch] [ebp-8h]

  v22 = 16462;
  *(_DWORD *)ld12->ld12 = 0;
  *(_DWORD *)&ld12->ld12[4] = 0;
  for ( *(_DWORD *)&ld12->ld12[8] = 0; manlen; ++manptr )
  {
    v25 = *(_DWORD *)&ld12->ld12[4];
    v26 = *(_DWORD *)&ld12->ld12[8];
    v23 = 0;
    v3 = __SPAIR64__(*(_QWORD *)&ld12->ld12[4] >> 31, *(__int64 *)ld12->ld12 >> 31) >> 31;
    v4 = *(_DWORD *)ld12->ld12;
    v5 = 4 * *(_DWORD *)ld12->ld12;
    v6 = (2LL * *(_QWORD *)ld12->ld12) >> 31;
    v7 = 5 * *(_DWORD *)ld12->ld12;
    *(_DWORD *)ld12->ld12 = v5;
    *(_DWORD *)&ld12->ld12[4] = v6;
    *(_DWORD *)&ld12->ld12[8] = v3;
    if ( v7 < v5 || v7 < v4 )
      v23 = 1;
    v8 = 0;
    *(_DWORD *)ld12->ld12 = v7;
    if ( v23 )
    {
      if ( v6 + 1 < v6 || v6 == -1 )
        v8 = 1;
      *(_DWORD *)&ld12->ld12[4] = v6 + 1;
      if ( v8 )
        *(_DWORD *)&ld12->ld12[8] = v3 + 1;
    }
    v9 = *(_DWORD *)&ld12->ld12[4];
    v10 = v9 + v25;
    v11 = 0;
    if ( v9 + v25 < v9 || v10 < v25 )
      v11 = 1;
    *(_DWORD *)&ld12->ld12[4] = v10;
    if ( v11 )
      ++*(_DWORD *)&ld12->ld12[8];
    *(_DWORD *)&ld12->ld12[8] += v26;
    v24 = 0;
    v12 = 2 * v7;
    v13 = (v7 >> 31) | (2 * v10);
    v14 = (v10 >> 31) | (2 * *(_DWORD *)&ld12->ld12[8]);
    *(_DWORD *)ld12->ld12 = v12;
    *(_DWORD *)&ld12->ld12[4] = v13;
    *(_DWORD *)&ld12->ld12[8] = v14;
    v15 = *manptr;
    v16 = v12 + v15;
    if ( v12 + v15 < v12 || v16 < v15 )
      v24 = 1;
    *(_DWORD *)ld12->ld12 = v16;
    if ( v24 )
    {
      v17 = 0;
      if ( v13 + 1 < v13 || v13 == -1 )
        v17 = 1;
      *(_DWORD *)&ld12->ld12[4] = v13 + 1;
      if ( v17 )
        *(_DWORD *)&ld12->ld12[8] = v14 + 1;
    }
    --manlen;
  }
  while ( !*(_DWORD *)&ld12->ld12[8] )
  {
    v18 = *(_DWORD *)&ld12->ld12[4];
    *(_DWORD *)&ld12->ld12[8] = HIWORD(v18);
    v22 -= 16;
    *(_QWORD *)ld12->ld12 = __PAIR64__(v18, *(_DWORD *)ld12->ld12) << 16;
  }
  if ( (*(_DWORD *)&ld12->ld12[8] & 0x8000) == 0 )
  {
    do
    {
      v19 = *(_DWORD *)ld12->ld12;
      v20 = *(_DWORD *)&ld12->ld12[4];
      --v22;
      *(_DWORD *)ld12->ld12 *= 2;
      v21 = (v20 >> 31) | (2 * *(_DWORD *)&ld12->ld12[8]);
      *(_DWORD *)&ld12->ld12[4] = (v19 >> 31) | (2 * v20);
      *(_DWORD *)&ld12->ld12[8] = v21;
    }
    while ( (v21 & 0x8000) == 0 );
  }
  *(_WORD *)&ld12->ld12[10] = v22;
}
