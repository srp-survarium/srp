bignum_ctx *__cdecl ec_GFp_nist_group_set_curve(
        ec_group_st *group,
        const bignum_st *p,
        const bignum_st *a,
        const bignum_st *b,
        bignum_ctx *ctx)
{
  bignum_ctx *v5; // esi
  int v6; // ebp
  bignum_ctx *v7; // edi
  bignum_ctx *result; // eax
  const bignum_st *v9; // eax
  ec_group_st *v10; // eax
  const bignum_st *v11; // eax
  const bignum_st *v12; // eax
  const bignum_st *v13; // eax
  const bignum_st *v14; // eax

  v5 = ctx;
  v6 = 0;
  v7 = 0;
  if ( !ctx )
  {
    result = BN_CTX_new();
    v7 = result;
    v5 = result;
    if ( !result )
      return result;
  }
  BN_CTX_start(v5);
  if ( BN_CTX_get(v5) )
  {
    v9 = BN_get0_nist_prime_192();
    if ( BN_ucmp(v9, p) )
    {
      v11 = BN_get0_nist_prime_224();
      if ( BN_ucmp(v11, p) )
      {
        v12 = BN_get0_nist_prime_256();
        if ( BN_ucmp(v12, p) )
        {
          v13 = BN_get0_nist_prime_384();
          if ( BN_ucmp(v13, p) )
          {
            v14 = BN_get0_nist_prime_521();
            if ( BN_ucmp(v14, p) )
            {
              ERR_put_error(0x10u, 202, 135, ".\\crypto\\ec\\ecp_nist.c", 147);
              goto err_181;
            }
            v10 = group;
            group->field_mod_func = BN_nist_mod_521;
          }
          else
          {
            v10 = group;
            group->field_mod_func = BN_nist_mod_384;
          }
        }
        else
        {
          v10 = group;
          group->field_mod_func = BN_nist_mod_256;
        }
      }
      else
      {
        v10 = group;
        group->field_mod_func = BN_nist_mod_224;
      }
    }
    else
    {
      v10 = group;
      group->field_mod_func = BN_nist_mod_192;
    }
    v6 = ec_GFp_simple_group_set_curve(v10, p, a, b, v5);
  }
err_181:
  BN_CTX_end(v5);
  if ( v7 )
    BN_CTX_free(v7);
  return (bignum_ctx *)v6;
}
