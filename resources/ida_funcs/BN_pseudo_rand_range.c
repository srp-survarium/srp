int __cdecl BN_pseudo_rand_range(bignum_st *r, const bignum_st *range)
{
  return bn_rand_range(r, range, 1);
}
