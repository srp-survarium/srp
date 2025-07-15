int __cdecl sub_5380B0(int a1, unsigned __int8 *a2, unsigned __int8 *a3, unsigned __int8 **a4)
{
  int result; // eax
  int v5; // [esp+4h] [ebp-14h]
  int v6; // [esp+Ch] [ebp-Ch]
  int v7; // [esp+14h] [ebp-4h]
  unsigned __int8 *v8; // [esp+24h] [ebp+Ch]

  if ( a2 == a3 )
    return -1;
  if ( a2[1] )
    v7 = sub_534A50(a2[1], *a2);
  else
    v7 = *(unsigned __int8 *)(a1 + *a2 + 76);
  switch ( v7 )
  {
    case 20:
      *a4 = a2 + 2;
      result = 33;
      break;
    case 22:
    case 24:
      v8 = a2 + 2;
      while ( 2 )
      {
        if ( v8 == a3 )
        {
          result = -1;
        }
        else
        {
          if ( v8[1] )
            v6 = sub_534A50(v8[1], *v8);
          else
            v6 = *(unsigned __int8 *)(a1 + *v8 + 76);
          switch ( v6 )
          {
            case 9:
            case 10:
            case 21:
LABEL_23:
              *a4 = v8;
              result = 16;
              break;
            case 22:
            case 24:
              v8 += 2;
              continue;
            case 30:
              if ( v8 + 2 == a3 )
              {
                result = -1;
              }
              else
              {
                if ( v8[3] )
                  v5 = sub_534A50(v8[3], v8[2]);
                else
                  v5 = *(unsigned __int8 *)(a1 + v8[2] + 76);
                switch ( v5 )
                {
                  case 9:
                  case 10:
                  case 21:
                  case 30:
                    *a4 = v8;
                    result = 0;
                    break;
                  default:
                    goto LABEL_23;
                }
              }
              break;
            default:
              *a4 = v8;
              result = 0;
              break;
          }
        }
        break;
      }
      break;
    case 27:
      result = sub_535E10(a1, a2 + 2, a3, a4);
      break;
    default:
      *a4 = a2;
      result = 0;
      break;
  }
  return result;
}
