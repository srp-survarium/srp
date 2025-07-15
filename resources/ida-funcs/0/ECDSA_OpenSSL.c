const ecdsa_method *__cdecl ECDSA_OpenSSL()
{
  return &openssl_ecdsa_meth;
}
