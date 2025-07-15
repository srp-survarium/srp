int __usercall ec_GF2m_simple_mul@<eax>(
        int a1@<ebx>,
        const ec_group_st *group,
        ec_point_st *r,
        const bignum_st *scalar,
        unsigned int num,
        const ec_point_st **points,
        bignum_st **scalars,
        bignum_ctx *ctx)
{
  bignum_ctx *v8; // ebp
  ec_point_st *v10; // ebx
  ec_point_st *v11; // eax
  ec_point_st *v12; // edi
  const bignum_st **v13; // edi
  int i; // eax
  int v15; // [esp+8h] [ebp-10h]
  int v16; // [esp+Ch] [ebp-Ch]
  bignum_ctx *v17; // [esp+10h] [ebp-8h]
  const ec_point_st *ctxa; // [esp+34h] [ebp+1Ch]

  v8 = ctx;
  v17 = 0;
  v15 = 0;
  if ( !ctx )
  {
    v17 = BN_CTX_new(a1);
    v8 = v17;
    if ( !v17 )
      return 0;
  }
  if ( scalar && num > 1 || num > 2 || !num && EC_GROUP_have_precompute_mult(group) )
  {
    v15 = ec_wNAF_mul(group, r, scalar, num, points, (const bignum_st **)scalars, v8);
  }
  else
  {
    v10 = EC_POINT_new((int)scalar, group);
    if ( v10 )
    {
      v11 = EC_POINT_new((int)v10, group);
      v12 = v11;
      ctxa = v11;
      if ( v11
        && EC_POINT_set_to_infinity((int)v10, group, v11)
        && (!scalar
         || ec_GF2m_montgomery_point_multiply(group, v10, scalar, group->generator)
         && (!scalar->neg || group->meth->invert(group, v10, v8))
         && group->meth->add(group, v12, v12, v10, v8)) )
      {
        v16 = 0;
        if ( num )
        {
          v13 = (const bignum_st **)scalars;
          for ( i = (char *)points - (char *)scalars;
                ec_GF2m_montgomery_point_multiply(group, v10, *v13, *(const ec_point_st **)((char *)v13 + i))
             && (!(*v13)->neg || group->meth->invert(group, v10, v8))
             && group->meth->add(group, ctxa, ctxa, v10, v8);
                i = (char *)points - (char *)scalars )
          {
            ++v13;
            if ( ++v16 >= num )
            {
              v12 = ctxa;
              goto LABEL_26;
            }
          }
          v12 = ctxa;
        }
        else
        {
LABEL_26:
          if ( EC_POINT_copy((int)v10, r, v12) )
            v15 = 1;
        }
      }
      EC_POINT_free(v10);
      if ( v12 )
        EC_POINT_free(v12);
    }
  }
  if ( v17 )
    BN_CTX_free(v17);
  return v15;
}
