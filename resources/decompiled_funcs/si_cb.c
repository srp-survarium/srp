int __cdecl si_cb(int operation, struct ASN1_VALUE_st **pval)
{
  if ( operation == 3 )
    EVP_PKEY_free(*((evp_pkey_st **)*pval + 7));
  return 1;
}
