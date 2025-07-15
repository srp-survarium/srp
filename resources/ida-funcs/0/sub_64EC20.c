unsigned __int8 *__cdecl sub_64EC20(int a1, unsigned __int8 *a2)
{
  unsigned __int8 *v3; // [esp+4h] [ebp-4h]

  v3 = a2;
  while ( 1 )
  {
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
      case 0x16:
      case 0x17:
      case 0x18:
      case 0x19:
      case 0x1A:
      case 0x1B:
      case 0x1D:
        ++a2;
        break;
      default:
        return (unsigned __int8 *)(a2 - v3);
    }
  }
}
