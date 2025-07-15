char *__cdecl i2s_ASN1_IA5STRING(v3_ext_method *method, asn1_string_st *ia5)
{
  unsigned __int8 *v2; // esi

  if ( !ia5 || !ia5->length )
    return 0;
  v2 = (unsigned __int8 *)CRYPTO_malloc(ia5->length + 1, ".\\crypto\\x509v3\\v3_ia5.c", 85);
  if ( v2 )
  {
    memcpy(v2, ia5->data, ia5->length);
    v2[ia5->length] = 0;
    return (char *)v2;
  }
  else
  {
    ERR_put_error(0x22u, 149, 65, ".\\crypto\\x509v3\\v3_ia5.c", 86);
    return 0;
  }
}
