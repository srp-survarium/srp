int __cdecl BN_rand(bignum_st *rnd, int bits, int top, int bottom)
{
  return bnrand(bits, 0, rnd, top, bottom);
}
