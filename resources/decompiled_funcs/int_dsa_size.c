int __cdecl int_dsa_size(const evp_pkey_st *pkey)
{
  return DSA_size(pkey->pkey.dsa);
}
