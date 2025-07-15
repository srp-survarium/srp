int __usercall BN_set_word@<eax>(int a1@<ebx>, bignum_st *a, unsigned int w)
{
  unsigned int *v3; // edi
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
  v3 = bn_expand_internal(a1, a, 1);
  if ( v3 )
  {
    if ( a->d )
      CRYPTO_free(a->d);
    a->d = v3;
    a->dmax = 1;
    goto LABEL_6;
  }
  return 0;
}
