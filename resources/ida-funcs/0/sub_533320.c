int __cdecl sub_533320(int a1, int a2)
{
  int v3; // [esp+8h] [ebp-8h]
  int v4; // [esp+Ch] [ebp-4h]
  _BYTE *v5; // [esp+1Ch] [ebp+Ch]
  _BYTE *i; // [esp+1Ch] [ebp+Ch]

  v4 = 0;
  v5 = (_BYTE *)(a2 + 2);
  if ( *v5 == 120 )
  {
    for ( i = v5 + 1; *i != 59; ++i )
    {
      v3 = (char)*i;
      switch ( *i )
      {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
          v4 = (16 * v4) | (v3 - 48);
          break;
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
          v4 = 16 * v4 + v3 - 55;
          break;
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        case 'f':
          v4 = 16 * v4 + v3 - 87;
          break;
        default:
          break;
      }
      if ( v4 >= 1114112 )
        return -1;
    }
  }
  else
  {
    while ( *v5 != 59 )
    {
      v4 = 10 * v4 + (char)*v5 - 48;
      if ( v4 >= 1114112 )
        return -1;
      ++v5;
    }
  }
  return sub_53FD00(v4);
}
