int __cdecl rsa_priv_decode(evp_pkey_st *pkey, pkcs8_priv_key_info_st *p8)
{
  char *v2; // eax
  int ppklen; // [esp+0h] [ebp-8h] BYREF
  unsigned __int8 *pk; // [esp+4h] [ebp-4h] BYREF

  if ( !PKCS8_pkey_get0(0, (const unsigned __int8 **)&pk, &ppklen, 0, p8) )
    return 0;
  v2 = (char *)d2i_RSAPrivateKey(0, &pk, (unsigned __int8 *)ppklen);
  if ( !v2 )
  {
    ERR_put_error(4u, 147, 4, ".\\crypto\\rsa\\rsa_ameth.c", 115);
    return 0;
  }
  EVP_PKEY_assign(pkey, 6, v2);
  return 1;
}
