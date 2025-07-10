int __cdecl eckey_param_decode(evp_pkey_st *pkey, unsigned __int8 **pder, unsigned __int8 *derlen)
{
  char *v3; // eax

  v3 = (char *)d2i_ECParameters(0, pder, derlen);
  if ( v3 )
  {
    EVP_PKEY_assign(pkey, 408, v3);
    return 1;
  }
  else
  {
    ERR_put_error(0x10u, 212, 16, ".\\crypto\\ec\\ec_ameth.c", 528);
    return 0;
  }
}
