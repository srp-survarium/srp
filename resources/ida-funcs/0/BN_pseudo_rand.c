int __cdecl BN_pseudo_rand(bignum_st *rnd, int bits, int top, int bottom)
{
  return bnrand(bits, 1, rnd, top, bottom);
}
