const dsa_method *__cdecl DSA_OpenSSL()
{
  return &openssl_dsa_meth;
}
