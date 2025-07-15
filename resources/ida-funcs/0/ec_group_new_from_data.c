ec_group_st *__usercall ec_group_new_from_data@<eax>(int a1@<ebx>, const EC_CURVE_DATA *data)
{
  ec_group_st *v2; // edi
  bignum_ctx *v3; // ebp
  int param_len; // esi
  const unsigned __int8 *v5; // ebx
  const bignum_st *v6; // eax
  const bignum_st *v7; // esi
  int v9; // [esp-4h] [ebp-34h]
  bignum_st *x; // [esp+10h] [ebp-20h]
  ec_point_st *point; // [esp+14h] [ebp-1Ch]
  bignum_st *p; // [esp+18h] [ebp-18h]
  bignum_st *a; // [esp+1Ch] [ebp-14h]
  bignum_st *v14; // [esp+20h] [ebp-10h]
  bignum_st *v15; // [esp+24h] [ebp-Ch]
  bignum_st *v16; // [esp+28h] [ebp-8h]
  unsigned int seed_len; // [esp+2Ch] [ebp-4h]

  v2 = 0;
  point = 0;
  p = 0;
  a = 0;
  v14 = 0;
  x = 0;
  v16 = 0;
  v15 = 0;
  v3 = BN_CTX_new(a1);
  if ( !v3 )
  {
    ERR_put_error(a1, 0x10u, 175, 65, ".\\crypto\\ec\\ec_curve.c", 1921);
LABEL_28:
    EC_GROUP_free(v2);
    v2 = 0;
    goto LABEL_29;
  }
  param_len = data->param_len;
  seed_len = data->seed_len;
  v5 = (const unsigned __int8 *)&data[1] + seed_len;
  p = BN_bin2bn(v5, param_len, 0);
  if ( !p
    || (a = BN_bin2bn(&v5[param_len], param_len, 0)) == 0
    || (v14 = BN_bin2bn(&v5[2 * param_len], param_len, 0)) == 0 )
  {
    v9 = 1934;
    goto LABEL_27;
  }
  if ( data->field_type == 406 )
  {
    v2 = EC_GROUP_new_curve_GFp(p);
    if ( !v2 )
    {
      ERR_put_error((int)v5, 0x10u, 175, 16, ".\\crypto\\ec\\ec_curve.c", 1942);
      goto LABEL_28;
    }
  }
  else
  {
    v2 = EC_GROUP_new_curve_GF2m(p);
    if ( !v2 )
    {
      ERR_put_error((int)v5, 0x10u, 175, 16, ".\\crypto\\ec\\ec_curve.c", 1950);
      goto LABEL_28;
    }
  }
  point = EC_POINT_new((int)v5, v2);
  if ( !point )
  {
    ERR_put_error((int)v5, 0x10u, 175, 16, ".\\crypto\\ec\\ec_curve.c", 1957);
    goto LABEL_28;
  }
  x = BN_bin2bn(&v5[2 * param_len + param_len], param_len, 0);
  if ( !x || (v6 = BN_bin2bn(&v5[4 * param_len], param_len, 0), (v16 = (bignum_st *)v6) == 0) )
  {
    v9 = 1964;
    goto LABEL_27;
  }
  if ( !EC_POINT_set_affine_coordinates_GF2m((int)v5, v2, point, x, v6, v3) )
  {
    ERR_put_error((int)v5, 0x10u, 175, 16, ".\\crypto\\ec\\ec_curve.c", 1969);
    goto LABEL_28;
  }
  v7 = BN_bin2bn(&v5[4 * param_len + param_len], param_len, 0);
  v15 = (bignum_st *)v7;
  if ( !v7 || !BN_set_word((int)v5, x, data->cofactor) )
  {
    v9 = 1975;
LABEL_27:
    ERR_put_error((int)v5, 0x10u, 175, 3, ".\\crypto\\ec\\ec_curve.c", v9);
    goto LABEL_28;
  }
  if ( !EC_GROUP_set_generator((int)v5, v2, point, v7, x) )
  {
    ERR_put_error((int)v5, 0x10u, 175, 16, ".\\crypto\\ec\\ec_curve.c", 1980);
    goto LABEL_28;
  }
  if ( seed_len && !EC_GROUP_set_seed(v2, (const __m128i *)&data[1], seed_len) )
  {
    ERR_put_error((int)&data[1], 0x10u, 175, 16, ".\\crypto\\ec\\ec_curve.c", 1987);
    goto LABEL_28;
  }
LABEL_29:
  if ( point )
    EC_POINT_free(point);
  if ( v3 )
    BN_CTX_free(v3);
  if ( p )
    BN_free(p);
  if ( a )
    BN_free(a);
  if ( v14 )
    BN_free(v14);
  if ( v15 )
    BN_free(v15);
  if ( x )
    BN_free(x);
  if ( v16 )
    BN_free(v16);
  return v2;
}
