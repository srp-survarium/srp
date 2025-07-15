int __usercall pubkey_cb@<eax>(int a1@<edi>, int operation, struct ASN1_VALUE_st **pval)
{
  if ( operation == 3 )
    EVP_PKEY_free(a1, *((evp_pkey_st **)*pval + 2));
  return 1;
}
