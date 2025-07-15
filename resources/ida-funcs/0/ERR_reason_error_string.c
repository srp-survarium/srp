ERR_string_data_st *__usercall ERR_reason_error_string@<eax>(unsigned int a1@<edi>, unsigned int e)
{
  ERR_string_data_st *result; // eax
  _DWORD v3[2]; // [esp+0h] [ebp-8h] BYREF

  if ( !err_fns )
  {
    CRYPTO_lock(a1, 9, 1, ".\\crypto\\err\\err.c", 295);
    if ( !err_fns )
      err_fns = &err_defaults;
    CRYPTO_lock(a1, 10, 1, ".\\crypto\\err\\err.c", 298);
  }
  v3[0] = e & 0xFFF | (HIBYTE(e) << 24);
  result = err_fns->cb_err_get_item(v3);
  if ( result )
    return (ERR_string_data_st *)result->string;
  v3[0] = e & 0xFFF;
  result = err_fns->cb_err_get_item(v3);
  if ( result )
    return (ERR_string_data_st *)result->string;
  return result;
}
