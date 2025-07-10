void (__cdecl *_init_pointers())(int)
{
  void *v0; // esi
  void (__cdecl *result)(int); // eax

  v0 = (void *)_encoded_null();
  _initp_heap_handler(v0);
  _initp_misc_initcrit(v0);
  _initp_misc_invarg(v0);
  _initp_misc_purevirt(v0);
  _initp_misc_rand_s(v0);
  _initp_misc_winsig(v0);
  _initp_misc_winxfltr(v0);
  _initp_eh_hooks(v0);
  result = (void (__cdecl *)(int))_encode_pointer(_exit);
  _aexit_rtn = result;
  return result;
}
