int __cdecl sub_64DC40(_BYTE *a1, unsigned __int8 *a2, unsigned __int8 *a3, unsigned __int8 **a4)
{
  int result; // eax
  unsigned __int8 *v5; // [esp+4h] [ebp-4h]
  unsigned __int8 *v6; // [esp+14h] [ebp+Ch]

  if ( a2 == a3 )
    return -4;
  v5 = a2;
  while ( 2 )
  {
    if ( a2 == a3 )
    {
      *a4 = a2;
      return 6;
    }
    else
    {
      switch ( a1[*a2 + 76] )
      {
        case 2:
          *a4 = a2;
          result = 0;
          break;
        case 3:
          if ( a2 == v5 )
          {
            result = sub_64A580(a1, a2 + 1, a3, a4);
          }
          else
          {
            *a4 = a2;
            result = 6;
          }
          break;
        case 5:
          a2 += 2;
          continue;
        case 6:
          a2 += 3;
          continue;
        case 7:
          a2 += 4;
          continue;
        case 9:
          if ( a2 == v5 )
          {
            v6 = a2 + 1;
            if ( v6 == a3 )
            {
              result = -3;
            }
            else
            {
              if ( a1[*v6 + 76] == 10 )
                ++v6;
              *a4 = v6;
              result = 7;
            }
          }
          else
          {
            *a4 = a2;
            result = 6;
          }
          break;
        case 0xA:
          if ( a2 == v5 )
          {
            *a4 = a2 + 1;
            result = 7;
          }
          else
          {
            *a4 = a2;
            result = 6;
          }
          break;
        case 0x15:
          if ( a2 == v5 )
          {
            *a4 = a2 + 1;
            result = 39;
          }
          else
          {
            *a4 = a2;
            result = 6;
          }
          break;
        default:
          ++a2;
          continue;
      }
    }
    return result;
  }
}
