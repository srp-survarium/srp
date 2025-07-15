bignum_st *__cdecl ec_GFp_simple_group_get_curve(
        const ec_group_st *group,
        bignum_st *p,
        bignum_st *a,
        bignum_st *b,
        bignum_ctx *ctx)
{
  bignum_st *result; // eax
  bignum_ctx *v6; // edi
  bignum_ctx *ctxa; // [esp+8h] [ebp-8h]
  int v8; // [esp+Ch] [ebp-4h]

  v8 = 0;
  ctxa = 0;
  if ( p )
  {
    result = BN_copy(p, &group->field);
    if ( !result )
      return result;
  }
  if ( !a && !b )
  {
LABEL_17:
    v8 = 1;
err_198:
    if ( ctxa )
      BN_CTX_free(ctxa);
    return (bignum_st *)v8;
  }
  if ( !group->meth->field_decode )
  {
    if ( a && !BN_copy(a, &group->a) || b && !BN_copy(b, &group->b) )
      return (bignum_st *)v8;
    goto LABEL_17;
  }
  v6 = ctx;
  if ( ctx || (result = (bignum_st *)BN_CTX_new((int)a), ctxa = (bignum_ctx *)result, (v6 = (bignum_ctx *)result) != 0) )
  {
    if ( a && !group->meth->field_decode(group, a, &group->a, v6)
      || b && !group->meth->field_decode(group, b, &group->b, v6) )
    {
      goto err_198;
    }
    goto LABEL_17;
  }
  return result;
}
