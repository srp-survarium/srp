void __usercall ERR_remove_state(unsigned int a1@<edi>)
{
  crypto_threadid_st id; // [esp+0h] [ebp-190h] BYREF

  CRYPTO_THREADID_current(&id);
  if ( !err_fns )
  {
    CRYPTO_lock(a1, 9, 1, ".\\crypto\\err\\err.c", 295);
    if ( !err_fns )
      err_fns = &err_defaults;
    CRYPTO_lock(a1, 10, 1, ".\\crypto\\err\\err.c", 298);
  }
  err_fns->cb_thread_del_item((const err_state_st *)&id);
}
