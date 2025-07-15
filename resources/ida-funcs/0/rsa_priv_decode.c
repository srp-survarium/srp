int __usercall rsa_priv_decode@<eax>(int a1@<ebx>, evp_pkey_st *pkey, pkcs8_priv_key_info_st *p8)
{
  char *v3; // eax
  int ppklen; // [esp+0h] [ebp-8h] BYREF
  unsigned __int8 *pk; // [esp+4h] [ebp-4h] BYREF

  if ( !PKCS8_pkey_get0(0, (const unsigned __int8 **)&pk, &ppklen, 0, p8) )
    return 0;
  v3 = (char *)d2i_RSAPrivateKey(0, &pk, (const unsigned __int8 **)ppklen);
  if ( !v3 )
  {
    ERR_put_error(a1, 4u, 147, 4, ".\\crypto\\rsa\\rsa_ameth.c", 115);
    return 0;
  }
  EVP_PKEY_assign(pkey, (void *)6, v3);
  return 1;
}
