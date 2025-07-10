int __cdecl pkey_hmac_copy(evp_pkey_ctx_st *dst, evp_pkey_ctx_st *src)
{
  int result; // eax
  char *data; // edi
  char *v4; // esi
  const unsigned __int8 *v5; // eax

  result = pkey_hmac_init(dst);
  if ( result )
  {
    data = (char *)dst->data;
    v4 = (char *)src->data;
    *(_DWORD *)data = *(_DWORD *)v4;
    HMAC_CTX_init((hmac_ctx_st *)(data + 20));
    HMAC_CTX_copy((hmac_ctx_st *)(data + 20), (hmac_ctx_st *)(v4 + 20));
    v5 = (const unsigned __int8 *)*((_DWORD *)v4 + 3);
    if ( !v5 )
      return 1;
    result = ASN1_OCTET_STRING_set((asn1_string_st *)(data + 4), v5, *((_DWORD *)v4 + 1));
    if ( result )
      return 1;
  }
  return result;
}
