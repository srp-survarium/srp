private_key_st *__usercall X509_PKEY_new@<eax>(int a1@<ebx>)
{
  _DWORD *v1; // eax
  _DWORD *v2; // esi
  X509_algor_st *v4; // eax
  asn1_string_st *v5; // eax

  v1 = CRYPTO_malloc(52, ".\\crypto\\asn1\\x_pkey.c", 112);
  v2 = v1;
  if ( !v1 )
  {
    ERR_put_error(a1, 0xDu, 173, 65, ".\\crypto\\asn1\\x_pkey.c", 112);
    return 0;
  }
  *v1 = 0;
  v4 = X509_ALGOR_new();
  v2[1] = v4;
  if ( !v4 )
    return 0;
  v5 = ASN1_STRING_type_new(a1, 4);
  v2[2] = v5;
  if ( !v5 )
    return 0;
  v2[3] = 0;
  v2[4] = 0;
  v2[5] = 0;
  v2[6] = 0;
  v2[7] = 0;
  v2[8] = 0;
  v2[9] = 0;
  v2[10] = 0;
  v2[11] = 0;
  v2[12] = 1;
  return (private_key_st *)v2;
}
