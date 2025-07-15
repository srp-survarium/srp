char __cdecl sub_376530(unsigned __int8 **a1, int a2, int a3, int a4)
{
  unsigned __int8 *v4; // ebx
  unsigned __int8 *v5; // esi
  unsigned __int8 *v6; // edi
  unsigned __int8 **v7; // eax
  int v8; // eax
  unsigned __int8 **v9; // eax
  int v10; // eax
  bool v11; // cc
  char v13; // cl

  v4 = a1[4];
  v5 = *a1;
  v6 = a1[1];
  if ( *((_DWORD *)v4 + 99) )
    goto LABEL_17;
  if ( a3 < 25 )
  {
    do
    {
      if ( !v6 )
      {
        if ( !(*(unsigned __int8 (__cdecl **)(unsigned __int8 *))(*((_DWORD *)v4 + 6) + 12))(v4) )
          return 0;
        v7 = (unsigned __int8 **)*((_DWORD *)v4 + 6);
        v5 = *v7;
        v6 = v7[1];
      }
      v8 = *v5;
      --v6;
      ++v5;
      if ( v8 == 255 )
      {
        do
        {
          if ( !v6 )
          {
            if ( !(*(unsigned __int8 (__cdecl **)(unsigned __int8 *))(*((_DWORD *)v4 + 6) + 12))(v4) )
              return 0;
            v9 = (unsigned __int8 **)*((_DWORD *)v4 + 6);
            v5 = *v9;
            v6 = v9[1];
          }
          v10 = *v5;
          --v6;
          ++v5;
        }
        while ( v10 == 255 );
        if ( v10 )
        {
          *((_DWORD *)v4 + 99) = v10;
LABEL_17:
          if ( a4 > a3 )
          {
            if ( !*(_BYTE *)(*((_DWORD *)v4 + 106) + 36) )
            {
              *(_DWORD *)(*(_DWORD *)v4 + 20) = 120;
              (*(void (__cdecl **)(unsigned __int8 *, int))(*(_DWORD *)v4 + 4))(v4, -1);
              *(_BYTE *)(*((_DWORD *)v4 + 106) + 36) = 1;
            }
            v13 = 25 - a3;
            a3 = 25;
            a2 <<= v13;
          }
          break;
        }
        v8 = 255;
      }
      v11 = a3 + 8 < 25;
      a2 = v8 | (a2 << 8);
      a3 += 8;
    }
    while ( v11 );
  }
  a1[1] = v6;
  *a1 = v5;
  a1[3] = (unsigned __int8 *)a3;
  a1[2] = (unsigned __int8 *)a2;
  return 1;
}
