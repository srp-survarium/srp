void (__cdecl *_init_pointers())(int)
{
  int (__cdecl *v0)(unsigned int); // esi
  void (__cdecl *result)(int); // eax

  v0 = (int (__cdecl *)(unsigned int))_encoded_null();
  _initp_heap_handler(v0);
  _initp_misc_initcrit((int (__stdcall *)(_RTL_CRITICAL_SECTION *, unsigned int))v0);
  _initp_misc_invarg((void (__cdecl *)(const wchar_t *, const wchar_t *, const wchar_t *, unsigned int, unsigned int))v0);
  _initp_misc_purevirt((void (__cdecl *)())v0);
  _initp_misc_rand_s((int (__stdcall *)(void *, unsigned int))v0);
  _initp_misc_winsig((void (__cdecl *)(int))v0);
  _initp_misc_winxfltr();
  _initp_eh_hooks();
  result = (void (__cdecl *)(int))_encode_pointer(_exit);
  _aexit_rtn = result;
  return result;
}
