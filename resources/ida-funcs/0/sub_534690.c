int __cdecl sub_534690(int a1, char *a2, char *a3, char **a4)
{
  int v5; // [esp+4h] [ebp-14h]
  int v6; // [esp+8h] [ebp-10h]
  int v7; // [esp+10h] [ebp-8h]
  unsigned int v8; // [esp+14h] [ebp-4h]
  char *v9; // [esp+24h] [ebp+Ch]
  char *v10; // [esp+24h] [ebp+Ch]
  char *v11; // [esp+24h] [ebp+Ch]

  if ( a2 == a3 )
    return -4;
  if ( (((_BYTE)a3 - (_BYTE)a2) & 1) != 0 )
  {
    v8 = (a3 - a2) & 0xFFFFFFFE;
    if ( !v8 )
      return -1;
    a3 = &a2[v8];
  }
  if ( a2[1] )
    v7 = sub_534A50(a2[1], *a2);
  else
    v7 = *(unsigned __int8 *)(a1 + (unsigned __int8)*a2 + 76);
  switch ( v7 )
  {
    case 0:
    case 1:
    case 8:
      *a4 = a2;
      return 0;
    case 4:
      v9 = a2 + 2;
      if ( v9 == a3 )
        return -1;
      if ( !v9[1] && *v9 == 93 )
      {
        v10 = v9 + 2;
        if ( v10 == a3 )
        {
          return -1;
        }
        else
        {
          if ( v10[1] || *v10 != 62 )
          {
            v9 = v10 - 2;
            goto LABEL_42;
          }
          *a4 = v10 + 2;
          return 40;
        }
      }
      else
      {
LABEL_42:
        while ( v9 != a3 )
        {
          if ( v9[1] )
            v5 = sub_534A50(v9[1], *v9);
          else
            v5 = *(unsigned __int8 *)(a1 + (unsigned __int8)*v9 + 76);
          switch ( v5 )
          {
            case 0:
            case 1:
            case 4:
            case 8:
            case 9:
            case 10:
              *a4 = v9;
              return 6;
            case 5:
              if ( a3 - v9 < 2 )
              {
                *a4 = v9;
                return 6;
              }
              v9 += 2;
              continue;
            case 6:
              if ( a3 - v9 < 3 )
              {
                *a4 = v9;
                return 6;
              }
              v9 += 3;
              continue;
            case 7:
              if ( a3 - v9 < 4 )
              {
                *a4 = v9;
                return 6;
              }
              v9 += 4;
              break;
            default:
              v9 += 2;
              continue;
          }
        }
        *a4 = v9;
        return 6;
      }
    case 5:
      if ( a3 - a2 >= 2 )
      {
        v9 = a2 + 2;
        goto LABEL_42;
      }
      return -2;
    case 6:
      if ( a3 - a2 >= 3 )
      {
        v9 = a2 + 3;
        goto LABEL_42;
      }
      return -2;
    case 7:
      if ( a3 - a2 >= 4 )
      {
        v9 = a2 + 4;
        goto LABEL_42;
      }
      return -2;
    case 9:
      v11 = a2 + 2;
      if ( v11 == a3 )
        return -1;
      if ( v11[1] )
        v6 = sub_534A50(v11[1], *v11);
      else
        v6 = *(unsigned __int8 *)(a1 + (unsigned __int8)*v11 + 76);
      if ( v6 == 10 )
        v11 += 2;
      *a4 = v11;
      return 7;
    case 10:
      *a4 = a2 + 2;
      return 7;
    default:
      v9 = a2 + 2;
      goto LABEL_42;
  }
}
