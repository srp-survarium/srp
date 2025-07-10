asn1_string_st *__cdecl s2i_ASN1_IA5STRING(v3_ext_method *method, v3_ext_ctx *ctx, char *str)
{
  asn1_string_st *v4; // esi

  if ( !str )
  {
    ERR_put_error(0x22u, 100, 107, ".\\crypto\\x509v3\\v3_ia5.c", 99);
    return 0;
  }
  v4 = ASN1_STRING_type_new(22);
  if ( !v4 )
    goto err_102;
  if ( !ASN1_STRING_set(v4, str, strlen(str)) )
  {
    ASN1_STRING_free(v4);
err_102:
    ERR_put_error(0x22u, 100, 65, ".\\crypto\\x509v3\\v3_ia5.c", 113);
    return 0;
  }
  return v4;
}
