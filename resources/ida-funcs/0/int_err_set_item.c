lhash_st *__usercall int_err_set_item@<eax>(int a1@<edi>, int a2@<ebx>, ERR_string_data_st *d)
{
  lhash_st *result; // eax
  lhash_st *v4; // esi
  lhash_node_st *v5; // esi

  if ( !err_fns )
  {
    CRYPTO_lock(a1, a2, 9, 1, ".\\crypto\\err\\err.c", 295);
    if ( !err_fns )
      err_fns = &err_defaults;
    CRYPTO_lock(a1, a2, 10, 1, ".\\crypto\\err\\err.c", 298);
  }
  result = (lhash_st *)err_fns->cb_err_get(1);
  v4 = result;
  if ( result )
  {
    CRYPTO_lock(a1, a2, 9, 1, ".\\crypto\\err\\err.c", 406);
    v5 = lh_insert(v4, d);
    CRYPTO_lock(a1, a2, 10, 1, ".\\crypto\\err\\err.c", 408);
    return (lhash_st *)v5;
  }
  return result;
}
