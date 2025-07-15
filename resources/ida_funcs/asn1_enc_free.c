void __cdecl asn1_enc_free(struct ASN1_VALUE_st **pval, const ASN1_ITEM_st *it)
{
  _DWORD *funcs; // eax
  char *v3; // esi

  if ( pval )
  {
    if ( *pval )
    {
      funcs = it->funcs;
      if ( funcs )
      {
        if ( (funcs[1] & 2) != 0 )
        {
          v3 = (char *)*pval + funcs[5];
          if ( v3 )
          {
            if ( *(_DWORD *)v3 )
              CRYPTO_free(*(void **)v3);
            *(_DWORD *)v3 = 0;
            *((_DWORD *)v3 + 1) = 0;
            *((_DWORD *)v3 + 2) = 1;
          }
        }
      }
    }
  }
}
