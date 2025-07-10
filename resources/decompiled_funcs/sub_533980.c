unsigned __int8 *__cdecl sub_533980(int a1, unsigned __int8 *a2, unsigned __int8 *a3, _DWORD *a4)
{
  unsigned __int8 *result; // eax

  while ( 1 )
  {
    result = a2;
    if ( a2 >= a3 )
      break;
    switch ( *(_BYTE *)(a1 + *a2 + 76) )
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
        if ( ++a2 != a3 && *(_BYTE *)(a1 + *a2 + 76) == 10 )
          ++a2;
        a4[1] = -1;
        break;
      case 0xA:
        a4[1] = -1;
        ++*a4;
        ++a2;
        break;
      default:
        ++a2;
        break;
    }
    ++a4[1];
  }
  return result;
}
