int __usercall pkey_hmac_ctrl@<eax>(
        int a1@<edi>,
        env_md_ctx_st *a2@<ebx>,
        evp_pkey_ctx_st *ctx,
        int type,
        int p1,
        unsigned __int8 *p2)
{
  char *data; // ecx

  data = (char *)ctx->data;
  if ( type == 1 )
  {
    *(_DWORD *)data = p2;
    return 1;
  }
  if ( type == 6 )
    return (p2 || p1 <= 0) && p1 >= -1 && ASN1_OCTET_STRING_set((asn1_string_st *)(data + 4), p2, p1);
  if ( type != 7 )
    return -2;
  HMAC_Init_ex(
    a1,
    a2,
    (hmac_ctx_st *)(data + 20),
    *((const __m128i **)ctx->pkey->pkey.ptr + 2),
    *(_DWORD *)ctx->pkey->pkey.ptr,
    *(const env_md_st **)data,
    ctx->engine);
  return 1;
}
