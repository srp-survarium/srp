int __usercall old_ec_priv_decode@<eax>(
        int a1@<ebx>,
        evp_pkey_st *pkey,
        unsigned __int8 **pder,
        const unsigned __int8 **derlen)
{
  char *v4; // eax

  v4 = (char *)d2i_ECPrivateKey(a1, 0, pder, derlen);
  if ( v4 )
  {
    EVP_PKEY_assign(pkey, (void *)0x198, v4);
    return 1;
  }
  else
  {
    ERR_put_error(a1, 0x10u, 222, 142, ".\\crypto\\ec\\ec_ameth.c", 565);
    return 0;
  }
}
