BOOL __usercall CRYPTO_pop_info@<eax>(int a1@<edi>, int a2@<ebx>)
{
  BOOL v2; // esi
  crypto_threadid_st id; // [esp+4h] [ebp-8h] BYREF

  v2 = 0;
  if ( CRYPTO_is_mem_check_on(a1, a2) )
  {
    CRYPTO_lock(a1, a2, 9, 20, ".\\crypto\\mem_dbg.c", 220);
    if ( (mh_mode & 1) != 0 )
    {
      CRYPTO_THREADID_current(&id);
      if ( !num_disable || CRYPTO_THREADID_cmp(&disabling_threadid, &id) )
      {
        CRYPTO_lock(a1, 1, 10, 20, ".\\crypto\\mem_dbg.c", 250);
        CRYPTO_lock(a1, 1, 9, 27, ".\\crypto\\mem_dbg.c", 256);
        CRYPTO_lock(a1, 1, 9, 20, ".\\crypto\\mem_dbg.c", 257);
        mh_mode &= ~2u;
        CRYPTO_THREADID_cpy(&disabling_threadid, &id);
      }
      ++num_disable;
    }
    CRYPTO_lock(a1, 1, 10, 20, ".\\crypto\\mem_dbg.c", 282);
    v2 = pop_info() != 0;
    CRYPTO_lock(a1, 1, 9, 20, ".\\crypto\\mem_dbg.c", 220);
    if ( (mh_mode & 1) != 0 )
    {
      if ( num_disable )
      {
        if ( !--num_disable )
        {
          mh_mode |= 2u;
          CRYPTO_lock(a1, 1, 10, 27, ".\\crypto\\mem_dbg.c", 273);
        }
      }
    }
    CRYPTO_lock(a1, 1, 10, 20, ".\\crypto\\mem_dbg.c", 282);
  }
  return v2;
}
