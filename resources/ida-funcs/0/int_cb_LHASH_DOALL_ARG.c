void __cdecl int_cb_LHASH_DOALL_ARG(_DWORD *a1, _DWORD *a2)
{
  ((void (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))*a2)(*a1, a1[1], a1[2], a2[1]);
}
