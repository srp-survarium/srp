int __cdecl BN_num_bits(const bignum_st *a)
{
  int result; // eax
  int v2; // eax
  int v3; // ecx

  result = a->top;
  if ( result )
  {
    v2 = BN_num_bits_word(a->d[result - 1]);
    return 32 * v3 + v2;
  }
  return result;
}
