private_key_st *__cdecl X509_PKEY_new()
{
  _DWORD *v0; // eax
  _DWORD *v1; // esi
  X509_algor_st *v3; // eax
  asn1_string_st *v4; // eax

  v0 = CRYPTO_malloc(52, ".\\crypto\\asn1\\x_pkey.c", 112);
  v1 = v0;
  if ( !v0 )
  {
    ERR_put_error(0xDu, 173, 65, ".\\crypto\\asn1\\x_pkey.c", 112);
    return 0;
  }
  *v0 = 0;
  v3 = X509_ALGOR_new();
  v1[1] = v3;
  if ( !v3 )
    return 0;
  v4 = ASN1_STRING_type_new(4);
  v1[2] = v4;
  if ( !v4 )
    return 0;
  v1[3] = 0;
  v1[4] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[7] = 0;
  v1[8] = 0;
  v1[9] = 0;
  v1[10] = 0;
  v1[11] = 0;
  v1[12] = 1;
  return (private_key_st *)v1;
}
