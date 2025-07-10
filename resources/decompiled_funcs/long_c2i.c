int __cdecl long_c2i(
        struct ASN1_VALUE_st **pval,
        const unsigned __int8 *cont,
        int len,
        int utype,
        char *free_cont,
        const ASN1_ITEM_st *it)
{
  BOOL v7; // ebp
  int v8; // ecx
  int i; // eax
  int v10; // ecx
  int v11; // edx
  struct ASN1_VALUE_st *v12; // eax

  if ( len > 4 )
  {
    ERR_put_error(0xDu, 166, 128, ".\\crypto\\asn1\\x_long.c", 150);
    return 0;
  }
  v7 = len && *(char *)cont < 0;
  v8 = 0;
  for ( i = 0; i < len; v8 = v11 | v10 )
  {
    v10 = v8 << 8;
    if ( v7 )
      v11 = (unsigned __int8)~cont[i];
    else
      v11 = cont[i];
    ++i;
  }
  v12 = (struct ASN1_VALUE_st *)v8;
  if ( v7 )
    v12 = (struct ASN1_VALUE_st *)(-1 - v8);
  if ( v12 == (struct ASN1_VALUE_st *)it->size )
  {
    ERR_put_error(0xDu, 166, 128, ".\\crypto\\asn1\\x_long.c", 168);
    return 0;
  }
  *pval = v12;
  return 1;
}
