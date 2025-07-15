int __cdecl BN_mul_word(bignum_st *a, unsigned int w)
{
  int top; // ecx
  int result; // eax
  unsigned int v4; // edi

  top = a->top;
  if ( !top )
    return 1;
  if ( !w )
  {
    BN_set_word(a, 0);
    return 1;
  }
  v4 = bn_mul_words(a->d, a->d, top, w);
  if ( !v4 )
    return 1;
  if ( a->top + 1 > a->dmax )
    result = (int)bn_expand2(a, (unsigned int *)(a->top + 1));
  else
    result = (int)a;
  if ( result )
  {
    a->d[a->top++] = v4;
    return 1;
  }
  return result;
}
