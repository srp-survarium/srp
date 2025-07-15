int __usercall ENGINE_finish@<eax>(int a1@<edi>, int a2@<ebx>, engine_st *e)
{
  bool v4; // zf
  int v5; // edi

  if ( !e )
  {
    ERR_put_error(a2, 0x26u, 107, 67, ".\\crypto\\engine\\eng_init.c", 142);
    return 0;
  }
  CRYPTO_lock(a1, a2, 9, 30, ".\\crypto\\engine\\eng_init.c", 145);
  v4 = e->funct_ref-- == 1;
  v5 = 1;
  if ( !v4
    || !e->finish
    || (CRYPTO_lock(1, a2, 10, 30, ".\\crypto\\engine\\eng_init.c", 97),
        v5 = e->finish(e),
        CRYPTO_lock(v5, a2, 9, 30, ".\\crypto\\engine\\eng_init.c", 100),
        v5) )
  {
    if ( engine_free_util(v5, a2, e, 0) )
      goto LABEL_9;
    ERR_put_error(a2, 0x26u, 191, 106, ".\\crypto\\engine\\eng_init.c", 114);
  }
  v5 = 0;
LABEL_9:
  CRYPTO_lock(v5, a2, 10, 30, ".\\crypto\\engine\\eng_init.c", 147);
  if ( v5 )
    return v5;
  ERR_put_error(a2, 0x26u, 107, 106, ".\\crypto\\engine\\eng_init.c", 150);
  return 0;
}
