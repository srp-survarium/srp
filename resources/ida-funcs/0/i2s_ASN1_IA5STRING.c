char *__usercall i2s_ASN1_IA5STRING@<eax>(int a1@<ebx>, v3_ext_method *method, asn1_string_st *ia5)
{
  _BYTE *v3; // esi

  if ( !ia5 || !ia5->length )
    return 0;
  v3 = CRYPTO_malloc(ia5->length + 1, ".\\crypto\\x509v3\\v3_ia5.c", 85);
  if ( v3 )
  {
    memcpy((int)v3, (const __m128i *)ia5->data, ia5->length);
    v3[ia5->length] = 0;
    return v3;
  }
  else
  {
    ERR_put_error(a1, 0x22u, 149, 65, ".\\crypto\\x509v3\\v3_ia5.c", 86);
    return 0;
  }
}
