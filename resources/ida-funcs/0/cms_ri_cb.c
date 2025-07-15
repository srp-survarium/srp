int __usercall cms_ri_cb@<eax>(int a1@<edi>, int operation, struct ASN1_VALUE_st **pval)
{
  int *v3; // eax
  int v4; // ecx
  int v5; // esi
  x509_st *v6; // esi
  int v8; // esi
  int v9; // eax

  if ( operation == 2 )
  {
    v3 = (int *)*pval;
    v4 = *(_DWORD *)*pval;
    if ( v4 )
    {
      if ( v4 == 2 )
      {
        v8 = v3[1];
        v9 = *(_DWORD *)(v8 + 16);
        if ( v9 )
        {
          OPENSSL_cleanse(v9, *(_DWORD *)(v8 + 20));
          CRYPTO_free(*(void **)(v8 + 16));
        }
      }
    }
    else
    {
      v5 = v3[1];
      if ( *(_DWORD *)(v5 + 20) )
        EVP_PKEY_free(a1, *(evp_pkey_st **)(v5 + 20));
      v6 = *(x509_st **)(v5 + 16);
      if ( v6 )
      {
        X509_free(v6);
        return 1;
      }
    }
  }
  return 1;
}
