int __cdecl bn_c2i(
        bignum_st **pval,
        const unsigned __int8 *cont,
        int len,
        int utype,
        char *free_cont,
        const ASN1_ITEM_st *it)
{
  bignum_st *v7; // [esp-4h] [ebp-8h]

  if ( !*pval )
    *pval = BN_new();
  if ( BN_bin2bn(cont, len, *pval) )
    return 1;
  if ( *pval )
  {
    v7 = *pval;
    if ( (it->size & 1) != 0 )
    {
      BN_clear_free(v7);
      *pval = 0;
      return 0;
    }
    BN_free(v7);
    *pval = 0;
  }
  return 0;
}
