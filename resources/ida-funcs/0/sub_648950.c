int __cdecl sub_648950(int a1, int a2, int a3, int a4)
{
  unsigned int v5; // [esp+10h] [ebp-30h]
  int v6; // [esp+14h] [ebp-2Ch]
  char v7; // [esp+1Bh] [ebp-25h]
  int v8; // [esp+1Ch] [ebp-24h]
  unsigned int v9; // [esp+24h] [ebp-1Ch]
  int v10; // [esp+28h] [ebp-18h]
  unsigned __int8 v11; // [esp+2Fh] [ebp-11h]
  unsigned __int8 v12; // [esp+2Fh] [ebp-11h]
  unsigned __int8 v13; // [esp+2Fh] [ebp-11h]
  unsigned int v14; // [esp+30h] [ebp-10h]
  int v15; // [esp+34h] [ebp-Ch]
  int v16; // [esp+38h] [ebp-8h]
  unsigned int v17; // [esp+3Ch] [ebp-4h]
  unsigned int i; // [esp+3Ch] [ebp-4h]

  if ( *(_DWORD *)(a2 + 8) )
  {
    v15 = sub_648D90(a1, a3);
    v14 = *(_DWORD *)(a2 + 8) - 1;
    v11 = 0;
    v17 = v14 & v15;
    while ( *(_DWORD *)(*(_DWORD *)a2 + 4 * v17) )
    {
      if ( (unsigned __int8)sub_648D50(a3, **(_DWORD **)(*(_DWORD *)a2 + 4 * v17)) )
        return *(_DWORD *)(*(_DWORD *)a2 + 4 * v17);
      if ( !v11 )
        v11 = (v14 >> 2) & ((v15 & ~v14) >> (*(_BYTE *)(a2 + 4) - 1)) | 1;
      if ( v17 >= v11 )
        v17 -= v11;
      else
        v17 += *(_DWORD *)(a2 + 8) - v11;
    }
    if ( !a4 )
      return 0;
    if ( *(_DWORD *)(a2 + 12) >> (*(_BYTE *)(a2 + 4) - 1) )
    {
      v7 = *(_BYTE *)(a2 + 4) + 1;
      v10 = 1 << v7;
      v9 = (1 << v7) - 1;
      v8 = (**(int (__cdecl ***)(int))(a2 + 16))(4 * (1 << v7));
      if ( !v8 )
        return 0;
      memset(v8, 0, 4 * (1 << v7));
      for ( i = 0; i < *(_DWORD *)(a2 + 8); ++i )
      {
        if ( *(_DWORD *)(*(_DWORD *)a2 + 4 * i) )
        {
          v6 = sub_648D90(a1, **(_DWORD **)(*(_DWORD *)a2 + 4 * i));
          v5 = v9 & v6;
          v12 = 0;
          while ( *(_DWORD *)(v8 + 4 * v5) )
          {
            if ( !v12 )
              v12 = (v9 >> 2) & ((v6 & ~v9) >> (v7 - 1)) | 1;
            if ( v5 >= v12 )
              v5 -= v12;
            else
              v5 += v10 - v12;
          }
          *(_DWORD *)(v8 + 4 * v5) = *(_DWORD *)(*(_DWORD *)a2 + 4 * i);
        }
      }
      (*(void (__cdecl **)(_DWORD))(*(_DWORD *)(a2 + 16) + 8))(*(_DWORD *)a2);
      *(_DWORD *)a2 = v8;
      *(_BYTE *)(a2 + 4) = v7;
      *(_DWORD *)(a2 + 8) = v10;
      v17 = v9 & v15;
      v13 = 0;
      while ( *(_DWORD *)(*(_DWORD *)a2 + 4 * v17) )
      {
        if ( !v13 )
          v13 = (v9 >> 2) & ((v15 & ~v9) >> (v7 - 1)) | 1;
        if ( v17 >= v13 )
          v17 -= v13;
        else
          v17 += v10 - v13;
      }
    }
  }
  else
  {
    if ( !a4 )
      return 0;
    *(_BYTE *)(a2 + 4) = 6;
    *(_DWORD *)(a2 + 8) = 64;
    v16 = 4 * *(_DWORD *)(a2 + 8);
    *(_DWORD *)a2 = (**(int (__cdecl ***)(int))(a2 + 16))(v16);
    if ( !*(_DWORD *)a2 )
    {
      *(_DWORD *)(a2 + 8) = 0;
      return 0;
    }
    memset(*(_DWORD *)a2, 0, v16);
    v17 = (*(_DWORD *)(a2 + 8) - 1) & sub_648D90(a1, a3);
  }
  *(_DWORD *)(*(_DWORD *)a2 + 4 * v17) = (**(int (__cdecl ***)(int))(a2 + 16))(a4);
  if ( !*(_DWORD *)(*(_DWORD *)a2 + 4 * v17) )
    return 0;
  memset(*(_DWORD *)(*(_DWORD *)a2 + 4 * v17), 0, a4);
  **(_DWORD **)(*(_DWORD *)a2 + 4 * v17) = a3;
  ++*(_DWORD *)(a2 + 12);
  return *(_DWORD *)(*(_DWORD *)a2 + 4 * v17);
}
