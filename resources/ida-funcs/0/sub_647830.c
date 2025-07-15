int __cdecl sub_647830(int a1, int a2)
{
  int v3; // [esp+0h] [ebp-18h]
  int v4; // [esp+4h] [ebp-14h]
  _DWORD *v5; // [esp+8h] [ebp-10h]
  _BYTE *j; // [esp+Ch] [ebp-Ch]
  _BYTE *i; // [esp+10h] [ebp-8h]
  _DWORD *v8; // [esp+14h] [ebp-4h]

  v8 = *(_DWORD **)(a1 + 356);
  for ( i = *(_BYTE **)a2; *i; ++i )
  {
    if ( *i == 58 )
    {
      for ( j = *(_BYTE **)a2; j != i; ++j )
      {
        if ( v8[23] != v8[22] || (unsigned __int8)sub_649210(v8 + 20) )
        {
          *(_BYTE *)v8[23]++ = *j;
          v4 = 1;
        }
        else
        {
          v4 = 0;
        }
        if ( !v4 )
          return 0;
      }
      if ( v8[23] != v8[22] || (unsigned __int8)sub_649210(v8 + 20) )
      {
        *(_BYTE *)v8[23]++ = 0;
        v3 = 1;
      }
      else
      {
        v3 = 0;
      }
      if ( !v3 )
        return 0;
      v5 = (_DWORD *)sub_648950(a1, v8 + 15, v8[24], 8);
      if ( !v5 )
        return 0;
      if ( *v5 == v8[24] )
        v8[24] = v8[23];
      else
        v8[23] = v8[24];
      *(_DWORD *)(a2 + 4) = v5;
    }
  }
  return 1;
}
