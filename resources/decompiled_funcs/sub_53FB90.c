unsigned int __cdecl sub_53FB90(int a1, unsigned int a2, unsigned int a3, _DWORD *a4)
{
  unsigned int result; // eax
  int v5; // [esp+0h] [ebp-Ch]
  int v6; // [esp+8h] [ebp-4h]

  while ( 1 )
  {
    result = a2;
    if ( a2 >= a3 )
      break;
    if ( *(_BYTE *)a2 )
      v6 = sub_534A50(*(_BYTE *)a2, *(_BYTE *)(a2 + 1));
    else
      v6 = *(unsigned __int8 *)(a1 + *(unsigned __int8 *)(a2 + 1) + 76);
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
          if ( *(_BYTE *)a2 )
            v5 = sub_534A50(*(_BYTE *)a2, *(_BYTE *)(a2 + 1));
          else
            v5 = *(unsigned __int8 *)(a1 + *(unsigned __int8 *)(a2 + 1) + 76);
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
