void __cdecl CRYPTO_set_id_callback(unsigned int (__cdecl *func)())
{
  id_callback = func;
}
