int __usercall long_c2i@<eax>(
        int a1@<ebx>,
        struct ASN1_VALUE_st **pval,
        char *cont,
        int len,
        int utype,
        char *free_cont,
        const ASN1_ITEM_st *it)
{
  BOOL v8; // ebp
  int v9; // ecx
  int i; // eax
  int v11; // ecx
  int v12; // edx
  struct ASN1_VALUE_st *v13; // eax

  if ( len > 4 )
  {
    ERR_put_error(a1, 0xDu, 166, 128, ".\\crypto\\asn1\\x_long.c", 150);
    return 0;
  }
  v8 = len && *cont < 0;
  v9 = 0;
  for ( i = 0; i < len; v9 = v12 | v11 )
  {
    v11 = v9 << 8;
    if ( v8 )
      v12 = (unsigned __int8)~cont[i];
    else
      v12 = (unsigned __int8)cont[i];
    ++i;
  }
  v13 = (struct ASN1_VALUE_st *)v9;
  if ( v8 )
    v13 = (struct ASN1_VALUE_st *)(-1 - v9);
  if ( v13 == (struct ASN1_VALUE_st *)it->size )
  {
    ERR_put_error(a1, 0xDu, 166, 128, ".\\crypto\\asn1\\x_long.c", 168);
    return 0;
  }
  *pval = v13;
  return 1;
}
