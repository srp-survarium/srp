char __cdecl sub_648240(int a1, _BYTE *i)
{
  int v3; // [esp+0h] [ebp-24h]
  int v4; // [esp+4h] [ebp-20h]
  int v5; // [esp+8h] [ebp-1Ch]
  int v6; // [esp+Ch] [ebp-18h]
  int v7; // [esp+10h] [ebp-14h]
  _DWORD *v8; // [esp+14h] [ebp-10h]
  int v9; // [esp+18h] [ebp-Ch]
  int v10; // [esp+1Ch] [ebp-8h]
  _BYTE *v11; // [esp+20h] [ebp-4h]

  v10 = *(_DWORD *)(a1 + 356);
  v11 = i;
  while ( *i )
  {
    if ( *v11 != 12 && *v11 )
    {
      if ( *v11 == 61 )
      {
        if ( *(_DWORD *)(a1 + 428) == *(_DWORD *)(a1 + 432) )
        {
          v8 = (_DWORD *)(v10 + 152);
        }
        else
        {
          if ( *(_DWORD *)(a1 + 428) != *(_DWORD *)(a1 + 424) || (unsigned __int8)sub_649210(a1 + 416) )
          {
            *(_BYTE *)(*(_DWORD *)(a1 + 428))++ = 0;
            v6 = 1;
          }
          else
          {
            v6 = 0;
          }
          if ( !v6 )
            return 0;
          v8 = (_DWORD *)sub_648950(a1, v10 + 60, *(_DWORD *)(a1 + 432), 8);
          if ( !v8 )
            return 0;
          if ( *v8 == *(_DWORD *)(a1 + 432) )
          {
            *v8 = sub_649090(v10 + 80, *v8);
            if ( !*v8 )
              return 0;
          }
          *(_DWORD *)(a1 + 428) = *(_DWORD *)(a1 + 432);
        }
        for ( i = v11 + 1; *i != 12 && *i; ++i )
        {
          if ( *(_DWORD *)(a1 + 428) != *(_DWORD *)(a1 + 424) || (unsigned __int8)sub_649210(a1 + 416) )
          {
            *(_BYTE *)(*(_DWORD *)(a1 + 428))++ = *i;
            v5 = 1;
          }
          else
          {
            v5 = 0;
          }
          if ( !v5 )
            return 0;
        }
        if ( *(_DWORD *)(a1 + 428) != *(_DWORD *)(a1 + 424) || (unsigned __int8)sub_649210(a1 + 416) )
        {
          *(_BYTE *)(*(_DWORD *)(a1 + 428))++ = 0;
          v4 = 1;
        }
        else
        {
          v4 = 0;
        }
        if ( !v4 )
          return 0;
        if ( sub_642D30(a1, v8, 0, *(const __m128i **)(a1 + 432), (_DWORD *)(a1 + 372)) )
          return 0;
        *(_DWORD *)(a1 + 428) = *(_DWORD *)(a1 + 432);
        if ( *i )
          ++i;
        v11 = i;
      }
      else
      {
        if ( *(_DWORD *)(a1 + 428) != *(_DWORD *)(a1 + 424) || (unsigned __int8)sub_649210(a1 + 416) )
        {
          *(_BYTE *)(*(_DWORD *)(a1 + 428))++ = *v11;
          v3 = 1;
        }
        else
        {
          v3 = 0;
        }
        if ( !v3 )
          return 0;
        ++v11;
      }
    }
    else
    {
      if ( *(_DWORD *)(a1 + 428) != *(_DWORD *)(a1 + 424) || (unsigned __int8)sub_649210(a1 + 416) )
      {
        *(_BYTE *)(*(_DWORD *)(a1 + 428))++ = 0;
        v7 = 1;
      }
      else
      {
        v7 = 0;
      }
      if ( !v7 )
        return 0;
      v9 = sub_648950(a1, v10, *(_DWORD *)(a1 + 432), 0);
      if ( v9 )
        *(_BYTE *)(v9 + 32) = 1;
      if ( *v11 )
        ++v11;
      i = v11;
      *(_DWORD *)(a1 + 428) = *(_DWORD *)(a1 + 432);
    }
  }
  return 1;
}
