err_state_st *__usercall ERR_get_state@<eax>(int a1@<ebx>)
{
  err_state_st *v1; // esi
  int *err_data_flags; // eax
  int v3; // ecx
  err_state_st *v4; // ebx
  crypto_threadid_st id; // [esp+Ch] [ebp-198h] BYREF
  crypto_threadid_st dest; // [esp+14h] [ebp-190h] BYREF

  if ( !err_fns )
  {
    CRYPTO_lock(0, a1, 9, 1, ".\\crypto\\err\\err.c", 295);
    if ( !err_fns )
      err_fns = &err_defaults;
    CRYPTO_lock(0, a1, 10, 1, ".\\crypto\\err\\err.c", 298);
  }
  CRYPTO_THREADID_current(&id);
  CRYPTO_THREADID_cpy(&dest, &id);
  v1 = err_fns->cb_thread_get_item(&dest);
  if ( !v1 )
  {
    v1 = (err_state_st *)CRYPTO_malloc(400, ".\\crypto\\err\\err.c", 1019);
    if ( !v1 )
      return &fallback;
    CRYPTO_THREADID_cpy(&v1->tid, &id);
    v1->top = 0;
    v1->bottom = 0;
    err_data_flags = v1->err_data_flags;
    v3 = 16;
    do
    {
      *(err_data_flags - 16) = 0;
      *err_data_flags++ = 0;
      --v3;
    }
    while ( v3 );
    v4 = err_fns->cb_thread_set_item(v1);
    if ( err_fns->cb_thread_get_item(v1) != v1 )
    {
      ERR_STATE_free(v1);
      return &fallback;
    }
    if ( v4 )
      ERR_STATE_free(v4);
  }
  return v1;
}
