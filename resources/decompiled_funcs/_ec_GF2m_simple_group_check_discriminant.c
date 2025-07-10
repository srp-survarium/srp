int __cdecl ec_GF2m_simple_group_check_discriminant(const ec_group_st *group, bignum_ctx *ctx)
{
  bignum_ctx *v2; // esi
  int v3; // ebp
  bignum_ctx *v4; // edi
  bignum_pool_item *v5; // ebx

  v2 = ctx;
  v3 = 0;
  v4 = 0;
  if ( ctx || (v4 = BN_CTX_new(), (v2 = v4) != 0) )
  {
    BN_CTX_start(v2);
    v5 = BN_CTX_get(v2);
    if ( v5 && BN_GF2m_mod_arr(v5->vals, &group->b, group->poly) && v5->vals[0].top )
      v3 = 1;
    if ( v2 )
      BN_CTX_end(v2);
  }
  else
  {
    ERR_put_error(0x10u, 159, 65, ".\\crypto\\ec\\ec2_smpl.c", 268);
  }
  if ( v4 )
    BN_CTX_free(v4);
  return v3;
}
