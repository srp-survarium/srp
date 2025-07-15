int __cdecl check_padding_md(int padding)
{
  const ssl_st *md; // ecx
  int v3; // eax

  if ( !md )
    return 1;
  if ( padding == 3 )
  {
    ERR_put_error(4u, 140, 141, ".\\crypto\\rsa\\rsa_pmeth.c", 354);
    return 0;
  }
  if ( padding != 5 )
    return 1;
  v3 = EVP_CIPHER_CTX_cipher(md);
  if ( RSA_X931_hash_id(v3) != -1 )
    return 1;
  ERR_put_error(4u, 140, 142, ".\\crypto\\rsa\\rsa_pmeth.c", 363);
  return 0;
}
