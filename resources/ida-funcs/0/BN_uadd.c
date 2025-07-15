bignum_st *__cdecl BN_uadd(bignum_st *r, const bignum_st *a, const bignum_st *b)
{
  const bignum_st *v3; // ecx
  const bignum_st *v4; // eax
  int top; // ebp
  int v6; // edi
  int v7; // ebx
  bignum_st *result; // eax
  unsigned int *v9; // esi
  unsigned int *v10; // edi
  int v11; // eax
  bignum_st *v12; // eax

  v3 = a;
  v4 = b;
  if ( a->top < b->top )
  {
    a = b;
    b = v3;
    v4 = v3;
    v3 = a;
  }
  top = v4->top;
  v6 = v3->top;
  v7 = v6 - top;
  if ( v6 + 1 > r->dmax )
  {
    result = bn_expand2(r, v6 + 1);
    v3 = a;
  }
  else
  {
    result = r;
  }
  if ( result )
  {
    r->top = v6;
    v9 = &r->d[top];
    v10 = &v3->d[top];
    if ( bn_add_words(r->d, v3->d, b->d, top) )
    {
      if ( !v7 )
      {
LABEL_11:
        v12 = r;
        *v9 = 1;
        ++r->top;
        goto LABEL_13;
      }
      while ( 1 )
      {
        v11 = *v10 + 1;
        *v9 = v11;
        --v7;
        ++v10;
        ++v9;
        if ( v11 )
          break;
        if ( !v7 )
          goto LABEL_11;
      }
    }
    v12 = r;
LABEL_13:
    if ( v7 && v9 != v10 )
    {
      do
      {
        --v7;
        *v9++ = *v10++;
      }
      while ( v7 );
    }
    v12->neg = 0;
    return (bignum_st *)1;
  }
  return result;
}
