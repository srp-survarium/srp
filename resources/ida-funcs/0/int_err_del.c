void __usercall int_err_del(int a1@<edi>, int a2@<ebx>)
{
  CRYPTO_lock(a1, a2, 9, 1, ".\\crypto\\err\\err.c", 370);
  if ( int_error_hash )
  {
    lh_free((lhash_st *)int_error_hash);
    int_error_hash = 0;
  }
  CRYPTO_lock(a1, a2, 10, 1, ".\\crypto\\err\\err.c", 376);
}
