int __cdecl EVP_PKEY_set_type(evp_pkey_st *pkey, void *type)
{
  return pkey_set_type(pkey, 0, type, (engine_st *)0xFFFFFFFF);
}
