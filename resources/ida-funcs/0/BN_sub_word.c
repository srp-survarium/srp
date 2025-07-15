int __cdecl BN_sub_word(bignum_st *a, unsigned int w)
{
  unsigned int v2; // eax
  int result; // eax
  int top; // ecx
  int v5; // edi
  int v6; // ecx
  int v7; // edx
  int v8; // eax

  v2 = w;
  if ( !w )
    return 1;
  top = a->top;
  if ( top )
  {
    if ( a->neg )
    {
      a->neg = 0;
      result = BN_add_word(a, w);
      a->neg = 1;
    }
    else if ( top == 1 && *a->d < w )
    {
      *a->d = w - *a->d;
      a->neg = 1;
      return 1;
    }
    else
    {
      v6 = 0;
      if ( *a->d < w )
      {
        v7 = 0;
        do
        {
          a->d[v7] -= v2;
          ++v6;
          v2 = 1;
          v7 = v6;
        }
        while ( !a->d[v6] );
      }
      a->d[v6] -= v2;
      if ( !a->d[v6] )
      {
        v8 = a->top - 1;
        if ( v6 == v8 )
          a->top = v8;
      }
      return 1;
    }
  }
  else
  {
    v5 = BN_set_word(a, w);
    if ( v5 )
      BN_set_negative(a, 1);
    return v5;
  }
  return result;
}
