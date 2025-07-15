int __cdecl rsa_pub_decode(evp_pkey_st *pkey, X509_pubkey_st *pubkey)
{
  char *v2; // eax
  int ppklen; // [esp+0h] [ebp-8h] BYREF
  unsigned __int8 *pk; // [esp+4h] [ebp-4h] BYREF

  if ( !X509_PUBKEY_get0_param(0, &pk, &ppklen, 0, pubkey) )
    return 0;
  v2 = (char *)d2i_RSAPublicKey(0, &pk, (unsigned __int8 *)ppklen);
  if ( !v2 )
  {
    ERR_put_error(4u, 139, 4, ".\\crypto\\rsa\\rsa_ameth.c", 94);
    return 0;
  }
  EVP_PKEY_assign(pkey, 6, v2);
  return 1;
}
