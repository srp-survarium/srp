const ecdh_method *__cdecl ECDH_OpenSSL()
{
  return &openssl_ecdh_meth;
}
