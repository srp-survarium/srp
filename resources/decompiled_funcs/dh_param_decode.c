int __cdecl dh_param_decode(evp_pkey_st *pkey, const unsigned __int8 **pder, int derlen)
{
  char *v3; // eax

  v3 = (char *)d2i_DHparams(0, pder, derlen);
  if ( v3 )
  {
    EVP_PKEY_assign(pkey, 28, v3);
    return 1;
  }
  else
  {
    ERR_put_error(5u, 107, 5, ".\\crypto\\dh\\dh_ameth.c", 304);
    return 0;
  }
}
