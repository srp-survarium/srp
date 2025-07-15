unsigned __int8 *__cdecl sub_539F50(int a1, unsigned __int8 *a2)
{
  int v3; // [esp+4h] [ebp-8h]
  unsigned __int8 *v4; // [esp+8h] [ebp-4h]

  v4 = a2;
  while ( 1 )
  {
    if ( a2[1] )
      v3 = sub_534A50(a2[1], *a2);
    else
      v3 = *(unsigned __int8 *)(a1 + *a2 + 76);
    switch ( v3 )
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
      case 22:
      case 23:
      case 24:
      case 25:
      case 26:
      case 27:
      case 29:
        a2 += 2;
        break;
      default:
        return (unsigned __int8 *)(a2 - v4);
    }
  }
}
