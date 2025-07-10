lhash_st *__usercall int_err_set_item@<eax>(unsigned int a1@<edi>, ERR_string_data_st *d)
{
  lhash_st *result; // eax
  lhash_st *v3; // esi
  void *v4; // esi

  if ( !err_fns )
  {
    CRYPTO_lock(a1, 9, 1, ".\\crypto\\err\\err.c", 295);
    if ( !err_fns )
      err_fns = &err_defaults;
    CRYPTO_lock(a1, 10, 1, ".\\crypto\\err\\err.c", 298);
  }
  result = (lhash_st *)err_fns->cb_err_get(1);
  v3 = result;
  if ( result )
  {
    CRYPTO_lock(a1, 9, 1, ".\\crypto\\err\\err.c", 406);
    v4 = lh_insert(v3, d);
    CRYPTO_lock(a1, 10, 1, ".\\crypto\\err\\err.c", 408);
    return (lhash_st *)v4;
  }
  return result;
}
