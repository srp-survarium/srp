int __usercall si_cb@<eax>(int a1@<edi>, int operation, struct ASN1_VALUE_st **pval)
{
  if ( operation == 3 )
    EVP_PKEY_free(a1, *((evp_pkey_st **)*pval + 7));
  return 1;
}
