BOOL __cdecl ASN1_UTCTIME_check(asn1_string_st *d)
{
  int length; // ebx
  unsigned __int8 *data; // edi
  int v4; // eax
  int i; // esi
  unsigned __int8 v6; // cl
  char v7; // cl
  int v8; // eax
  int v9; // ecx
  char v10; // dl
  int v11; // ecx
  unsigned __int8 v12; // cl
  int v13; // eax
  int v14; // esi
  char v15; // cl
  char v16; // dl
  int v17; // eax
  int v18; // ecx
  int v19; // ecx

  if ( d->type != 23 )
    return 0;
  length = d->length;
  data = d->data;
  v4 = 0;
  if ( d->length >= 11 )
  {
    for ( i = 0; i < 6; ++i )
    {
      if ( i == 5 )
      {
        v6 = data[v4];
        if ( v6 == 90 || v6 == 43 || v6 == 45 )
          break;
      }
      v7 = data[v4];
      if ( v7 < 48 )
        return 0;
      if ( v7 > 57 )
        return 0;
      v8 = v4 + 1;
      v9 = v7 - 48;
      if ( v8 > length )
        return 0;
      v10 = data[v8];
      if ( v10 < 48 )
        return 0;
      if ( v10 > 57 )
        return 0;
      v4 = v8 + 1;
      v11 = v10 + 10 * v9 - 48;
      if ( v4 > length || v11 < min_0[i] || v11 > max_0[i] )
        return 0;
    }
    v12 = data[v4];
    if ( v12 == 90 )
      return ++v4 == length;
    if ( v12 != 43 && v12 != 45 )
      return v4 == length;
    v13 = v4 + 1;
    if ( v13 + 4 <= length )
    {
      v14 = 0;
      while ( 1 )
      {
        v15 = data[v13];
        if ( v15 < 48 )
          break;
        if ( v15 > 57 )
          break;
        v16 = data[v13 + 1];
        v17 = v13 + 1;
        v18 = v15 - 48;
        if ( v16 < 48 )
          break;
        if ( v16 > 57 )
          break;
        v19 = v16 + 10 * v18 - 48;
        if ( v19 < dword_839878[v14] || v19 > dword_839898[v14] )
          break;
        ++v14;
        v13 = v17 + 1;
        if ( v14 >= 2 )
          return v13 == length;
      }
    }
  }
  return 0;
}
