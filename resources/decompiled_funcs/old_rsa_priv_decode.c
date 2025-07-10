int __cdecl old_rsa_priv_decode(evp_pkey_st *pkey, unsigned __int8 **pder, unsigned __int8 *derlen)
{
  char *v3; // eax

  v3 = (char *)d2i_RSAPrivateKey(0, pder, derlen);
  if ( v3 )
  {
    EVP_PKEY_assign(pkey, 6, v3);
    return 1;
  }
  else
  {
    ERR_put_error(4u, 147, 4, ".\\crypto\\rsa\\rsa_ameth.c", 115);
    return 0;
  }
}
