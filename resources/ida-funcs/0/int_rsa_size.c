int __cdecl int_rsa_size(const evp_pkey_st *pkey)
{
  return RSA_size(pkey->pkey.rsa);
}
