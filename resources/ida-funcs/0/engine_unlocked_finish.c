int __usercall engine_unlocked_finish@<eax>(int a1@<ebx>, engine_st *e, int unlock_for_handlers)
{
  bool v3; // zf
  int v4; // edi
  int v5; // eax

  v3 = e->funct_ref-- == 1;
  v4 = 1;
  if ( v3 && e->finish )
  {
    if ( unlock_for_handlers )
      CRYPTO_lock(1, unlock_for_handlers, 10, 30, ".\\crypto\\engine\\eng_init.c", 97);
    v5 = e->finish(e);
    v4 = v5;
    if ( unlock_for_handlers )
      CRYPTO_lock(v5, a1, 9, 30, ".\\crypto\\engine\\eng_init.c", 100);
    if ( !v4 )
      return 0;
  }
  if ( !engine_free_util(v4, a1, e, 0) )
  {
    ERR_put_error(a1, 0x26u, 191, 106, ".\\crypto\\engine\\eng_init.c", 114);
    return 0;
  }
  return v4;
}
