BOOL __cdecl dsa_missing_parameters(const evp_pkey_st *pkey)
{
  char *ptr; // eax

  ptr = pkey->pkey.ptr;
  return !*((_DWORD *)ptr + 3) || !*((_DWORD *)ptr + 4) || !*((_DWORD *)ptr + 5);
}
