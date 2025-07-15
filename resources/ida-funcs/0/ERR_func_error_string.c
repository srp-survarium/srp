ERR_string_data_st *__usercall ERR_func_error_string@<eax>(int a1@<edi>, int a2@<ebx>, unsigned int e)
{
  ERR_string_data_st *result; // eax
  unsigned int v4; // [esp+0h] [ebp-8h] BYREF

  if ( !err_fns )
  {
    CRYPTO_lock(a1, a2, 9, 1, ".\\crypto\\err\\err.c", 295);
    if ( !err_fns )
      err_fns = &err_defaults;
    CRYPTO_lock(a1, a2, 10, 1, ".\\crypto\\err\\err.c", 298);
  }
  v4 = (HIBYTE(e) << 24) | (((e >> 12) & 0xFFF) << 12);
  result = err_fns->cb_err_get_item(&v4);
  if ( result )
    return (ERR_string_data_st *)result->string;
  return result;
}
