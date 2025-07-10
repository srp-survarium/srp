int __cdecl BN_add_word(bignum_st *a, unsigned int w)
{
  unsigned int v2; // edi
  int result; // eax
  int top; // eax
  unsigned int *v5; // eax
  int i; // ecx
  unsigned int v7; // eax
  int v8; // eax

  v2 = w;
  if ( !w )
    return 1;
  top = a->top;
  if ( !top )
    return BN_set_word(a, w);
  if ( a->neg )
  {
    a->neg = 0;
    result = BN_sub_word(a, w);
    if ( a->top )
      a->neg = a->neg == 0;
  }
  else if ( a->d[top - 1] != -1
         || ((v5 = (unsigned int *)(top + 1), (int)v5 > a->dmax) ? (result = (int)bn_expand2(a, v5)) : (result = (int)a),
             result) )
  {
    for ( i = 0; ; ++i )
    {
      v7 = i < a->top ? v2 + a->d[i] : v2;
      a->d[i] = v7;
      if ( v2 <= v7 )
        break;
      v2 = 1;
    }
    v8 = a->top;
    if ( i >= v8 )
      a->top = v8 + 1;
    return 1;
  }
  return result;
}
