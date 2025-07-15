int __usercall sig_cb@<eax>(int a1@<ebx>, int operation, struct ASN1_VALUE_st **pval)
{
  struct ASN1_VALUE_st *v3; // eax

  if ( operation )
    return 1;
  v3 = (struct ASN1_VALUE_st *)CRYPTO_malloc(8, ".\\crypto\\dsa\\dsa_asn1.c", 71);
  if ( v3 )
  {
    *(_DWORD *)v3 = 0;
    *((_DWORD *)v3 + 1) = 0;
    *pval = v3;
    return 2;
  }
  else
  {
    ERR_put_error(a1, 0xAu, 114, 65, ".\\crypto\\dsa\\dsa_asn1.c", 74);
    return 0;
  }
}
