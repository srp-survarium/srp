int __usercall BN_RECP_CTX_set@<eax>(int a1@<ebx>, bn_recp_ctx_st *recp, const bignum_st *d)
{
  int result; // eax

  result = (int)BN_copy(&recp->N, d);
  if ( result )
  {
    BN_set_word(a1, &recp->Nr, 0);
    recp->num_bits = BN_num_bits(d);
    recp->shift = 0;
    return 1;
  }
  return result;
}
