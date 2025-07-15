BOOL __cdecl ec_GFp_mont_field_set_to_one(const ec_group_st *group, bignum_st *r)
{
  if ( group->field_data2 )
    return BN_copy(r, (const bignum_st *)group->field_data2) != 0;
  ERR_put_error(0x10u, 209, 111, ".\\crypto\\ec\\ecp_mont.c", 309);
  return 0;
}
