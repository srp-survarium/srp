int __cdecl __onexitinit()
{
  unsigned __int8 *v0; // esi

  v0 = _calloc_crt(0x20u, 4u);
  __onexitbegin = (void (__cdecl **)())_encode_pointer(v0);
  __onexitend = __onexitbegin;
  if ( !v0 )
    return 24;
  *(_DWORD *)v0 = 0;
  return 0;
}
