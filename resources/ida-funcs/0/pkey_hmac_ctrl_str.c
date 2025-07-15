unsigned __int8 *__cdecl pkey_hmac_ctrl_str(evp_pkey_ctx_st *ctx, const char *type, char *value)
{
  unsigned __int8 *result; // eax
  unsigned __int8 *v4; // edi
  BOOL v5; // esi

  if ( !value )
    return 0;
  if ( !strcmp(type, "key") )
    return (unsigned __int8 *)(ASN1_OCTET_STRING_set(
                                 (asn1_string_st *)((char *)ctx->data + 4),
                                 (unsigned __int8 *)value,
                                 -1) != 0);
  if ( strcmp(type, "hexkey") )
    return (unsigned __int8 *)-2;
  result = string_to_hex(value, (int *)&value);
  v4 = result;
  if ( result )
  {
    if ( (int)value >= -1 )
    {
      v5 = ASN1_OCTET_STRING_set((asn1_string_st *)((char *)ctx->data + 4), result, (int)value) != 0;
      CRYPTO_free(v4);
      return (unsigned __int8 *)v5;
    }
    else
    {
      CRYPTO_free(result);
      return 0;
    }
  }
  return result;
}
