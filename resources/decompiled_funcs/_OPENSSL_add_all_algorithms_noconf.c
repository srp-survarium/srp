int OPENSSL_add_all_algorithms_noconf()
{
  OPENSSL_cpuid_setup();
  OpenSSL_add_all_ciphers();
  return OpenSSL_add_all_digests();
}
