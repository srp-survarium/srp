int __cdecl sub_37C6A0(_DWORD *a1, void *a2)
{
  signed int v2; // esi
  int v3; // ebp
  int v4; // eax
  int v5; // ecx
  int v6; // ebp
  int v7; // ebx
  signed int v8; // edx
  int v9; // ebp
  int v10; // edi
  int v11; // esi
  char v13; // [esp+13h] [ebp-9h]
  int v14; // [esp+14h] [ebp-8h]
  int v15; // [esp+18h] [ebp-4h]

  v2 = a1[25];
  v14 = v2;
  v15 = a1[21];
  v3 = 1;
  do
  {
    v4 = ++v3;
    if ( v2 > 1 )
    {
      v5 = v2 - 1;
      do
      {
        v4 *= v3;
        --v5;
      }
      while ( v5 );
    }
  }
  while ( v4 <= a1[21] );
  v6 = v3 - 1;
  if ( v6 < 2 )
  {
    *(_DWORD *)(*a1 + 20) = 58;
    *(_DWORD *)(*a1 + 24) = v4;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  v7 = 1;
  if ( v2 > 0 )
  {
    v8 = v2;
    memset32(a2, v6, v2);
    do
    {
      v7 *= v6;
      --v8;
    }
    while ( v8 );
  }
  while ( 2 )
  {
    v9 = 0;
    v13 = 0;
    if ( v2 > 0 )
    {
      while ( 1 )
      {
        v10 = a1[11] == 2 ? dword_863048[v9] : v9;
        v11 = *((_DWORD *)a2 + v10);
        if ( (v11 + 1) * (v7 / v11) > v15 )
          break;
        ++v9;
        *((_DWORD *)a2 + v10) = v11 + 1;
        v7 = (v11 + 1) * (v7 / v11);
        v13 = 1;
        if ( v9 >= v14 )
          goto LABEL_12;
      }
      if ( v13 )
      {
LABEL_12:
        v2 = v14;
        continue;
      }
    }
    return v7;
  }
}
