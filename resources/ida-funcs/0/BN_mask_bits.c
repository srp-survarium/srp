int __cdecl BN_mask_bits(bignum_st *a, int n)
{
  int v3; // eax
  unsigned int v4; // ecx
  int top; // eax
  unsigned int *v6; // ecx

  if ( n < 0 )
    return 0;
  v3 = n / 32;
  v4 = n & 0x8000001F;
  if ( n / 32 >= a->top )
    return 0;
  if ( v4 )
  {
    a->top = v3 + 1;
    a->d[v3] &= ~(-1 << v4);
  }
  else
  {
    a->top = v3;
  }
  top = a->top;
  if ( top > 0 )
  {
    v6 = &a->d[top - 1];
    do
    {
      if ( *v6-- )
        break;
      --top;
    }
    while ( top > 0 );
    a->top = top;
  }
  return 1;
}
