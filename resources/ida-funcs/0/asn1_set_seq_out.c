int __usercall asn1_set_seq_out@<eax>(
        _DWORD *a1@<edi>,
        stack_st_ASN1_VALUE *sk,
        unsigned __int8 **out,
        int skcontlen,
        const ASN1_ITEM_st *item,
        int do_sort,
        int iclass)
{
  int v7; // ebx
  int v8; // eax
  char *v9; // ebp
  void *v10; // eax
  int v12; // edi
  unsigned int v13; // eax
  int v14; // ebx
  unsigned int *v15; // edi
  int v16; // edi
  void **v17; // ebx
  unsigned __int8 *dst; // [esp+10h] [ebp-10h] BYREF
  struct ASN1_VALUE_st *v19; // [esp+14h] [ebp-Ch] BYREF
  char *v20; // [esp+18h] [ebp-8h]
  void *str; // [esp+1Ch] [ebp-4h]

  v7 = 0;
  dst = 0;
  if ( do_sort && sk_num(&sk->stack) >= 2 )
  {
    v8 = sk_num(&sk->stack);
    v9 = (char *)CRYPTO_malloc(12 * v8, ".\\crypto\\asn1\\tasn_enc.c", 455);
    v20 = v9;
    v10 = CRYPTO_malloc(skcontlen, ".\\crypto\\asn1\\tasn_enc.c", 456);
    str = v10;
    if ( !v9 || !v10 )
      return 0;
    dst = (unsigned __int8 *)v10;
    if ( sk_num(&sk->stack) > 0 )
    {
      a1 = v9 + 8;
      do
      {
        v19 = (struct ASN1_VALUE_st *)sk_value(&sk->stack, v7);
        *(a1 - 2) = dst;
        *(a1 - 1) = ASN1_item_ex_i2d(&v19, &dst, item, -1, iclass);
        *a1 = v19;
        ++v7;
        a1 += 3;
      }
      while ( v7 < sk_num(&sk->stack) );
      v9 = v20;
    }
    v13 = sk_num(&sk->stack);
    qsort((int)a1, v9, v13, 0xCu, (int (__cdecl *)(const void *, const void *))der_cmp);
    dst = *out;
    v14 = 0;
    if ( sk_num(&sk->stack) > 0 )
    {
      v15 = (unsigned int *)(v9 + 4);
      do
      {
        memcpy((int)dst, (const __m128i *)*(v15 - 1), *v15);
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
        v17 = (void **)(v9 + 8);
        do
        {
          sk_set(&sk->stack, v16++, *v17);
          v17 += 3;
        }
        while ( v16 < sk_num(&sk->stack) );
      }
    }
    CRYPTO_free(v9);
    CRYPTO_free(str);
    return 1;
  }
  v12 = 0;
  if ( sk_num(&sk->stack) <= 0 )
    return 1;
  do
  {
    v19 = (struct ASN1_VALUE_st *)sk_value(&sk->stack, v12);
    ASN1_item_ex_i2d(&v19, out, item, -1, iclass);
    ++v12;
  }
  while ( v12 < sk_num(&sk->stack) );
  return 1;
}
