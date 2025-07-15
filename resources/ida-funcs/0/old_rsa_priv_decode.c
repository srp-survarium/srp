int __usercall old_rsa_priv_decode@<eax>(
        int a1@<ebx>,
        evp_pkey_st *pkey,
        unsigned __int8 **pder,
        const unsigned __int8 **derlen)
{
  char *v4; // eax

  v4 = (char *)d2i_RSAPrivateKey(0, pder, derlen);
  if ( v4 )
  {
    EVP_PKEY_assign(pkey, (void *)6, v4);
    return 1;
  }
  else
  {
    ERR_put_error(a1, 4u, 147, 4, ".\\crypto\\rsa\\rsa_ameth.c", 115);
    return 0;
  }
}
