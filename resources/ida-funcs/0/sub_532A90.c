int __cdecl sub_532A90(_BYTE *a1, unsigned __int8 *a2, unsigned __int8 *a3, unsigned __int8 **a4)
{
  int result; // eax
  int v5; // [esp+4h] [ebp-8h]
  unsigned __int8 *v6; // [esp+8h] [ebp-4h]
  unsigned __int8 *v7; // [esp+18h] [ebp+Ch]

  if ( a2 == a3 )
    return -4;
  v6 = a2;
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
        case 3:
          if ( a2 == v6 )
          {
            result = sub_52F1F0(a1, a2 + 1, a3, a4);
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
          if ( a2 == v6 )
          {
            v7 = a2 + 1;
            if ( v7 == a3 )
            {
              result = -3;
            }
            else
            {
              if ( a1[*v7 + 76] == 10 )
                ++v7;
              *a4 = v7;
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
          if ( a2 == v6 )
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
        case 0x1E:
          if ( a2 == v6 )
          {
            v5 = sub_532020(a1, a2 + 1, a3, a4);
            result = v5 != 22 ? v5 : 0;
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
