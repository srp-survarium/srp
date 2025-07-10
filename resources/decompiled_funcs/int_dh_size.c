int __cdecl int_dh_size(const evp_pkey_st *pkey)
{
  return DH_size(pkey->pkey.dh);
}
