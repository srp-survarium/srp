int __usercall dh_param_decode@<eax>(
        int a1@<ebx>,
        evp_pkey_st *pkey,
        unsigned __int8 **pder,
        const unsigned __int8 *derlen)
{
  char *v4; // eax

  v4 = (char *)d2i_DHparams(0, pder, derlen);
  if ( v4 )
  {
    EVP_PKEY_assign(pkey, (void *)0x1C, v4);
    return 1;
  }
  else
  {
    ERR_put_error(a1, 5u, 107, 5, ".\\crypto\\dh\\dh_ameth.c", 304);
    return 0;
  }
}
