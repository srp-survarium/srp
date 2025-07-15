int __usercall check_padding_md@<eax>(const ssl_st *a1@<ecx>, int a2@<ebx>, int padding)
{
  int v4; // eax

  if ( !a1 )
    return 1;
  if ( padding == 3 )
  {
    ERR_put_error(a2, 4u, 140, 141, ".\\crypto\\rsa\\rsa_pmeth.c", 354);
    return 0;
  }
  if ( padding != 5 )
    return 1;
  v4 = EVP_CIPHER_CTX_cipher(a1);
  if ( RSA_X931_hash_id(v4) != -1 )
    return 1;
  ERR_put_error(a2, 4u, 140, 142, ".\\crypto\\rsa\\rsa_pmeth.c", 363);
  return 0;
}
