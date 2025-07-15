int __cdecl sub_655960(int a1, char *a2, char *a3, char **a4)
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
  if ( *a2 )
    v7 = sub_64FDE0(*a2, a2[1]);
  else
    v7 = *(unsigned __int8 *)(a1 + (unsigned __int8)a2[1] + 76);
  switch ( v7 )
  {
    case 0:
    case 1:
    case 8:
      *a4 = a2;
      return 0;
    case 2:
      return sub_6563C0(a1, a2 + 2, a3, a4);
    case 3:
      return sub_655DE0(a1, a2 + 2, a3, a4);
    case 4:
      v10 = a2 + 2;
      if ( v10 == a3 )
        return -5;
      if ( !*v10 && v10[1] == 93 )
      {
        v11 = v10 + 2;
        if ( v11 == a3 )
        {
          return -5;
        }
        else
        {
          if ( *v11 || v11[1] != 62 )
          {
            v10 = v11 - 2;
            goto LABEL_44;
          }
          *a4 = v11;
          return 0;
        }
      }
      else
      {
LABEL_44:
        while ( v10 != a3 )
        {
          if ( *v10 )
            v5 = sub_64FDE0(*v10, v10[1]);
          else
            v5 = *(unsigned __int8 *)(a1 + (unsigned __int8)v10[1] + 76);
          switch ( v5 )
          {
            case 0:
            case 1:
            case 2:
            case 3:
            case 8:
            case 9:
            case 10:
              goto LABEL_67;
            case 4:
              if ( v10 + 2 == a3 )
                goto LABEL_67;
              if ( !v10[2] && v10[3] == 93 )
              {
                if ( v10 + 4 == a3 )
                {
LABEL_67:
                  *a4 = v10;
                  return 6;
                }
                if ( !v10[4] && v10[5] == 62 )
                {
                  *a4 = v10 + 4;
                  return 0;
                }
                v10 += 2;
              }
              else
              {
                v10 += 2;
              }
              break;
            case 5:
              if ( a3 - v10 < 2 )
              {
                *a4 = v10;
                return 6;
              }
              v10 += 2;
              continue;
            case 6:
              if ( a3 - v10 < 3 )
              {
                *a4 = v10;
                return 6;
              }
              v10 += 3;
              continue;
            case 7:
              if ( a3 - v10 < 4 )
              {
                *a4 = v10;
                return 6;
              }
              v10 += 4;
              continue;
            default:
              v10 += 2;
              continue;
          }
        }
        *a4 = v10;
        return 6;
      }
    case 5:
      if ( a3 - a2 >= 2 )
      {
        v10 = a2 + 2;
        goto LABEL_44;
      }
      return -2;
    case 6:
      if ( a3 - a2 >= 3 )
      {
        v10 = a2 + 3;
        goto LABEL_44;
      }
      return -2;
    case 7:
      if ( a3 - a2 >= 4 )
      {
        v10 = a2 + 4;
        goto LABEL_44;
      }
      return -2;
    case 9:
      v9 = a2 + 2;
      if ( v9 == a3 )
        return -3;
      if ( *v9 )
        v6 = sub_64FDE0(*v9, v9[1]);
      else
        v6 = *(unsigned __int8 *)(a1 + (unsigned __int8)v9[1] + 76);
      if ( v6 == 10 )
        v9 += 2;
      *a4 = v9;
      return 7;
    case 10:
      *a4 = a2 + 2;
      return 7;
    default:
      v10 = a2 + 2;
      goto LABEL_44;
  }
}
