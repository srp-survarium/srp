bignum_st *__usercall BN_new@<eax>(int a1@<ebx>)
{
  bignum_st *result; // eax

  result = (bignum_st *)CRYPTO_malloc(20, ".\\crypto\\bn\\bn_lib.c", 302);
  if ( result )
  {
    result->flags = 1;
    result->top = 0;
    result->neg = 0;
    result->dmax = 0;
    result->d = 0;
  }
  else
  {
    ERR_put_error(a1, 3u, 113, 65, ".\\crypto\\bn\\bn_lib.c", 304);
    return 0;
  }
  return result;
}
