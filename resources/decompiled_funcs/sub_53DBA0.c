int __cdecl sub_53DBA0(int a1, int a2, char *a3, char **a4)
{
  int result; // eax
  int v5; // [esp+4h] [ebp-14h]
  int v6; // [esp+Ch] [ebp-Ch]
  int v7; // [esp+14h] [ebp-4h]
  int v8; // [esp+24h] [ebp+Ch]

  if ( (char *)a2 == a3 )
    return -1;
  if ( *(_BYTE *)a2 )
    v7 = sub_534A50(*(_BYTE *)a2, *(_BYTE *)(a2 + 1));
  else
    v7 = *(unsigned __int8 *)(a1 + *(unsigned __int8 *)(a2 + 1) + 76);
  switch ( v7 )
  {
    case 20:
      *a4 = (char *)(a2 + 2);
      result = 33;
      break;
    case 22:
    case 24:
      v8 = a2 + 2;
      while ( 2 )
      {
        if ( (char *)v8 == a3 )
        {
          result = -1;
        }
        else
        {
          if ( *(_BYTE *)v8 )
            v6 = sub_534A50(*(_BYTE *)v8, *(_BYTE *)(v8 + 1));
          else
            v6 = *(unsigned __int8 *)(a1 + *(unsigned __int8 *)(v8 + 1) + 76);
          switch ( v6 )
          {
            case 9:
            case 10:
            case 21:
LABEL_23:
              *a4 = (char *)v8;
              result = 16;
              break;
            case 22:
            case 24:
              v8 += 2;
              continue;
            case 30:
              if ( (char *)(v8 + 2) == a3 )
              {
                result = -1;
              }
              else
              {
                if ( *(_BYTE *)(v8 + 2) )
                  v5 = sub_534A50(*(_BYTE *)(v8 + 2), *(_BYTE *)(v8 + 3));
                else
                  v5 = *(unsigned __int8 *)(a1 + *(unsigned __int8 *)(v8 + 3) + 76);
                switch ( v5 )
                {
                  case 9:
                  case 10:
                  case 21:
                  case 30:
                    *a4 = (char *)v8;
                    result = 0;
                    break;
                  default:
                    goto LABEL_23;
                }
              }
              break;
            default:
              *a4 = (char *)v8;
              result = 0;
              break;
          }
        }
        break;
      }
      break;
    case 27:
      result = sub_53B8F0(a1, (char *)(a2 + 2), a3, a4);
      break;
    default:
      *a4 = (char *)a2;
      result = 0;
      break;
  }
  return result;
}
