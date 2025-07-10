int __cdecl BN_set_word(bignum_st *a, unsigned int w)
{
  unsigned int *v2; // edi
  unsigned int *d; // ecx
  int result; // eax

  if ( a->dmax >= 1 )
  {
LABEL_6:
    d = a->d;
    a->neg = 0;
    *d = w;
    result = 1;
    a->top = w != 0;
    return result;
  }
  v2 = bn_expand_internal(a, (unsigned int *)1);
  if ( v2 )
  {
    if ( a->d )
      CRYPTO_free(a->d);
    a->d = v2;
    a->dmax = 1;
    goto LABEL_6;
  }
  return 0;
}
