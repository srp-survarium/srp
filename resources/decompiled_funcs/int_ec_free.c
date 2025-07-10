void __cdecl int_ec_free(evp_pkey_st *pkey)
{
  EC_KEY_free(pkey->pkey.ec);
}
