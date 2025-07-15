void __cdecl ec_GFp_mont_group_finish(ec_group_st *group)
{
  if ( group->field_data1 )
  {
    BN_MONT_CTX_free((bn_mont_ctx_st *)group->field_data1);
    group->field_data1 = 0;
  }
  if ( group->field_data2 )
  {
    BN_free((bignum_st *)group->field_data2);
    group->field_data2 = 0;
  }
  ec_GFp_simple_group_finish(group);
}
