void __cdecl int_cb_LHASH_DOALL_ARG(_DWORD *arg1, _DWORD *arg2)
{
  ((void (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))*arg2)(*arg1, arg1[1], arg1[2], arg2[1]);
}
