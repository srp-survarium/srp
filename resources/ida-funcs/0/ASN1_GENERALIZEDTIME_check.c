BOOL __cdecl ASN1_GENERALIZEDTIME_check(asn1_string_st *d)
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
  char v12; // cl
  int v13; // edx
  unsigned __int8 v14; // cl
  int v15; // eax
  int v16; // esi
  char v17; // cl
  char v18; // dl
  int v19; // eax
  int v20; // ecx
  int v21; // ecx

  if ( d->type != 24 )
    return 0;
  length = d->length;
  data = d->data;
  v4 = 0;
  if ( d->length >= 13 )
  {
    for ( i = 0; i < 7; ++i )
    {
      if ( i == 6 )
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
      if ( v4 > length || v11 < min[i] || v11 > max[i] )
        return 0;
    }
    if ( data[v4] != 46 )
      goto LABEL_25;
    if ( ++v4 <= length )
    {
      v12 = data[v4];
      v13 = v4;
      if ( v12 >= 48 )
      {
        do
        {
          if ( v12 > 57 )
            break;
          if ( v4 > length )
            break;
          v12 = data[++v4];
        }
        while ( v12 >= 48 );
        if ( v13 != v4 )
        {
LABEL_25:
          v14 = data[v4];
          if ( v14 == 90 )
            return v4 + 1 == length;
          if ( v14 == 43 || v14 == 45 )
          {
            v15 = v4 + 1;
            if ( v15 + 4 <= length )
            {
              v16 = 0;
              while ( 1 )
              {
                v17 = data[v15];
                if ( v17 < 48 )
                  break;
                if ( v17 > 57 )
                  break;
                v18 = data[v15 + 1];
                v19 = v15 + 1;
                v20 = v17 - 48;
                if ( v18 < 48 )
                  break;
                if ( v18 > 57 )
                  break;
                v21 = v18 + 10 * v20 - 48;
                if ( v21 < dword_6CB4C8[v16] || v21 > dword_6CB4EC[v16] )
                  break;
                ++v16;
                v15 = v19 + 1;
                if ( v16 >= 2 )
                  return v15 == length;
              }
            }
          }
        }
      }
    }
  }
  return 0;
}
