int __usercall ec_GF2m_simple_group_check_discriminant@<eax>(int a1@<ebx>, const ec_group_st *group, bignum_ctx *ctx)
{
  bignum_ctx *v3; // esi
  int v4; // ebp
  bignum_ctx *v5; // edi
  bignum_pool_item *v6; // ebx

  v3 = ctx;
  v4 = 0;
  v5 = 0;
  if ( ctx || (v5 = BN_CTX_new(a1), (v3 = v5) != 0) )
  {
    BN_CTX_start(a1, v3);
    v6 = BN_CTX_get(a1, v3);
    if ( v6 && BN_GF2m_mod_arr(v6->vals, &group->b, group->poly) && v6->vals[0].top )
      v4 = 1;
    if ( v3 )
      BN_CTX_end(v3);
  }
  else
  {
    ERR_put_error(a1, 0x10u, 159, 65, ".\\crypto\\ec\\ec2_smpl.c", 268);
  }
  if ( v5 )
    BN_CTX_free(v5);
  return v4;
}
