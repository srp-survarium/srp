int __cdecl EVP_PKEY_assign(evp_pkey_st *pkey, int type, char *key)
{
  int result; // eax

  result = pkey_set_type(pkey, 0, type, -1);
  if ( result )
  {
    pkey->pkey.ptr = key;
    return key != 0;
  }
  return result;
}
