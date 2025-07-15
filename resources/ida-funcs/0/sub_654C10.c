int __cdecl sub_654C10(int a1, int a2)
{
  int v3; // [esp+0h] [ebp-18h]
  int v4; // [esp+8h] [ebp-10h]
  int v5; // [esp+14h] [ebp-4h]
  char *v6; // [esp+24h] [ebp+Ch]
  char *i; // [esp+24h] [ebp+Ch]

  v5 = 0;
  v6 = (char *)(a2 + 4);
  if ( v6[1] || *v6 != 120 )
  {
    while ( v6[1] || *v6 != 59 )
    {
      if ( v6[1] )
        v3 = -1;
      else
        v3 = *v6;
      v5 = 10 * v5 + v3 - 48;
      if ( v5 >= 1114112 )
        return -1;
      v6 += 2;
    }
  }
  else
  {
    for ( i = v6 + 2; i[1] || *i != 59; i += 2 )
    {
      if ( i[1] )
        v4 = -1;
      else
        v4 = *i;
      switch ( v4 )
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
          v5 = (16 * v5) | (v4 - 48);
          break;
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
          v5 = 16 * v5 + v4 - 55;
          break;
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        case 'f':
          v5 = 16 * v5 + v4 - 87;
          break;
        default:
          break;
      }
      if ( v5 >= 1114112 )
        return -1;
    }
  }
  return sub_65B090(v5);
}
