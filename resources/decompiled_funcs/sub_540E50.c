int __cdecl sub_540E50(int a1, int a2, int a3, _DWORD *a4, _DWORD *a5, _DWORD *a6, _DWORD *a7)
{
  int v8; // eax
  int v9; // eax
  int v10; // [esp+0h] [ebp-8h]
  int v11; // [esp+0h] [ebp-8h]
  int v12; // [esp+0h] [ebp-8h]
  int v13; // [esp+0h] [ebp-8h]
  char v14; // [esp+7h] [ebp-1h]
  int v15; // [esp+14h] [ebp+Ch]

  if ( a2 == a3 )
  {
    *a4 = 0;
    return 1;
  }
  else
  {
    v8 = sub_540DA0(a1, a2, a3);
    if ( sub_540DF0(v8) )
    {
      do
      {
        a2 += *(_DWORD *)(a1 + 68);
        v9 = sub_540DA0(a1, a2, a3);
      }
      while ( sub_540DF0(v9) );
      if ( a2 == a3 )
      {
        *a4 = 0;
        return 1;
      }
      else
      {
        *a4 = a2;
        while ( 1 )
        {
          v10 = sub_540DA0(a1, a2, a3);
          if ( v10 == -1 )
          {
            *a7 = a2;
            return 0;
          }
          if ( v10 == 61 )
          {
            *a5 = a2;
            goto LABEL_20;
          }
          if ( sub_540DF0(v10) )
            break;
          a2 += *(_DWORD *)(a1 + 68);
        }
        *a5 = a2;
        do
        {
          a2 += *(_DWORD *)(a1 + 68);
          v11 = sub_540DA0(a1, a2, a3);
        }
        while ( sub_540DF0(v11) );
        if ( v11 != 61 )
        {
          *a7 = a2;
          return 0;
        }
LABEL_20:
        if ( a2 == *a4 )
        {
          *a7 = a2;
          return 0;
        }
        else
        {
          do
          {
            a2 += *(_DWORD *)(a1 + 68);
            v12 = sub_540DA0(a1, a2, a3);
          }
          while ( sub_540DF0(v12) );
          if ( v12 == 34 || v12 == 39 )
          {
            v14 = v12;
            v15 = *(_DWORD *)(a1 + 68) + a2;
            *a6 = v15;
            while ( 1 )
            {
              v13 = sub_540DA0(a1, v15, a3);
              if ( v13 == v14 )
                break;
              if ( (v13 < 97 || v13 > 122)
                && (v13 < 65 || v13 > 90)
                && (v13 < 48 || v13 > 57)
                && v13 != 46
                && v13 != 45
                && v13 != 95 )
              {
                *a7 = v15;
                return 0;
              }
              v15 += *(_DWORD *)(a1 + 68);
            }
            *a7 = *(_DWORD *)(a1 + 68) + v15;
            return 1;
          }
          else
          {
            *a7 = a2;
            return 0;
          }
        }
      }
    }
    else
    {
      *a7 = a2;
      return 0;
    }
  }
}
