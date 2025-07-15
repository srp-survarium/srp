int __usercall rsa_blinding_convert@<eax>(
        bignum_st *f@<ebx>,
        bignum_st *unblind@<ecx>,
        bignum_ctx *ctx@<edi>,
        bn_blinding_st *b)
{
  int v6; // esi

  if ( !unblind )
    return BN_BLINDING_convert_ex(f, 0, b, ctx);
  CRYPTO_lock((int)ctx, (int)f, 9, 25, ".\\crypto\\rsa\\rsa_eay.c", 329);
  v6 = BN_BLINDING_convert_ex(f, unblind, b, ctx);
  CRYPTO_lock((int)ctx, (int)f, 10, 25, ".\\crypto\\rsa\\rsa_eay.c", 331);
  return v6;
}
