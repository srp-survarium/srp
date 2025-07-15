int __cdecl ec_GF2m_montgomery_point_multiply(
        const ec_group_st *group,
        ec_point_st *r,
        const bignum_st *scalar,
        const ec_point_st *point)
{
  bignum_ctx *v4; // ecx
  ec_point_st *v5; // esi
  bignum_ctx *v6; // edi
  bignum_pool_item *v8; // ebx
  int top; // eax
  int v10; // edx
  int v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // ecx
  int v14; // eax
  bool v15; // zf
  int p_Y; // ebx
  int v17; // eax
  bignum_st *v18; // [esp-Ch] [ebp-38h]
  unsigned int v19; // [esp+10h] [ebp-1Ch]
  bignum_pool_item *a; // [esp+14h] [ebp-18h]
  unsigned int v21; // [esp+18h] [ebp-14h]
  bignum_st *v22; // [esp+1Ch] [ebp-10h]
  int v23; // [esp+20h] [ebp-Ch]
  bignum_st *p_X; // [esp+24h] [ebp-8h]
  int v25; // [esp+28h] [ebp-4h]

  v5 = r;
  v6 = v4;
  v25 = 0;
  if ( r == point )
  {
    ERR_put_error((int)point, 0x10u, 208, 112, ".\\crypto\\ec\\ec2_mult.c", 224);
    return 0;
  }
  if ( scalar && scalar->top && point && !EC_POINT_is_at_infinity((int)point, group, point) )
  {
    if ( !point->Z_is_one )
      return 0;
    BN_CTX_start((int)point, v6);
    v8 = BN_CTX_get((int)point, v6);
    v22 = (bignum_st *)v8;
    a = BN_CTX_get((int)v8, v6);
    if ( !a )
      goto err_170;
    p_X = &point->X;
    if ( !BN_GF2m_mod_arr(v8->vals, &point->X, group->poly)
      || !BN_set_word((int)v8, a->vals, 1u)
      || !group->meth->field_sqr(group, &r->Y, (const bignum_st *)v8, v6)
      || !group->meth->field_sqr(group, &r->X, &r->Y, v6)
      || !BN_GF2m_add(&r->X, &r->X, &group->b) )
    {
      goto err_170;
    }
    top = scalar->top;
    v10 = scalar->d[top - 1];
    v11 = top - 1;
    v23 = v11;
    v12 = 0x80000000;
    if ( v10 >= 0 )
    {
      do
        v12 >>= 1;
      while ( (v10 & v12) == 0 );
    }
    v13 = v12 >> 1;
    v19 = v13;
    if ( !v13 )
    {
      --v11;
      v19 = 0x80000000;
      v13 = 0x80000000;
      v23 = v11;
    }
    if ( v11 >= 0 )
    {
LABEL_22:
      v21 = scalar->d[v11];
      while ( 1 )
      {
        if ( (v13 & v21) != 0 )
        {
          if ( !gf2m_Madd(group, a->vals, v6, p_X, v8->vals, &v5->X, &v5->Y) )
            goto err_170;
          v14 = gf2m_Mdouble(group, v6, (int)a, &r->X, &r->Y);
        }
        else
        {
          if ( !gf2m_Madd(group, &r->Y, v6, p_X, &v5->X, v8->vals, a->vals) )
            goto err_170;
          v14 = gf2m_Mdouble(group, v6, (int)&r->Y, v22, a->vals);
        }
        if ( !v14 )
          goto err_170;
        v15 = v19 >> 1 == 0;
        v19 >>= 1;
        v8 = (bignum_pool_item *)v22;
        v5 = r;
        if ( v15 )
        {
          v11 = v23 - 1;
          v19 = 0x80000000;
          v23 = v11;
          if ( v11 >= 0 )
          {
            v13 = 0x80000000;
            goto LABEL_22;
          }
          break;
        }
        v13 = v19;
      }
    }
    v18 = (bignum_st *)v8;
    p_Y = (int)&v5->Y;
    v17 = gf2m_Mxy(group, &v5->Y, v6, p_X, &point->Y, v18, a->vals, &v5->X);
    if ( v17 )
    {
      if ( v17 == 1 )
      {
        if ( EC_POINT_set_to_infinity(p_Y, group, v5) )
          goto LABEL_38;
      }
      else if ( BN_set_word(p_Y, &v5->Z, 1u) )
      {
        v5->Z_is_one = 1;
LABEL_38:
        BN_set_negative(&v5->X, 0);
        BN_set_negative(&v5->Y, 0);
        v25 = 1;
      }
    }
err_170:
    BN_CTX_end(v6);
    return v25;
  }
  return EC_POINT_set_to_infinity((int)point, group, r);
}
