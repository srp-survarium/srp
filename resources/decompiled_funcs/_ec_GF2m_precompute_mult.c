// attributes: thunk
int __cdecl ec_GF2m_precompute_mult(ec_group_st *group, bignum_ctx *ctx)
{
  return ec_wNAF_precompute_mult(group, ctx);
}
