int __cdecl ec_GF2m_simple_mul(
        const ec_group_st *group,
        ec_point_st *r,
        const bignum_st *scalar,
        unsigned int num,
        const ec_point_st **points,
        bignum_st **scalars,
        bignum_ctx *ctx)
{
  bignum_ctx *v7; // ebp
  ec_point_st *v9; // ebx
  ec_point_st *v10; // eax
  ec_point_st *v11; // edi
  const bignum_st **v12; // edi
  int i; // eax
  int v14; // [esp+8h] [ebp-10h]
  int v15; // [esp+Ch] [ebp-Ch]
  bignum_ctx *v16; // [esp+10h] [ebp-8h]
  const ec_point_st *ctxa; // [esp+34h] [ebp+1Ch]

  v7 = ctx;
  v16 = 0;
  v14 = 0;
  if ( !ctx )
  {
    v16 = BN_CTX_new();
    v7 = v16;
    if ( !v16 )
      return 0;
  }
  if ( scalar && num > 1 || num > 2 || !num && EC_GROUP_have_precompute_mult(group) )
  {
    v14 = ec_wNAF_mul(group, r, scalar, num, points, (const bignum_st **)scalars, v7);
  }
  else
  {
    v9 = EC_POINT_new(group);
    if ( v9 )
    {
      v10 = EC_POINT_new(group);
      v11 = v10;
      ctxa = v10;
      if ( v10
        && EC_POINT_set_to_infinity(group, v10)
        && (!scalar
         || ec_GF2m_montgomery_point_multiply(group, v9, scalar, group->generator)
         && (!scalar->neg || group->meth->invert(group, v9, v7))
         && group->meth->add(group, v11, v11, v9, v7)) )
      {
        v15 = 0;
        if ( num )
        {
          v12 = (const bignum_st **)scalars;
          for ( i = (char *)points - (char *)scalars;
                ec_GF2m_montgomery_point_multiply(group, v9, *v12, *(const ec_point_st **)((char *)v12 + i))
             && (!(*v12)->neg || group->meth->invert(group, v9, v7))
             && group->meth->add(group, ctxa, ctxa, v9, v7);
                i = (char *)points - (char *)scalars )
          {
            ++v12;
            if ( ++v15 >= num )
            {
              v11 = ctxa;
              goto LABEL_26;
            }
          }
          v11 = ctxa;
        }
        else
        {
LABEL_26:
          if ( EC_POINT_copy(r, v11) )
            v14 = 1;
        }
      }
      EC_POINT_free(v9);
      if ( v11 )
        EC_POINT_free(v11);
    }
  }
  if ( v16 )
    BN_CTX_free(v16);
  return v14;
}
