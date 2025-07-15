unsigned __int8 *__cdecl sub_53A0A0(int a1, unsigned __int8 *a2, unsigned __int8 *a3, _DWORD *a4)
{
  unsigned __int8 *result; // eax
  int v5; // [esp+0h] [ebp-Ch]
  int v6; // [esp+8h] [ebp-4h]

  while ( 1 )
  {
    result = a2;
    if ( a2 >= a3 )
      break;
    if ( a2[1] )
      v6 = sub_534A50(a2[1], *a2);
    else
      v6 = *(unsigned __int8 *)(a1 + *a2 + 76);
    switch ( v6 )
    {
      case 5:
        a2 += 2;
        break;
      case 6:
        a2 += 3;
        break;
      case 7:
        a2 += 4;
        break;
      case 9:
        ++*a4;
        a2 += 2;
        if ( a2 != a3 )
        {
          if ( a2[1] )
            v5 = sub_534A50(a2[1], *a2);
          else
            v5 = *(unsigned __int8 *)(a1 + *a2 + 76);
          if ( v5 == 10 )
            a2 += 2;
        }
        a4[1] = -1;
        break;
      case 10:
        a4[1] = -1;
        ++*a4;
        a2 += 2;
        break;
      default:
        a2 += 2;
        break;
    }
    ++a4[1];
  }
  return result;
}
