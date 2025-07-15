BOOL __cdecl dh_missing_parameters(const evp_pkey_st *a)
{
  char *ptr; // eax

  ptr = a->pkey.ptr;
  return !*((_DWORD *)ptr + 2) || !*((_DWORD *)ptr + 3);
}
