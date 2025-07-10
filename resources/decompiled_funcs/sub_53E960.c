int __cdecl sub_53E960(int a1, unsigned __int8 *a2, unsigned __int8 *a3, unsigned __int8 **a4)
{
  int result; // eax
  int v5; // [esp+0h] [ebp-14h]
  int v6; // [esp+8h] [ebp-Ch]
  int v7; // [esp+Ch] [ebp-8h]
  unsigned __int8 *v8; // [esp+10h] [ebp-4h]
  unsigned __int8 *v9; // [esp+20h] [ebp+Ch]

  if ( a2 == a3 )
    return -4;
  v8 = a2;
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
        v6 = sub_534A50(*a2, a2[1]);
      else
        v6 = *(unsigned __int8 *)(a1 + a2[1] + 76);
      switch ( v6 )
      {
        case 3:
          if ( a2 == v8 )
          {
            result = sub_53AA50(a1, a2 + 2, a3, a4);
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
          if ( a2 == v8 )
          {
            v9 = a2 + 2;
            if ( v9 == a3 )
            {
              result = -3;
            }
            else
            {
              if ( *v9 )
                v5 = sub_534A50(*v9, v9[1]);
              else
                v5 = *(unsigned __int8 *)(a1 + v9[1] + 76);
              if ( v5 == 10 )
                v9 += 2;
              *a4 = v9;
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
          if ( a2 == v8 )
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
        case 30:
          if ( a2 == v8 )
          {
            v7 = sub_53DDF0(a1, a2 + 2, a3, a4);
            result = v7 != 22 ? v7 : 0;
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
