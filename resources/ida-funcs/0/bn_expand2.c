bignum_st *__cdecl bn_expand2(bignum_st *b, unsigned int *words)
{
  bignum_st *result; // eax
  unsigned int *v3; // edi

  if ( (int)words > b->dmax )
  {
    result = (bignum_st *)bn_expand_internal(b, words);
    v3 = (unsigned int *)result;
    if ( !result )
      return result;
    if ( b->d )
      CRYPTO_free(b->d);
    b->d = v3;
    b->dmax = (int)words;
  }
  return b;
}
