int __usercall CRYPTO_push_info_@<eax>(int a1@<edi>, int a2@<ebx>, char *info, char *file, unsigned int line)
{
  crypto_threadid_st *v5; // esi
  lhash_node_st *v6; // eax
  lhash_st *v8; // [esp-14h] [ebp-1Ch]
  crypto_threadid_st id; // [esp+0h] [ebp-8h] BYREF

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
    v5 = (crypto_threadid_st *)CRYPTO_malloc(28, ".\\crypto\\mem_dbg.c", 406);
    if ( v5 )
    {
      if ( amih
        || (amih = (lhash_st_APP_INFO *)lh_new(
                                          (int (__cdecl *)(const char *))app_info_LHASH_HASH,
                                          (void (__cdecl *)(unsigned __int8 *, unsigned __int8 *))err_state_LHASH_COMP)) != 0 )
      {
        CRYPTO_THREADID_current(v5);
        v5[1].ptr = file;
        v8 = (lhash_st *)amih;
        v5[1].val = line;
        v5[2].ptr = info;
        v5[3].ptr = (void *)1;
        v5[2].val = 0;
        v6 = lh_insert(v8, v5);
        if ( v6 )
          v5[2].val = (unsigned int)v6;
      }
      else
      {
        CRYPTO_free(v5);
      }
    }
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
  return 0;
}
