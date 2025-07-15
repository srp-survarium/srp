int __usercall ASN1_INTEGER_set@<eax>(int a1@<ebx>, asn1_string_st *a, int v)
{
  bool v3; // cc
  unsigned __int8 *v4; // eax
  int v6; // ecx
  unsigned int v7; // eax
  int v8; // ecx
  int i; // eax
  _BYTE v10[8]; // [esp+4h] [ebp-Ch]

  v3 = a->length < 5;
  a->type = 2;
  if ( v3 )
  {
    if ( a->data )
      CRYPTO_free(a->data);
    v4 = (unsigned __int8 *)CRYPTO_malloc(5, ".\\crypto\\asn1\\a_int.c", 347);
    a->data = v4;
    if ( v4 )
    {
      *(_DWORD *)v4 = 0;
      v4[4] = 0;
    }
  }
  if ( a->data )
  {
    v6 = v;
    if ( v < 0 )
    {
      v6 = -v;
      a->type = 258;
    }
    v7 = 0;
    do
    {
      if ( !v6 )
        break;
      v10[v7++] = v6;
      v6 >>= 8;
    }
    while ( v7 < 4 );
    v8 = 0;
    for ( i = v7 - 1; i >= 0; --i )
      a->data[v8++] = v10[i];
    a->length = v8;
    return 1;
  }
  else
  {
    ERR_put_error(a1, 0xDu, 118, 65, ".\\crypto\\asn1\\a_int.c", 352);
    return 0;
  }
}
