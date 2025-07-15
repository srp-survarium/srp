unsigned int __usercall ENGINE_finish@<eax>(unsigned int a1@<edi>, engine_st *e)
{
  bool v3; // zf
  unsigned int v4; // edi

  if ( !e )
  {
    ERR_put_error(0x26u, 107, 67, ".\\crypto\\engine\\eng_init.c", 142);
    return 0;
  }
  CRYPTO_lock(a1, 9, 30, ".\\crypto\\engine\\eng_init.c", 145);
  v3 = e->funct_ref-- == 1;
  v4 = 1;
  if ( !v3
    || !e->finish
    || (CRYPTO_lock(1u, 10, 30, ".\\crypto\\engine\\eng_init.c", 97),
        v4 = e->finish(e),
        CRYPTO_lock(v4, 9, 30, ".\\crypto\\engine\\eng_init.c", 100),
        v4) )
  {
    if ( engine_free_util(v4, e, 0) )
      goto LABEL_9;
    ERR_put_error(0x26u, 191, 106, ".\\crypto\\engine\\eng_init.c", 114);
  }
  v4 = 0;
LABEL_9:
  CRYPTO_lock(v4, 10, 30, ".\\crypto\\engine\\eng_init.c", 147);
  if ( v4 )
    return v4;
  ERR_put_error(0x26u, 107, 106, ".\\crypto\\engine\\eng_init.c", 150);
  return 0;
}
