void __cdecl ASN1_put_object(unsigned __int8 **pp, int constructed, int length, int tag, char xclass)
{
  _BYTE *v5; // ecx
  int v6; // ebx
  int v7; // eax
  _BYTE *v8; // ecx
  _BYTE *v9; // ecx
  int v10; // eax
  int i; // edx
  int v12; // edi
  int v13; // esi
  int v14; // edx
  int v15; // eax
  int j; // esi
  _BYTE *v17; // ecx
  int k; // esi

  v5 = *pp;
  v6 = tag;
  v7 = xclass & 0xC0 | (constructed != 0 ? 0x20 : 0);
  if ( tag >= 31 )
  {
    *v5 = v7 | 0x1F;
    v9 = v5 + 1;
    v10 = 0;
    for ( i = tag; i > 0; i >>= 7 )
      ++v10;
    v12 = v10;
    if ( v10 > 0 )
    {
      v13 = v10 - 1;
      do
      {
        v9[--v10] = v6 & 0x7F;
        if ( v10 != v13 )
          v9[v10] = v6 & 0x7F | 0x80;
        v6 >>= 7;
      }
      while ( v10 > 0 );
    }
    v8 = &v9[v12];
  }
  else
  {
    *v5 = v7 | tag & 0x1F;
    v8 = v5 + 1;
  }
  if ( constructed == 2 )
  {
    *v8 = 0x80;
    *pp = v8 + 1;
  }
  else
  {
    v14 = length;
    if ( length > 127 )
    {
      v15 = 0;
      for ( j = length; j > 0; j >>= 8 )
        ++v15;
      *v8 = v15 | 0x80;
      v17 = v8 + 1;
      for ( k = v15; v15 > 0; v14 >>= 8 )
        v17[--v15] = v14;
      *pp = &v17[k];
    }
    else
    {
      *v8 = length;
      *pp = v8 + 1;
    }
  }
}
