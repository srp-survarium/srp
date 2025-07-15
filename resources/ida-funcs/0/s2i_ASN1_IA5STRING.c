asn1_string_st *__usercall s2i_ASN1_IA5STRING@<eax>(
        int a1@<ebx>,
        v3_ext_method *method,
        v3_ext_ctx *ctx,
        const __m128i *str)
{
  asn1_string_st *v5; // esi

  if ( !str )
  {
    ERR_put_error(a1, 0x22u, 100, 107, ".\\crypto\\x509v3\\v3_ia5.c", 99);
    return 0;
  }
  v5 = ASN1_STRING_type_new(a1, 22);
  if ( !v5 )
    goto err_104;
  if ( !ASN1_STRING_set(v5, str, strlen(str->m128i_i8)) )
  {
    ASN1_STRING_free(v5);
err_104:
    ERR_put_error(a1, 0x22u, 100, 65, ".\\crypto\\x509v3\\v3_ia5.c", 113);
    return 0;
  }
  return v5;
}
