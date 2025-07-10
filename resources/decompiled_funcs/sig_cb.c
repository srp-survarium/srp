int __cdecl sig_cb(int operation, struct ASN1_VALUE_st **pval)
{
  struct ASN1_VALUE_st *v2; // eax

  if ( operation )
    return 1;
  v2 = (struct ASN1_VALUE_st *)CRYPTO_malloc(8, ".\\crypto\\dsa\\dsa_asn1.c", 71);
  if ( v2 )
  {
    *(_DWORD *)v2 = 0;
    *((_DWORD *)v2 + 1) = 0;
    *pval = v2;
    return 2;
  }
  else
  {
    ERR_put_error(0xAu, 114, 65, ".\\crypto\\dsa\\dsa_asn1.c", 74);
    return 0;
  }
}
