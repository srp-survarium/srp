int __usercall ERR_free_strings@<eax>(int a1@<edi>, int a2@<ebx>)
{
  if ( !err_fns )
  {
    CRYPTO_lock(a1, a2, 9, 1, ".\\crypto\\err\\err.c", 295);
    if ( !err_fns )
      err_fns = &err_defaults;
    CRYPTO_lock(a1, a2, 10, 1, ".\\crypto\\err\\err.c", 298);
  }
  return ((int (*)(void))err_fns->cb_err_del)();
}
