int __cdecl sub_656C80(int a1, char *a2, char *a3, char **a4)
{
  int result; // eax
  int v5; // [esp+4h] [ebp-4h]
  char *v6; // [esp+14h] [ebp+Ch]
  char *v7; // [esp+14h] [ebp+Ch]

  if ( a2 == a3 )
    return -1;
  if ( *a2 || a2[1] != 45 )
  {
    *a4 = a2;
    return 0;
  }
  v6 = a2 + 2;
  while ( 2 )
  {
    if ( v6 == a3 )
      return -1;
    if ( *v6 )
      v5 = sub_64FDE0(*v6, v6[1]);
    else
      v5 = *(unsigned __int8 *)(a1 + (unsigned __int8)v6[1] + 76);
    switch ( v5 )
    {
      case 0:
      case 1:
      case 8:
        *a4 = v6;
        return 0;
      case 5:
        if ( a3 - v6 < 2 )
          return -2;
        v6 += 2;
        continue;
      case 6:
        if ( a3 - v6 < 3 )
          return -2;
        v6 += 3;
        continue;
      case 7:
        if ( a3 - v6 < 4 )
          return -2;
        v6 += 4;
        continue;
      case 27:
        v6 += 2;
        if ( v6 == a3 )
          return -1;
        if ( *v6 || v6[1] != 45 )
          continue;
        v7 = v6 + 2;
        if ( v7 == a3 )
        {
          result = -1;
        }
        else if ( !*v7 && v7[1] == 62 )
        {
          *a4 = v7 + 2;
          result = 13;
        }
        else
        {
          *a4 = v7;
          result = 0;
        }
        break;
      default:
        v6 += 2;
        continue;
    }
    break;
  }
  return result;
}
