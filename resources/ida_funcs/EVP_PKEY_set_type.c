int __cdecl EVP_PKEY_set_type(evp_pkey_st *pkey, int type)
{
  return pkey_set_type(pkey, 0, type, -1);
}
