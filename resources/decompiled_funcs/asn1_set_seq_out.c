int __cdecl asn1_set_seq_out(
        stack_st_ASN1_VALUE *sk,
        unsigned __int8 **out,
        int skcontlen,
        const ASN1_ITEM_st *item,
        int do_sort,
        int iclass)
{
  int v6; // ebx
  int v7; // eax
  char *v8; // ebp
  void *v9; // eax
  int v11; // edi
  struct ASN1_VALUE_st **v12; // edi
  unsigned int v13; // eax
  int v14; // ebx
  unsigned int *v15; // edi
  int v16; // edi
  void **v17; // ebx
  unsigned __int8 *dst; // [esp+10h] [ebp-10h] BYREF
  struct ASN1_VALUE_st *pval; // [esp+14h] [ebp-Ch] BYREF
  char *v20; // [esp+18h] [ebp-8h]
  void *str; // [esp+1Ch] [ebp-4h]

  v6 = 0;
  dst = 0;
  if ( do_sort && sk_num(&sk->stack) >= 2 )
  {
    v7 = sk_num(&sk->stack);
    v8 = (char *)CRYPTO_malloc(12 * v7, ".\\crypto\\asn1\\tasn_enc.c", 455);
    v20 = v8;
    v9 = CRYPTO_malloc(skcontlen, ".\\crypto\\asn1\\tasn_enc.c", 456);
    str = v9;
    if ( !v8 || !v9 )
      return 0;
    dst = (unsigned __int8 *)v9;
    if ( sk_num(&sk->stack) > 0 )
    {
      v12 = (struct ASN1_VALUE_st **)(v8 + 8);
      do
      {
        pval = (struct ASN1_VALUE_st *)sk_value(&sk->stack, v6);
        *(v12 - 2) = (struct ASN1_VALUE_st *)dst;
        *(v12 - 1) = (struct ASN1_VALUE_st *)ASN1_item_ex_i2d(&pval, &dst, item, -1, iclass);
        *v12 = pval;
        ++v6;
        v12 += 3;
      }
      while ( v6 < sk_num(&sk->stack) );
      v8 = v20;
    }
    v13 = sk_num(&sk->stack);
    qsort(v8, v13, 0xCu, (int (__cdecl *)(const void *, const void *))der_cmp);
    dst = *out;
    v14 = 0;
    if ( sk_num(&sk->stack) > 0 )
    {
      v15 = (unsigned int *)(v8 + 4);
      do
      {
        memcpy(dst, (unsigned __int8 *)*(v15 - 1), *v15);
        dst += *v15;
        ++v14;
        v15 += 3;
      }
      while ( v14 < sk_num(&sk->stack) );
    }
    *out = dst;
    if ( do_sort == 2 )
    {
      v16 = 0;
      if ( sk_num(&sk->stack) > 0 )
      {
        v17 = (void **)(v8 + 8);
        do
        {
          sk_set(&sk->stack, v16++, *v17);
          v17 += 3;
        }
        while ( v16 < sk_num(&sk->stack) );
      }
    }
    CRYPTO_free(v8);
    CRYPTO_free(str);
    return 1;
  }
  v11 = 0;
  if ( sk_num(&sk->stack) <= 0 )
    return 1;
  do
  {
    pval = (struct ASN1_VALUE_st *)sk_value(&sk->stack, v11);
    ASN1_item_ex_i2d(&pval, out, item, -1, iclass);
    ++v11;
  }
  while ( v11 < sk_num(&sk->stack) );
  return 1;
}
