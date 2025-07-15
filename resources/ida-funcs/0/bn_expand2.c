bignum_st *__cdecl bn_expand2(bignum_st *b, int words)
{
  bignum_st *result; // eax
  unsigned int *v3; // edi

  if ( words > b->dmax )
  {
    result = (bignum_st *)bn_expand_internal(words, b, words);
    v3 = (unsigned int *)result;
    if ( !result )
      return result;
    if ( b->d )
      CRYPTO_free(b->d);
    b->d = v3;
    b->dmax = words;
  }
  return b;
}
