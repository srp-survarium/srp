evp_pkey_st *__usercall EVP_PKEY_new@<eax>(int a1@<ebx>)
{
  evp_pkey_st *result; // eax

  result = (evp_pkey_st *)CRYPTO_malloc(32, ".\\crypto\\evp\\p_lib.c", 186);
  if ( result )
  {
    result->type = 0;
    result->save_type = 0;
    result->references = 1;
    result->ameth = 0;
    result->engine = 0;
    result->pkey.ptr = 0;
    result->attributes = 0;
    result->save_parameters = 1;
  }
  else
  {
    ERR_put_error(a1, 6u, 106, 65, ".\\crypto\\evp\\p_lib.c", 189);
    return 0;
  }
  return result;
}
