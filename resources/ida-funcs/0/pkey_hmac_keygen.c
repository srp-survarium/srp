int __cdecl pkey_hmac_keygen(evp_pkey_ctx_st *ctx, evp_pkey_st *pkey)
{
  char *data; // eax
  char *v4; // eax

  data = (char *)ctx->data;
  if ( !*((_DWORD *)data + 3) )
    return 0;
  v4 = (char *)ASN1_OCTET_STRING_dup((const asn1_string_st *)(data + 4));
  if ( !v4 )
    return 0;
  EVP_PKEY_assign(pkey, (void *)0x357, v4);
  return 1;
}
