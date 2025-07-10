lhash_st *__usercall int_thread_set_item@<eax>(unsigned int a1@<edi>, err_state_st *d)
{
  lhash_st *result; // eax
  void *v3; // esi
  lhash_st *lh; // [esp+0h] [ebp-4h] BYREF

  if ( !err_fns )
  {
    CRYPTO_lock(a1, 9, 1, ".\\crypto\\err\\err.c", 295);
    if ( !err_fns )
      err_fns = &err_defaults;
    CRYPTO_lock(a1, 10, 1, ".\\crypto\\err\\err.c", 298);
  }
  result = (lhash_st *)err_fns->cb_thread_get(1);
  lh = result;
  if ( result )
  {
    CRYPTO_lock(a1, 9, 1, ".\\crypto\\err\\err.c", 513);
    v3 = lh_insert(lh, d);
    CRYPTO_lock(a1, 10, 1, ".\\crypto\\err\\err.c", 515);
    err_fns->cb_thread_release((lhash_st_ERR_STATE **)&lh);
    return (lhash_st *)v3;
  }
  return result;
}
