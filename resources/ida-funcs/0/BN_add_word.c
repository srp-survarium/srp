int __usercall BN_add_word@<eax>(int a1@<ebx>, bignum_st *a, unsigned int w)
{
  unsigned int v3; // edi
  int result; // eax
  int top; // eax
  int v6; // eax
  int i; // ecx
  unsigned int v8; // eax
  int v9; // eax

  v3 = w;
  if ( !w )
    return 1;
  top = a->top;
  if ( !top )
    return BN_set_word(a1, a, w);
  if ( a->neg )
  {
    a->neg = 0;
    result = BN_sub_word(a, w);
    if ( a->top )
      a->neg = a->neg == 0;
  }
  else if ( a->d[top - 1] != -1
         || ((v6 = top + 1, v6 > a->dmax) ? (result = (int)bn_expand2(a, v6)) : (result = (int)a), result) )
  {
    for ( i = 0; ; ++i )
    {
      v8 = i < a->top ? v3 + a->d[i] : v3;
      a->d[i] = v8;
      if ( v3 <= v8 )
        break;
      v3 = 1;
    }
    v9 = a->top;
    if ( i >= v9 )
      a->top = v9 + 1;
    return 1;
  }
  return result;
}
