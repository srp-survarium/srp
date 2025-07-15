void __usercall int_thread_del_item(unsigned int a1@<edi>, const err_state_st *d)
{
  err_state_st *v2; // esi
  lhash_st *lh; // [esp+0h] [ebp-4h] BYREF

  if ( !err_fns )
  {
    CRYPTO_lock(a1, 9, 1, ".\\crypto\\err\\err.c", 295);
    if ( !err_fns )
      err_fns = &err_defaults;
    CRYPTO_lock(a1, 10, 1, ".\\crypto\\err\\err.c", 298);
  }
  lh = (lhash_st *)err_fns->cb_thread_get(0);
  if ( lh )
  {
    CRYPTO_lock(a1, 9, 1, ".\\crypto\\err\\err.c", 531);
    v2 = (err_state_st *)lh_delete(lh, d);
    if ( int_thread_hash_references == 1 && int_thread_hash && !lh_num_items((const lhash_st *)int_thread_hash) )
    {
      lh_free((lhash_st *)int_thread_hash);
      int_thread_hash = 0;
    }
    CRYPTO_lock(a1, 10, 1, ".\\crypto\\err\\err.c", 540);
    err_fns->cb_thread_release((lhash_st_ERR_STATE **)&lh);
    if ( v2 )
      ERR_STATE_free(v2);
  }
}
