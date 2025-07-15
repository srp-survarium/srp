int __usercall bn_c2i@<eax>(
        int a1@<ebx>,
        bignum_st **pval,
        unsigned __int8 *cont,
        int len,
        int utype,
        char *free_cont,
        const ASN1_ITEM_st *it)
{
  bignum_st *v8; // [esp-4h] [ebp-8h]

  if ( !*pval )
    *pval = BN_new(a1);
  if ( BN_bin2bn(cont, len, *pval) )
    return 1;
  if ( *pval )
  {
    v8 = *pval;
    if ( (it->size & 1) != 0 )
    {
      BN_clear_free(v8);
      *pval = 0;
      return 0;
    }
    BN_free(v8);
    *pval = 0;
  }
  return 0;
}
