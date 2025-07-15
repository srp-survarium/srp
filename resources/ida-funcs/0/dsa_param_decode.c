int __usercall dsa_param_decode@<eax>(
        int a1@<ebx>,
        evp_pkey_st *pkey,
        unsigned __int8 **pder,
        const unsigned __int8 **derlen)
{
  char *v4; // eax

  v4 = (char *)d2i_DSAparams(0, pder, derlen);
  if ( v4 )
  {
    EVP_PKEY_assign(pkey, (void *)0x74, v4);
    return 1;
  }
  else
  {
    ERR_put_error(a1, 0xAu, 119, 10, ".\\crypto\\dsa\\dsa_ameth.c", 496);
    return 0;
  }
}
