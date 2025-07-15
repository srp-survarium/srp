int __cdecl cms_ri_cb(int operation, struct ASN1_VALUE_st **pval)
{
  int *v2; // eax
  int v3; // ecx
  int v4; // esi
  x509_st *v5; // esi
  int v7; // esi
  int v8; // eax

  if ( operation == 2 )
  {
    v2 = (int *)*pval;
    v3 = *(_DWORD *)*pval;
    if ( v3 )
    {
      if ( v3 == 2 )
      {
        v7 = v2[1];
        v8 = *(_DWORD *)(v7 + 16);
        if ( v8 )
        {
          OPENSSL_cleanse(v8, *(_DWORD *)(v7 + 20));
          CRYPTO_free(*(void **)(v7 + 16));
        }
      }
    }
    else
    {
      v4 = v2[1];
      if ( *(_DWORD *)(v4 + 20) )
        EVP_PKEY_free(*(evp_pkey_st **)(v4 + 20));
      v5 = *(x509_st **)(v4 + 16);
      if ( v5 )
      {
        X509_free(v5);
        return 1;
      }
    }
  }
  return 1;
}
