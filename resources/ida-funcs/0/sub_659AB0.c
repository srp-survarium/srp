int __cdecl sub_659AB0(int a1, unsigned __int8 *a2, unsigned __int8 *a3, unsigned __int8 **a4)
{
  int result; // eax
  int v5; // [esp+0h] [ebp-10h]
  int v6; // [esp+8h] [ebp-8h]
  unsigned __int8 *v7; // [esp+Ch] [ebp-4h]
  unsigned __int8 *v8; // [esp+1Ch] [ebp+Ch]

  if ( a2 == a3 )
    return -4;
  v7 = a2;
  while ( 2 )
  {
    if ( a2 == a3 )
    {
      *a4 = a2;
      return 6;
    }
    else
    {
      if ( *a2 )
        v6 = sub_64FDE0(*a2, a2[1]);
      else
        v6 = *(unsigned __int8 *)(a1 + a2[1] + 76);
      switch ( v6 )
      {
        case 2:
          *a4 = a2;
          result = 0;
          break;
        case 3:
          if ( a2 == v7 )
          {
            result = sub_655DE0(a1, a2 + 2, a3, a4);
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
          if ( a2 == v7 )
          {
            v8 = a2 + 2;
            if ( v8 == a3 )
            {
              result = -3;
            }
            else
            {
              if ( *v8 )
                v5 = sub_64FDE0(*v8, v8[1]);
              else
                v5 = *(unsigned __int8 *)(a1 + v8[1] + 76);
              if ( v5 == 10 )
                v8 += 2;
              *a4 = v8;
              result = 7;
            }
          }
          else
          {
            *a4 = a2;
            result = 6;
          }
          break;
        case 10:
          if ( a2 == v7 )
          {
            *a4 = a2 + 2;
            result = 7;
          }
          else
          {
            *a4 = a2;
            result = 6;
          }
          break;
        case 21:
          if ( a2 == v7 )
          {
            *a4 = a2 + 2;
            result = 39;
          }
          else
          {
            *a4 = a2;
            result = 6;
          }
          break;
        default:
          a2 += 2;
          continue;
      }
    }
    return result;
  }
}
