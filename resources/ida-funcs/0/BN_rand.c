int __usercall BN_rand@<eax>(int a1@<ebx>, bignum_st *rnd, int bits, int top, int bottom)
{
  return bnrand(bits, 0, a1, rnd, top, bottom);
}
