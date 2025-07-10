int __cdecl ASN1_INTEGER_set(asn1_string_st *a, int v)
{
  bool v2; // cc
  unsigned __int8 *v3; // eax
  int v5; // ecx
  unsigned int v6; // eax
  int v7; // ecx
  int i; // eax
  _BYTE v9[8]; // [esp+4h] [ebp-Ch]

  v2 = a->length < 5;
  a->type = 2;
  if ( v2 )
  {
    if ( a->data )
      CRYPTO_free(a->data);
    v3 = (unsigned __int8 *)CRYPTO_malloc(5, ".\\crypto\\asn1\\a_int.c", 347);
    a->data = v3;
    if ( v3 )
    {
      *(_DWORD *)v3 = 0;
      v3[4] = 0;
    }
  }
  if ( a->data )
  {
    v5 = v;
    if ( v < 0 )
    {
      v5 = -v;
      a->type = 258;
    }
    v6 = 0;
    do
    {
      if ( !v5 )
        break;
      v9[v6++] = v5;
      v5 >>= 8;
    }
    while ( v6 < 4 );
    v7 = 0;
    for ( i = v6 - 1; i >= 0; --i )
      a->data[v7++] = v9[i];
    a->length = v7;
    return 1;
  }
  else
  {
    ERR_put_error(0xDu, 118, 65, ".\\crypto\\asn1\\a_int.c", 352);
    return 0;
  }
}
