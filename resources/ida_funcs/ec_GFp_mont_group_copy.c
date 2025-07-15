int __cdecl ec_GFp_mont_group_copy(ec_group_st *dest, const ec_group_st *src)
{
  bn_mont_ctx_st *v2; // eax
  bignum_st *v3; // eax

  if ( dest->field_data1 )
  {
    BN_MONT_CTX_free((bn_mont_ctx_st *)dest->field_data1);
    dest->field_data1 = 0;
  }
  if ( dest->field_data2 )
  {
    BN_clear_free((bignum_st *)dest->field_data2);
    dest->field_data2 = 0;
  }
  if ( !ec_GFp_simple_group_copy(dest, src) )
    return 0;
  if ( src->field_data1 )
  {
    v2 = BN_MONT_CTX_new();
    dest->field_data1 = v2;
    if ( !v2 )
      return 0;
    if ( !BN_MONT_CTX_copy(v2, (bn_mont_ctx_st *)src->field_data1) )
      goto LABEL_17;
  }
  if ( src->field_data2 )
  {
    v3 = BN_dup((const bignum_st *)src->field_data2);
    dest->field_data2 = v3;
    if ( !v3 )
    {
LABEL_17:
      if ( dest->field_data1 )
      {
        BN_MONT_CTX_free((bn_mont_ctx_st *)dest->field_data1);
        dest->field_data1 = 0;
      }
      return 0;
    }
  }
  return 1;
}
