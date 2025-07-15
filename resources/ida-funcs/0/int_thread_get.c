lhash_st_ERR_STATE *__usercall int_thread_get@<eax>(int a1@<edi>, int a2@<ebx>, int create)
{
  lhash_st_ERR_STATE *v3; // esi
  lhash_st_ERR_STATE *v4; // eax

  v3 = 0;
  CRYPTO_lock(a1, a2, 9, 1, ".\\crypto\\err\\err.c", 446);
  v4 = int_thread_hash;
  if ( int_thread_hash
    || create
    && (CRYPTO_push_info_(a1, "int_thread_get (err.c)", ".\\crypto\\err\\err.c", 0x1C1u),
        int_thread_hash = (lhash_st_ERR_STATE *)lh_new(
                                                  (int (__cdecl *)(const char *))err_state_LHASH_HASH,
                                                  (void (__cdecl *)(unsigned __int8 *, unsigned __int8 *))err_state_LHASH_COMP),
        CRYPTO_pop_info(a1),
        (v4 = int_thread_hash) != 0) )
  {
    ++int_thread_hash_references;
    v3 = v4;
  }
  CRYPTO_lock(a1, a2, 10, 1, ".\\crypto\\err\\err.c", 458);
  return v3;
}
