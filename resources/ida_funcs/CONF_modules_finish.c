void CONF_modules_finish()
{
  void **v0; // esi
  void (__cdecl *v1)(void **); // eax

  while ( sk_num(&initialized_modules->stack) > 0 )
  {
    v0 = (void **)sk_pop(&initialized_modules->stack);
    v1 = (void (__cdecl *)(void **))*((_DWORD *)*v0 + 3);
    if ( v1 )
      v1(v0);
    --*((_DWORD *)*v0 + 4);
    CRYPTO_free(v0[1]);
    CRYPTO_free(v0[2]);
    CRYPTO_free(v0);
  }
  sk_free(&initialized_modules->stack);
  initialized_modules = 0;
}
