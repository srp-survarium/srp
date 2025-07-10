int __cdecl sub_53FA40(int a1, int a2)
{
  int v3; // [esp+4h] [ebp-8h]
  int v4; // [esp+8h] [ebp-4h]

  v4 = a2;
  while ( 1 )
  {
    if ( *(_BYTE *)a2 )
      v3 = sub_534A50(*(_BYTE *)a2, *(_BYTE *)(a2 + 1));
    else
      v3 = *(unsigned __int8 *)(a1 + *(unsigned __int8 *)(a2 + 1) + 76);
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
        return a2 - v4;
    }
  }
}
