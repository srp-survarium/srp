int __cdecl old_hmac_encode(const evp_pkey_st *pkey, unsigned __int8 **pder)
{
  char *ptr; // esi
  int v3; // ebx

  ptr = pkey->pkey.ptr;
  if ( pder )
  {
    if ( *pder )
    {
      v3 = 1;
    }
    else
    {
      *pder = (unsigned __int8 *)CRYPTO_malloc(*(_DWORD *)ptr, ".\\crypto\\hmac\\hm_ameth.c", 125);
      v3 = 0;
    }
    memcpy(*pder, *((unsigned __int8 **)ptr + 2), *(_DWORD *)ptr);
    if ( v3 )
      *pder += *(_DWORD *)ptr;
  }
  return *(_DWORD *)ptr;
}
