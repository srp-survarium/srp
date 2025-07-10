int __cdecl sxnet_i2r(v3_ext_method *method, SXNET_st *sx, bio_st *out, int indent)
{
  int v4; // eax
  int i; // esi
  char *v6; // edi
  char *v7; // ebx

  v4 = ASN1_INTEGER_get(sx->version);
  BIO_printf(out, "%*sVersion: %ld (0x%lX)", indent, (const char *)&buf, v4 + 1, v4);
  for ( i = 0; i < sk_num(&sx->ids->stack); ++i )
  {
    v6 = sk_value(&sx->ids->stack, i);
    v7 = i2s_ASN1_INTEGER(0, *(asn1_string_st **)v6);
    BIO_printf(out, "\n%*sZone: %s, User: ", indent, (const char *)&buf, v7);
    CRYPTO_free(v7);
    ASN1_STRING_print(out, *((const asn1_string_st **)v6 + 1));
  }
  return 1;
}
