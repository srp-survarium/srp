int __cdecl sub_527E30(int a1, int a2, int *a3, int a4, _DWORD *a5, char a6)
{
  int v7; // [esp+0h] [ebp-28h]
  int v8; // [esp+8h] [ebp-20h] BYREF
  void (__cdecl *v9)(_DWORD, int, int); // [esp+Ch] [ebp-1Ch]
  char v10; // [esp+13h] [ebp-15h] BYREF
  int v11; // [esp+14h] [ebp-14h] BYREF
  int v12; // [esp+18h] [ebp-10h]
  _DWORD *v13; // [esp+1Ch] [ebp-Ch]
  _DWORD *v14; // [esp+20h] [ebp-8h]
  int v15; // [esp+24h] [ebp-4h] BYREF

  v15 = *a3;
  if ( a2 == *(_DWORD *)(a1 + 144) )
  {
    v13 = (_DWORD *)(a1 + 288);
    *(_DWORD *)(a1 + 288) = v15;
    v14 = (_DWORD *)(a1 + 292);
  }
  else
  {
    v13 = *(_DWORD **)(a1 + 300);
    v14 = (_DWORD *)(*(_DWORD *)(a1 + 300) + 4);
  }
  *v13 = v15;
  *a3 = 0;
  while ( 2 )
  {
    v12 = (*(int (__cdecl **)(int, int, int, int *))(a2 + 8))(a2, v15, a4, &v11);
    *v14 = v11;
    switch ( v12 )
    {
      case -4:
      case -1:
        if ( !a6 )
          return 20;
        *a5 = v15;
        return 0;
      case -2:
        if ( !a6 )
          return 6;
        *a5 = v15;
        return 0;
      case 0:
        *v13 = v11;
        return 4;
      case 6:
        v9 = *(void (__cdecl **)(_DWORD, int, int))(a1 + 60);
        if ( v9 )
        {
          if ( *(_BYTE *)(a2 + 72) )
          {
            v9(*(_DWORD *)(a1 + 4), v15, v11 - v15);
          }
          else
          {
            while ( 1 )
            {
              v8 = *(_DWORD *)(a1 + 44);
              (*(void (__cdecl **)(int, int *, int, int *, _DWORD))(a2 + 60))(a2, &v15, v11, &v8, *(_DWORD *)(a1 + 48));
              *v14 = v11;
              v9(*(_DWORD *)(a1 + 4), *(_DWORD *)(a1 + 44), v8 - *(_DWORD *)(a1 + 44));
              if ( v15 == v11 )
                break;
              *v13 = v15;
            }
          }
        }
        else if ( *(_DWORD *)(a1 + 80) )
        {
          sub_52C240(a1, a2, v15, v11);
        }
        goto LABEL_35;
      case 7:
        if ( *(_DWORD *)(a1 + 60) )
        {
          v10 = 10;
          (*(void (__cdecl **)(_DWORD, char *, int))(a1 + 60))(*(_DWORD *)(a1 + 4), &v10, 1);
        }
        else if ( *(_DWORD *)(a1 + 80) )
        {
          sub_52C240(a1, a2, v15, v11);
        }
LABEL_35:
        v15 = v11;
        *v13 = v11;
        v7 = *(_DWORD *)(a1 + 480);
        if ( v7 != 2 )
        {
          if ( v7 == 3 )
          {
            *a5 = v11;
            return 0;
          }
          continue;
        }
        return 35;
      case 40:
        if ( *(_DWORD *)(a1 + 76) )
        {
          (*(void (__cdecl **)(_DWORD))(a1 + 76))(*(_DWORD *)(a1 + 4));
        }
        else if ( *(_DWORD *)(a1 + 80) )
        {
          sub_52C240(a1, a2, v15, v11);
        }
        *a3 = v11;
        *a5 = v11;
        if ( *(_DWORD *)(a1 + 480) == 2 )
          return 35;
        else
          return 0;
      default:
        *v13 = v11;
        return 23;
    }
  }
}
