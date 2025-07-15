int __usercall BN_pseudo_rand_range@<eax>(int a1@<ebx>, bignum_st *r, const bignum_st *range)
{
  return bn_rand_range(r, range, a1, 1);
}
