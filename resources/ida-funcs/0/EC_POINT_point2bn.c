bignum_st *__cdecl EC_POINT_point2bn(
        const ec_group_st *group,
        const ec_point_st *point,
        point_conversion_form_t form,
        bignum_st *ret,
        bignum_ctx *ctx)
{
  bignum_st *result; // eax
  bignum_st *v6; // esi
  void *v7; // edi
  bignum_st *v8; // esi

  result = (bignum_st *)EC_POINT_point2oct((int)ctx, group, point, form, 0, 0, ctx);
  v6 = result;
  if ( result )
  {
    v7 = CRYPTO_malloc((int)result, ".\\crypto\\ec\\ec_print.c", 73);
    if ( !v7 )
      return 0;
    if ( !EC_POINT_point2oct((int)ctx, group, point, form, (unsigned __int8 *)v7, (unsigned int)v6, ctx) )
    {
      CRYPTO_free(v7);
      return 0;
    }
    v8 = BN_bin2bn((const unsigned __int8 *)v7, (int)v6, ret);
    CRYPTO_free(v7);
    return v8;
  }
  return result;
}
