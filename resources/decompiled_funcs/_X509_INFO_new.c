X509_info_st *__cdecl X509_INFO_new()
{
  X509_info_st *result; // eax

  result = (X509_info_st *)CRYPTO_malloc(44, ".\\crypto\\asn1\\x_info.c", 69);
  if ( result )
  {
    result->enc_cipher.cipher = 0;
    result->enc_len = 0;
    result->enc_data = 0;
    result->references = 1;
    result->x509 = 0;
    result->crl = 0;
    result->x_pkey = 0;
  }
  else
  {
    ERR_put_error(0xDu, 170, 65, ".\\crypto\\asn1\\x_info.c", 72);
    return 0;
  }
  return result;
}
