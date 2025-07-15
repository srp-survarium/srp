lhash_st *__usercall int_thread_get_item@<eax>(int a1@<edi>, int a2@<ebx>, err_state_st *d)
{
  lhash_st *result; // eax
  void **v4; // esi
  lhash_st *lh; // [esp+0h] [ebp-4h] BYREF

  if ( !err_fns )
  {
    CRYPTO_lock(a1, a2, 9, 1, ".\\crypto\\err\\err.c", 295);
    if ( !err_fns )
      err_fns = &err_defaults;
    CRYPTO_lock(a1, a2, 10, 1, ".\\crypto\\err\\err.c", 298);
  }
  result = (lhash_st *)err_fns->cb_thread_get(0);
  lh = result;
  if ( result )
  {
    CRYPTO_lock(a1, a2, 5, 1, ".\\crypto\\err\\err.c", 495);
    v4 = lh_retrieve(lh, d);
    CRYPTO_lock(a1, a2, 6, 1, ".\\crypto\\err\\err.c", 497);
    err_fns->cb_thread_release((lhash_st_ERR_STATE **)&lh);
    return (lhash_st *)v4;
  }
  return result;
}
