int __cdecl ec_GFp_simple_group_set_curve(
        ec_group_st *group,
        const bignum_st *p,
        const bignum_st *a,
        const bignum_st *b,
        bignum_ctx *ctx)
{
  bignum_ctx *v5; // edi
  bignum_pool_item *v7; // ebp
  int (__cdecl *field_encode)(const ec_group_st *, bignum_st *, const bignum_st *, bignum_ctx *); // eax
  int (__cdecl *v10)(const ec_group_st *, bignum_st *, const bignum_st *, bignum_ctx *); // eax
  bignum_ctx *v11; // [esp+8h] [ebp-8h]
  int v12; // [esp+Ch] [ebp-4h]

  v12 = 0;
  v11 = 0;
  if ( BN_num_bits(p) > 2 && p->top > 0 && (*(_BYTE *)p->d & 1) != 0 )
  {
    v5 = ctx;
    if ( ctx || (v11 = BN_CTX_new(), (v5 = v11) != 0) )
    {
      BN_CTX_start(v5);
      v7 = BN_CTX_get(v5);
      if ( v7 )
      {
        if ( BN_copy(&group->field, p) )
        {
          BN_set_negative(&group->field, 0);
          if ( BN_nnmod(v7->vals, a, p, v5) )
          {
            field_encode = group->meth->field_encode;
            if ( field_encode ? (bignum_st *)field_encode(group, &group->a, v7->vals, v5) : BN_copy(&group->a, v7->vals) )
            {
              if ( BN_nnmod(&group->b, b, p, v5) )
              {
                v10 = group->meth->field_encode;
                if ( !v10 || v10(group, &group->b, &group->b, v5) )
                {
                  if ( BN_add_word(v7->vals, 3u) )
                  {
                    group->a_is_minus3 = BN_cmp(v7->vals, &group->field) == 0;
                    v12 = 1;
                  }
                }
              }
            }
          }
        }
      }
      BN_CTX_end(v5);
      if ( v11 )
        BN_CTX_free(v11);
      return v12;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    ERR_put_error(0x10u, 166, 103, ".\\crypto\\ec\\ecp_smpl.c", 178);
    return 0;
  }
}
