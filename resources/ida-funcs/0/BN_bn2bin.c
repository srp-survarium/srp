int __cdecl BN_bn2bin(const bignum_st *a, unsigned __int8 *to)
{
  int top; // eax
  int v3; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // kr04_4
  int i; // esi

  top = a->top;
  if ( top )
  {
    v3 = BN_num_bits_word(a->d[top - 1]);
    top = 32 * v4 + v3;
  }
  v6 = top + 7;
  v5 = (((top + 7) >> 31) & 7) + top + 7;
  for ( i = v6 / 8; i; *(to - 1) = a->d[i / 4] >> (8 * (i % 4)) )
  {
    --i;
    ++to;
  }
  return v5 >> 3;
}
