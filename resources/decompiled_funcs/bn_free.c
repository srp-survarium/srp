void __cdecl bn_free(struct ASN1_VALUE_st **pval, const ASN1_ITEM_st *it)
{
  bignum_st *v2; // [esp-4h] [ebp-8h]

  if ( *pval )
  {
    v2 = (bignum_st *)*pval;
    if ( (it->size & 1) != 0 )
      BN_clear_free(v2);
    else
      BN_free(v2);
    *pval = 0;
  }
}
