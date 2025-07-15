int __cdecl sub_647CC0(int a1)
{
  int v2; // [esp+0h] [ebp-54h]
  int v3; // [esp+4h] [ebp-50h]
  int v4; // [esp+8h] [ebp-4Ch]
  int v5; // [esp+Ch] [ebp-48h]
  int v6; // [esp+10h] [ebp-44h]
  int v7; // [esp+14h] [ebp-40h]
  int v8; // [esp+18h] [ebp-3Ch]
  int v9; // [esp+1Ch] [ebp-38h]
  int v10; // [esp+20h] [ebp-34h]
  int v11; // [esp+24h] [ebp-30h]
  _BYTE *m; // [esp+28h] [ebp-2Ch]
  int v13; // [esp+2Ch] [ebp-28h]
  _BYTE *j; // [esp+30h] [ebp-24h]
  int v15; // [esp+34h] [ebp-20h]
  int k; // [esp+38h] [ebp-1Ch]
  int v17; // [esp+3Ch] [ebp-18h]
  int i; // [esp+40h] [ebp-14h]
  int v19; // [esp+44h] [ebp-10h]
  _BYTE v20[11]; // [esp+48h] [ebp-Ch] BYREF
  char v21; // [esp+53h] [ebp-1h]

  v19 = *(_DWORD *)(a1 + 356);
  v21 = 0;
  if ( *(_DWORD *)(v19 + 156) )
  {
    if ( *(_DWORD *)(a1 + 428) != *(_DWORD *)(a1 + 424) || (unsigned __int8)sub_649210(a1 + 416) )
    {
      *(_BYTE *)(*(_DWORD *)(a1 + 428))++ = 61;
      v10 = 1;
    }
    else
    {
      v10 = 0;
    }
    if ( !v10 )
      return 0;
    v17 = *(_DWORD *)(*(_DWORD *)(v19 + 156) + 20);
    if ( *(_BYTE *)(a1 + 472) )
      --v17;
    for ( i = 0; i < v17; ++i )
    {
      if ( *(_DWORD *)(a1 + 428) != *(_DWORD *)(a1 + 424) || (unsigned __int8)sub_649210(a1 + 416) )
      {
        *(_BYTE *)(*(_DWORD *)(a1 + 428))++ = *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(v19 + 156) + 16) + i);
        v9 = 1;
      }
      else
      {
        v9 = 0;
      }
      if ( !v9 )
        return 0;
    }
    v21 = 1;
  }
  sub_648E70(v20, v19 + 60);
  while ( 1 )
  {
    v15 = sub_648EA0(v20);
    if ( !v15 )
      break;
    if ( *(_DWORD *)(v15 + 4) )
    {
      if ( v21 )
      {
        if ( *(_DWORD *)(a1 + 428) != *(_DWORD *)(a1 + 424) || (unsigned __int8)sub_649210(a1 + 416) )
        {
          *(_BYTE *)(*(_DWORD *)(a1 + 428))++ = 12;
          v8 = 1;
        }
        else
        {
          v8 = 0;
        }
        if ( !v8 )
          return 0;
      }
      for ( j = *(_BYTE **)v15; *j; ++j )
      {
        if ( *(_DWORD *)(a1 + 428) != *(_DWORD *)(a1 + 424) || (unsigned __int8)sub_649210(a1 + 416) )
        {
          *(_BYTE *)(*(_DWORD *)(a1 + 428))++ = *j;
          v7 = 1;
        }
        else
        {
          v7 = 0;
        }
        if ( !v7 )
          return 0;
      }
      if ( *(_DWORD *)(a1 + 428) != *(_DWORD *)(a1 + 424) || (unsigned __int8)sub_649210(a1 + 416) )
      {
        *(_BYTE *)(*(_DWORD *)(a1 + 428))++ = 61;
        v6 = 1;
      }
      else
      {
        v6 = 0;
      }
      if ( !v6 )
        return 0;
      v13 = *(_DWORD *)(*(_DWORD *)(v15 + 4) + 20);
      if ( *(_BYTE *)(a1 + 472) )
        --v13;
      for ( k = 0; k < v13; ++k )
      {
        if ( *(_DWORD *)(a1 + 428) != *(_DWORD *)(a1 + 424) || (unsigned __int8)sub_649210(a1 + 416) )
        {
          *(_BYTE *)(*(_DWORD *)(a1 + 428))++ = *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(v15 + 4) + 16) + k);
          v5 = 1;
        }
        else
        {
          v5 = 0;
        }
        if ( !v5 )
          return 0;
      }
      v21 = 1;
    }
  }
  sub_648E70(v20, v19);
  while ( 1 )
  {
    v11 = sub_648EA0(v20);
    if ( !v11 )
      break;
    if ( *(_BYTE *)(v11 + 32) )
    {
      if ( v21 )
      {
        if ( *(_DWORD *)(a1 + 428) != *(_DWORD *)(a1 + 424) || (unsigned __int8)sub_649210(a1 + 416) )
        {
          *(_BYTE *)(*(_DWORD *)(a1 + 428))++ = 12;
          v4 = 1;
        }
        else
        {
          v4 = 0;
        }
        if ( !v4 )
          return 0;
      }
      for ( m = *(_BYTE **)v11; *m; ++m )
      {
        if ( *(_DWORD *)(a1 + 428) != *(_DWORD *)(a1 + 424) || (unsigned __int8)sub_649210(a1 + 416) )
        {
          *(_BYTE *)(*(_DWORD *)(a1 + 428))++ = *m;
          v3 = 1;
        }
        else
        {
          v3 = 0;
        }
        if ( !v3 )
          return 0;
      }
      v21 = 1;
    }
  }
  if ( *(_DWORD *)(a1 + 428) != *(_DWORD *)(a1 + 424) || (unsigned __int8)sub_649210(a1 + 416) )
  {
    *(_BYTE *)(*(_DWORD *)(a1 + 428))++ = 0;
    v2 = 1;
  }
  else
  {
    v2 = 0;
  }
  if ( v2 )
    return *(_DWORD *)(a1 + 432);
  else
    return 0;
}
