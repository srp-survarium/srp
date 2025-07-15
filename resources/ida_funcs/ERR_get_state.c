err_state_st *__cdecl ERR_get_state()
{
  err_state_st *v0; // esi
  int *err_data_flags; // eax
  int v2; // ecx
  err_state_st *v3; // ebx
  crypto_threadid_st id; // [esp+Ch] [ebp-198h] BYREF
  crypto_threadid_st dest; // [esp+14h] [ebp-190h] BYREF

  if ( !err_fns )
  {
    CRYPTO_lock(0, 9, 1, ".\\crypto\\err\\err.c", 295);
    if ( !err_fns )
      err_fns = &err_defaults;
    CRYPTO_lock(0, 10, 1, ".\\crypto\\err\\err.c", 298);
  }
  CRYPTO_THREADID_current(&id);
  CRYPTO_THREADID_cpy(&dest, &id);
  v0 = err_fns->cb_thread_get_item(&dest);
  if ( !v0 )
  {
    v0 = (err_state_st *)CRYPTO_malloc(400, ".\\crypto\\err\\err.c", 1019);
    if ( !v0 )
      return &fallback;
    CRYPTO_THREADID_cpy(&v0->tid, &id);
    v0->top = 0;
    v0->bottom = 0;
    err_data_flags = v0->err_data_flags;
    v2 = 16;
    do
    {
      *(err_data_flags - 16) = 0;
      *err_data_flags++ = 0;
      --v2;
    }
    while ( v2 );
    v3 = err_fns->cb_thread_set_item(v0);
    if ( err_fns->cb_thread_get_item(v0) != v0 )
    {
      ERR_STATE_free(v0);
      return &fallback;
    }
    if ( v3 )
      ERR_STATE_free(v3);
  }
  return v0;
}
