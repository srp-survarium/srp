int __usercall BN_mul_word@<eax>(int a1@<ebx>, bignum_st *a, unsigned int w)
{
  int top; // ecx
  int result; // eax
  int v5; // edi

  top = a->top;
  if ( !top )
    return 1;
  if ( !w )
  {
    BN_set_word(a1, a, 0);
    return 1;
  }
  v5 = bn_mul_words(a->d, a->d, top, w);
  if ( !v5 )
    return 1;
  if ( a->top + 1 > a->dmax )
    result = (int)bn_expand2(a, a->top + 1);
  else
    result = (int)a;
  if ( result )
  {
    a->d[a->top++] = v5;
    return 1;
  }
  return result;
}
