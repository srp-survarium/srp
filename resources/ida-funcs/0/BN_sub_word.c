int __usercall BN_sub_word@<eax>(int a1@<ebx>, bignum_st *a, unsigned int w)
{
  unsigned int v3; // eax
  int result; // eax
  int top; // ecx
  int v6; // edi
  int v7; // ecx
  int v8; // edx
  int v9; // eax

  v3 = w;
  if ( !w )
    return 1;
  top = a->top;
  if ( top )
  {
    if ( a->neg )
    {
      a->neg = 0;
      result = BN_add_word(a1, a, w);
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
      v7 = 0;
      if ( *a->d < w )
      {
        v8 = 0;
        do
        {
          a->d[v8] -= v3;
          ++v7;
          v3 = 1;
          v8 = v7;
        }
        while ( !a->d[v7] );
      }
      a->d[v7] -= v3;
      if ( !a->d[v7] )
      {
        v9 = a->top - 1;
        if ( v7 == v9 )
          a->top = v9;
      }
      return 1;
    }
  }
  else
  {
    v6 = BN_set_word(a1, a, w);
    if ( v6 )
      BN_set_negative(a, 1);
    return v6;
  }
  return result;
}
