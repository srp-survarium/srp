int __cdecl old_dsa_priv_decode(evp_pkey_st *pkey, unsigned __int8 **pder, unsigned __int8 *derlen)
{
  char *v3; // eax

  v3 = (char *)d2i_DSAPrivateKey(0, pder, derlen);
  if ( v3 )
  {
    EVP_PKEY_assign(pkey, 116, v3);
    return 1;
  }
  else
  {
    ERR_put_error(0xAu, 122, 10, ".\\crypto\\dsa\\dsa_ameth.c", 533);
    return 0;
  }
}
