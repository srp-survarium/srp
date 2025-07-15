void __cdecl BN_RECP_CTX_init(bn_recp_ctx_st *recp)
{
  BN_init(&recp->N);
  BN_init(&recp->Nr);
  recp->num_bits = 0;
  recp->flags = 0;
}
