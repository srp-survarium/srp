int __cdecl sub_65BAC0(_DWORD *a1, int a2, int a3, unsigned __int8 *a4, unsigned __int8 *a5, _DWORD *a6)
{
  int v7; // [esp+0h] [ebp-14h]
  unsigned int v8; // [esp+4h] [ebp-10h]
  char v9; // [esp+8h] [ebp-Ch]
  int v10; // [esp+Ch] [ebp-8h]
  _DWORD *v11; // [esp+10h] [ebp-4h]

  if ( a4 == a5 )
    return -4;
  v11 = *(_DWORD **)(a2 + 76);
  if ( a4 + 1 != a5 )
  {
    v7 = a4[1] | (*a4 << 8);
    if ( v7 > 65279 )
    {
      if ( v7 == 65534 )
      {
        if ( *(_BYTE *)(a2 + 73) || a3 != 1 )
        {
          *a6 = a4 + 2;
          *v11 = a1[5];
          return 14;
        }
        goto LABEL_52;
      }
    }
    else
    {
      switch ( v7 )
      {
        case 65279:
          if ( *(_BYTE *)(a2 + 73) || a3 != 1 )
          {
            *a6 = a4 + 2;
            *v11 = a1[4];
            return 14;
          }
          goto LABEL_52;
        case 15360:
          if ( (*(_BYTE *)(a2 + 73) == 4 || *(_BYTE *)(a2 + 73) == 3) && a3 == 1 )
            goto LABEL_52;
          goto LABEL_51;
        case 61371:
          if ( a3 != 1 || (v10 = *(char *)(a2 + 73), *(_BYTE *)(a2 + 73)) && v10 != 4 && v10 != 5 && v10 != 3 )
          {
            if ( a4 + 2 == a5 )
              return -1;
            if ( a4[2] == 191 )
            {
              *a6 = a4 + 3;
              *v11 = a1[2];
              return 14;
            }
          }
          goto LABEL_52;
      }
    }
    if ( !*a4 )
    {
      if ( a3 != 1 || *(_BYTE *)(a2 + 73) != 5 )
      {
        *v11 = a1[4];
        return (*(int (__cdecl **)(_DWORD, unsigned __int8 *, unsigned __int8 *, _DWORD *))(*v11 + 4 * a3))(
                 *v11,
                 a4,
                 a5,
                 a6);
      }
      goto LABEL_52;
    }
    if ( a4[1] || a3 == 1 )
      goto LABEL_52;
LABEL_51:
    *v11 = a1[5];
    return (*(int (__cdecl **)(_DWORD, unsigned __int8 *, unsigned __int8 *, _DWORD *))(*v11 + 4 * a3))(
             *v11,
             a4,
             a5,
             a6);
  }
  v9 = *(_BYTE *)(a2 + 73);
  if ( v9 >= 3 && v9 <= 5 )
    return -1;
  v8 = *a4;
  if ( v8 <= 0xEF )
  {
    if ( v8 != 239 )
    {
      if ( *a4 && v8 != 60 )
        goto LABEL_52;
      return -1;
    }
LABEL_13:
    if ( !*(_BYTE *)(a2 + 73) && a3 == 1 )
      goto LABEL_52;
    return -1;
  }
  if ( *a4 >= 0xFEu )
    goto LABEL_13;
LABEL_52:
  *v11 = a1[*(char *)(a2 + 73)];
  return (*(int (__cdecl **)(_DWORD, unsigned __int8 *, unsigned __int8 *, _DWORD *))(*v11 + 4 * a3))(*v11, a4, a5, a6);
}
