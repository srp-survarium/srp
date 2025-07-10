void __cdecl CRYPTO_set_locking_callback(void (__cdecl *func)(int, int, const char *, int))
{
  locking_callback = func;
}
