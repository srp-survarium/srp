lhash_st_ERR_STATE *__usercall int_thread_get@<eax>(unsigned int a1@<edi>, int create)
{
  lhash_st_ERR_STATE *v2; // esi
  lhash_st_ERR_STATE *v3; // eax

  v2 = 0;
  CRYPTO_lock(a1, 9, 1, ".\\crypto\\err\\err.c", 446);
  v3 = int_thread_hash;
  if ( int_thread_hash
    || create
    && (CRYPTO_push_info_("int_thread_get (err.c)", ".\\crypto\\err\\err.c", 449),
        int_thread_hash = (lhash_st_ERR_STATE *)lh_new(
                                                  (unsigned int (__cdecl *)(const void *))err_state_LHASH_HASH,
                                                  err_state_LHASH_COMP),
        CRYPTO_pop_info(),
        (v3 = int_thread_hash) != 0) )
  {
    ++int_thread_hash_references;
    v2 = v3;
  }
  CRYPTO_lock(a1, 10, 1, ".\\crypto\\err\\err.c", 458);
  return v2;
}
