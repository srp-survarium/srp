unsigned int __cdecl engine_unlocked_finish(engine_st *e, int unlock_for_handlers)
{
  bool v2; // zf
  unsigned int v3; // edi

  v2 = e->funct_ref-- == 1;
  v3 = 1;
  if ( v2 && e->finish )
  {
    if ( unlock_for_handlers )
      CRYPTO_lock(1u, 10, 30, ".\\crypto\\engine\\eng_init.c", 97);
    v3 = e->finish(e);
    if ( unlock_for_handlers )
      CRYPTO_lock(v3, 9, 30, ".\\crypto\\engine\\eng_init.c", 100);
    if ( !v3 )
      return 0;
  }
  if ( !engine_free_util(v3, e, 0) )
  {
    ERR_put_error(0x26u, 191, 106, ".\\crypto\\engine\\eng_init.c", 114);
    return 0;
  }
  return v3;
}
