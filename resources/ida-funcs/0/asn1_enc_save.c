int __cdecl asn1_enc_save(struct ASN1_VALUE_st **pval, const __m128i *in, unsigned int inlen, const ASN1_ITEM_st *it)
{
  _BYTE *funcs; // eax
  char *v5; // esi
  int result; // eax

  if ( !pval )
    return 1;
  if ( !*pval )
    return 1;
  funcs = it->funcs;
  if ( !funcs )
    return 1;
  if ( (funcs[4] & 2) == 0 )
    return 1;
  v5 = (char *)*pval + *((_DWORD *)funcs + 5);
  if ( !v5 )
    return 1;
  if ( *(_DWORD *)v5 )
    CRYPTO_free(*(void **)v5);
  result = (int)CRYPTO_malloc(inlen, ".\\crypto\\asn1\\tasn_utl.c", 175);
  *(_DWORD *)v5 = result;
  if ( result )
  {
    memcpy(result, in, inlen);
    *((_DWORD *)v5 + 1) = inlen;
    *((_DWORD *)v5 + 2) = 0;
    return 1;
  }
  return result;
}
