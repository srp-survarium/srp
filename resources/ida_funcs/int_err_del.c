void __usercall int_err_del(unsigned int a1@<edi>)
{
  CRYPTO_lock(a1, 9, 1, ".\\crypto\\err\\err.c", 370);
  if ( int_error_hash )
  {
    lh_free((lhash_st *)int_error_hash);
    int_error_hash = 0;
  }
  CRYPTO_lock(a1, 10, 1, ".\\crypto\\err\\err.c", 376);
}
