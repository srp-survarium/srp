int __usercall sxnet_i2r@<eax>(char *a1@<ebx>, v3_ext_method *method, SXNET_st *sx, bio_st *out, int indent)
{
  int v5; // eax
  int i; // esi
  char *v7; // edi

  v5 = ASN1_INTEGER_get(sx->version);
  BIO_printf(out, "%*sVersion: %ld (0x%lX)", indent, uri, v5 + 1, v5);
  for ( i = 0; i < sk_num(&sx->ids->stack); ++i )
  {
    v7 = sk_value(&sx->ids->stack, i);
    a1 = i2s_ASN1_INTEGER((int)a1, 0, *(asn1_string_st **)v7);
    BIO_printf(out, "\n%*sZone: %s, User: ", indent, uri, a1);
    CRYPTO_free(a1);
    ASN1_STRING_print(out, *((const asn1_string_st **)v7 + 1));
  }
  return 1;
}
