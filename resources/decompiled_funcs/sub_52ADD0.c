int __cdecl sub_52ADD0(int a1, int a2, int a3, _DWORD *a4)
{
  int result; // eax
  int v5; // [esp+0h] [ebp-10h]
  int v6; // [esp+8h] [ebp-8h] BYREF
  int v7; // [esp+Ch] [ebp-4h]

  *(_DWORD *)(a1 + 280) = sub_52ADD0;
  *(_DWORD *)(a1 + 288) = a2;
  while ( 2 )
  {
    v6 = 0;
    v7 = (**(int (__cdecl ***)(_DWORD, int, int, int *))(a1 + 144))(*(_DWORD *)(a1 + 144), a2, a3, &v6);
    *(_DWORD *)(a1 + 292) = v6;
    switch ( v7 )
    {
      case -15:
        if ( *(_DWORD *)(a1 + 80) && (sub_52C240(a1, *(_DWORD *)(a1 + 144), a2, v6), *(_DWORD *)(a1 + 480) == 2) )
        {
          result = 35;
        }
        else
        {
          *a4 = v6;
          result = 0;
        }
        break;
      case -4:
        *a4 = a2;
        result = 0;
        break;
      case -2:
        if ( *(_BYTE *)(a1 + 484) )
        {
          result = 6;
        }
        else
        {
          *a4 = a2;
          result = 0;
        }
        break;
      case -1:
        if ( *(_BYTE *)(a1 + 484) )
        {
          result = 5;
        }
        else
        {
          *a4 = a2;
          result = 0;
        }
        break;
      case 0:
        *(_DWORD *)(a1 + 288) = v6;
        result = 4;
        break;
      case 11:
        if ( sub_52BFC0(a1, *(_DWORD *)(a1 + 144), a2, v6) )
          goto LABEL_25;
        result = 1;
        break;
      case 13:
        if ( sub_52C190(a1, *(_DWORD *)(a1 + 144), a2, v6) )
          goto LABEL_25;
        result = 1;
        break;
      case 15:
        if ( *(_DWORD *)(a1 + 80) )
          sub_52C240(a1, *(_DWORD *)(a1 + 144), a2, v6);
LABEL_25:
        a2 = v6;
        *(_DWORD *)(a1 + 288) = v6;
        v5 = *(_DWORD *)(a1 + 480);
        if ( v5 == 2 )
        {
          result = 35;
        }
        else
        {
          if ( v5 != 3 )
            continue;
          *a4 = v6;
          result = 0;
        }
        break;
      default:
        result = 9;
        break;
    }
    return result;
  }
}
