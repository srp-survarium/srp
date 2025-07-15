bignum_ctx *__usercall ec_GFp_nist_group_set_curve@<eax>(
        int a1@<ebx>,
        ec_group_st *group,
        const bignum_st *p,
        const bignum_st *a,
        const bignum_st *b,
        bignum_ctx *ctx)
{
  bignum_ctx *v6; // esi
  int v7; // ebp
  bignum_ctx *v8; // edi
  bignum_ctx *result; // eax
  const bignum_st *v10; // eax
  ec_group_st *v11; // eax
  const bignum_st *v12; // eax
  const bignum_st *v13; // eax
  const bignum_st *v14; // eax
  const bignum_st *v15; // eax

  v6 = ctx;
  v7 = 0;
  v8 = 0;
  if ( !ctx )
  {
    result = BN_CTX_new(a1);
    v8 = result;
    v6 = result;
    if ( !result )
      return result;
  }
  BN_CTX_start(a1, v6);
  if ( BN_CTX_get(a1, v6) )
  {
    v10 = BN_get0_nist_prime_192();
    if ( BN_ucmp(v10, p) )
    {
      v12 = BN_get0_nist_prime_224();
      if ( BN_ucmp(v12, p) )
      {
        v13 = BN_get0_nist_prime_256();
        if ( BN_ucmp(v13, p) )
        {
          v14 = BN_get0_nist_prime_384();
          if ( BN_ucmp(v14, p) )
          {
            v15 = BN_get0_nist_prime_521();
            if ( BN_ucmp(v15, p) )
            {
              ERR_put_error((int)p, 0x10u, 202, 135, ".\\crypto\\ec\\ecp_nist.c", 147);
              goto err_183;
            }
            v11 = group;
            group->field_mod_func = BN_nist_mod_521;
          }
          else
          {
            v11 = group;
            group->field_mod_func = BN_nist_mod_384;
          }
        }
        else
        {
          v11 = group;
          group->field_mod_func = BN_nist_mod_256;
        }
      }
      else
      {
        v11 = group;
        group->field_mod_func = BN_nist_mod_224;
      }
    }
    else
    {
      v11 = group;
      group->field_mod_func = BN_nist_mod_192;
    }
    v7 = ec_GFp_simple_group_set_curve(v11, p, a, b, v6);
  }
err_183:
  BN_CTX_end(v6);
  if ( v8 )
    BN_CTX_free(v8);
  return (bignum_ctx *)v7;
}
