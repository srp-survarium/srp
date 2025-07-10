int __cdecl int_ec_size(const evp_pkey_st *pkey)
{
  return ECDSA_size(pkey->pkey.ec);
}
