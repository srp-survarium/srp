int __cdecl sub_64D1F0(_BYTE *a1, unsigned __int8 *a2, unsigned __int8 *a3, unsigned __int8 **a4)
{
  int result; // eax
  unsigned __int8 *v5; // [esp+18h] [ebp+Ch]

  if ( a2 == a3 )
    return -1;
  switch ( a1[*a2 + 76] )
  {
    case 0x14:
      *a4 = a2 + 1;
      result = 33;
      break;
    case 0x16:
    case 0x18:
      v5 = a2 + 1;
      while ( 2 )
      {
        if ( v5 == a3 )
        {
          result = -1;
        }
        else
        {
          switch ( a1[*v5 + 76] )
          {
            case 9:
            case 0xA:
            case 0x15:
LABEL_13:
              *a4 = v5;
              result = 16;
              break;
            case 0x16:
            case 0x18:
              ++v5;
              continue;
            case 0x1E:
              if ( v5 + 1 == a3 )
              {
                result = -1;
              }
              else
              {
                switch ( a1[v5[1] + 76] )
                {
                  case 9:
                  case 0xA:
                  case 0x15:
                  case 0x1E:
                    *a4 = v5;
                    result = 0;
                    break;
                  default:
                    goto LABEL_13;
                }
              }
              break;
            default:
              *a4 = v5;
              result = 0;
              break;
          }
        }
        break;
      }
      break;
    case 0x1B:
      result = sub_64B260(a1, a2 + 1, a3, a4);
      break;
    default:
      *a4 = a2;
      result = 0;
      break;
  }
  return result;
}
