int __usercall ERR_free_strings@<eax>(unsigned int a1@<edi>)
{
  if ( !err_fns )
  {
    CRYPTO_lock(a1, 9, 1, ".\\crypto\\err\\err.c", 295);
    if ( !err_fns )
      err_fns = &err_defaults;
    CRYPTO_lock(a1, 10, 1, ".\\crypto\\err\\err.c", 298);
  }
  return ((int (*)(void))err_fns->cb_err_del)();
}
