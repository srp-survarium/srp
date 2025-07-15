int __usercall ASN1_item_digest@<eax>(
        int a1@<edi>,
        engine_st *a2@<ebx>,
        const ASN1_ITEM_st *it,
        const env_md_st *type,
        struct ASN1_VALUE_st *asn,
        unsigned __int8 *md,
        unsigned int *len)
{
  unsigned int v7; // eax
  unsigned __int8 *out; // [esp+0h] [ebp-4h] BYREF

  out = 0;
  v7 = ASN1_item_i2d(asn, &out, it);
  if ( !out )
    return 0;
  EVP_Digest(a1, a2, out, v7, md, len, type, 0);
  CRYPTO_free(out);
  return 1;
}
