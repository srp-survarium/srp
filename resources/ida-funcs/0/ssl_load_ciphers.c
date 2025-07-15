int __usercall ssl_load_ciphers@<eax>(int a1@<edi>, int a2@<esi>, int a3@<ebx>)
{
  const env_md_st *digestbyname; // eax
  int result; // eax

  ssl_cipher_methods[0] = EVP_get_cipherbyname("DES-CBC");
  ssl_cipher_methods[1] = EVP_get_cipherbyname("DES-EDE3-CBC");
  ssl_cipher_methods[2] = EVP_get_cipherbyname("RC4");
  ssl_cipher_methods[3] = EVP_get_cipherbyname("RC2-CBC");
  ssl_cipher_methods[4] = EVP_get_cipherbyname("IDEA-CBC");
  ssl_cipher_methods[6] = EVP_get_cipherbyname("AES-128-CBC");
  ssl_cipher_methods[7] = EVP_get_cipherbyname("AES-256-CBC");
  ssl_cipher_methods[8] = EVP_get_cipherbyname("CAMELLIA-128-CBC");
  ssl_cipher_methods[9] = EVP_get_cipherbyname("CAMELLIA-256-CBC");
  ssl_cipher_methods[10] = EVP_get_cipherbyname("gost89-cnt");
  ssl_cipher_methods[11] = EVP_get_cipherbyname("SEED-CBC");
  ssl_digest_methods[0] = EVP_get_digestbyname("MD5");
  ssl_mac_secret_size[0] = EVP_MD_size(a3, ssl_digest_methods[0]);
  if ( ssl_mac_secret_size[0] < 0 )
    OpenSSLDie(a1, a2, a3, ".\\ssl\\ssl_ciph.c", 386, "ssl_mac_secret_size[SSL_MD_MD5_IDX] >= 0");
  ssl_digest_methods[1] = EVP_get_digestbyname("SHA1");
  ssl_mac_secret_size[1] = EVP_MD_size(a3, ssl_digest_methods[1]);
  if ( ssl_mac_secret_size[1] < 0 )
    OpenSSLDie(a1, a2, a3, ".\\ssl\\ssl_ciph.c", 391, "ssl_mac_secret_size[SSL_MD_SHA1_IDX] >= 0");
  digestbyname = EVP_get_digestbyname("md_gost94");
  ssl_digest_methods[2] = digestbyname;
  if ( digestbyname )
  {
    ssl_mac_secret_size[2] = EVP_MD_size(a3, digestbyname);
    if ( ssl_mac_secret_size[2] < 0 )
      OpenSSLDie(a1, a2, a3, ".\\ssl\\ssl_ciph.c", 398, "ssl_mac_secret_size[SSL_MD_GOST94_IDX] >= 0");
  }
  ssl_digest_methods[3] = EVP_get_digestbyname("gost-mac");
  result = get_optional_pkey_id(a1, a3, "gost-mac");
  ssl_mac_pkey_id[3] = result;
  if ( result )
    ssl_mac_secret_size[3] = 32;
  return result;
}
