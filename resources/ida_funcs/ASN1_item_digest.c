int __usercall ASN1_item_digest@<eax>(
        unsigned int a1@<edi>,
        const ASN1_ITEM_st *it,
        const env_md_st *type,
        struct ASN1_VALUE_st *asn,
        unsigned __int8 *md,
        unsigned int *len)
{
  unsigned int v6; // eax
  unsigned __int8 *out; // [esp+0h] [ebp-4h] BYREF

  out = 0;
  v6 = ASN1_item_i2d(asn, &out, it);
  if ( !out )
    return 0;
  EVP_Digest(a1, out, v6, md, len, type, 0);
  CRYPTO_free(out);
  return 1;
}
