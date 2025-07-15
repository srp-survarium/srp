int __usercall CRYPTO_push_info_@<eax>(unsigned int a1@<edi>, char *info, char *file, unsigned int line)
{
  crypto_threadid_st *v4; // esi
  void *v5; // eax
  lhash_st *v7; // [esp-14h] [ebp-1Ch]
  crypto_threadid_st id; // [esp+0h] [ebp-8h] BYREF

  if ( CRYPTO_is_mem_check_on(a1) )
  {
    CRYPTO_lock(a1, 9, 20, ".\\crypto\\mem_dbg.c", 220);
    if ( (mh_mode & 1) != 0 )
    {
      CRYPTO_THREADID_current(&id);
      if ( !num_disable || CRYPTO_THREADID_cmp(&disabling_threadid, &id) )
      {
        CRYPTO_lock(a1, 10, 20, ".\\crypto\\mem_dbg.c", 250);
        CRYPTO_lock(a1, 9, 27, ".\\crypto\\mem_dbg.c", 256);
        CRYPTO_lock(a1, 9, 20, ".\\crypto\\mem_dbg.c", 257);
        mh_mode &= ~2u;
        CRYPTO_THREADID_cpy(&disabling_threadid, &id);
      }
      ++num_disable;
    }
    CRYPTO_lock(a1, 10, 20, ".\\crypto\\mem_dbg.c", 282);
    v4 = (crypto_threadid_st *)CRYPTO_malloc(28, ".\\crypto\\mem_dbg.c", 406);
    if ( v4 )
    {
      if ( amih
        || (amih = (lhash_st_APP_INFO *)lh_new(
                                          (unsigned int (__cdecl *)(const void *))app_info_LHASH_HASH,
                                          (int (__cdecl *)(const void *, const void *))err_state_LHASH_COMP)) != 0 )
      {
        CRYPTO_THREADID_current(v4);
        v4[1].ptr = file;
        v7 = (lhash_st *)amih;
        v4[1].val = line;
        v4[2].ptr = info;
        v4[3].ptr = (void *)1;
        v4[2].val = 0;
        v5 = lh_insert(v7, v4);
        if ( v5 )
          v4[2].val = (unsigned int)v5;
      }
      else
      {
        CRYPTO_free(v4);
      }
    }
    CRYPTO_lock(a1, 9, 20, ".\\crypto\\mem_dbg.c", 220);
    if ( (mh_mode & 1) != 0 )
    {
      if ( num_disable )
      {
        if ( !--num_disable )
        {
          mh_mode |= 2u;
          CRYPTO_lock(a1, 10, 27, ".\\crypto\\mem_dbg.c", 273);
        }
      }
    }
    CRYPTO_lock(a1, 10, 20, ".\\crypto\\mem_dbg.c", 282);
  }
  return 0;
}
