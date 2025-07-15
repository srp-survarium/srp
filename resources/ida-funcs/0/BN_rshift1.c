int __cdecl BN_rshift1(bignum_st *r, const bignum_st *a)
{
  int top; // eax
  int result; // eax
  unsigned int *d; // eax
  int v5; // esi
  int v6; // ecx
  int *v7; // edx
  char *v8; // edi
  unsigned int v9; // eax
  int v10; // eax
  unsigned int *v11; // ecx

  top = a->top;
  if ( !top )
  {
    BN_set_word((int)a, r, 0);
    return 1;
  }
  if ( a != r )
  {
    if ( top > r->dmax )
      result = (int)bn_expand2(r, top);
    else
      result = (int)r;
    if ( !result )
      return result;
    r->top = a->top;
    r->neg = a->neg;
  }
  d = r->d;
  v5 = 0;
  v6 = a->top - 1;
  if ( v6 >= 0 )
  {
    v7 = (int *)&d[v6];
    v8 = (char *)((char *)a->d - (char *)d);
    do
    {
      v9 = *(int *)((char *)v7 + (_DWORD)v8);
      *v7 = v5 | (v9 >> 1);
      --v6;
      --v7;
      v5 = v9 << 31;
    }
    while ( v6 >= 0 );
  }
  v10 = r->top;
  if ( v10 > 0 )
  {
    v11 = &r->d[v10 - 1];
    do
    {
      if ( *v11-- )
        break;
      --v10;
    }
    while ( v10 > 0 );
    r->top = v10;
  }
  return 1;
}
