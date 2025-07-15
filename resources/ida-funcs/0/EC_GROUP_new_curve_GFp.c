ec_group_st *__cdecl EC_GROUP_new_curve_GFp(const bignum_st *p, int a2, int a3)
{
  const ec_method_st *v3; // eax
  ec_group_st *result; // eax
  ec_group_st *v5; // esi
  unsigned int error; // eax
  int v7; // eax
  const ec_method_st *v8; // eax
  ec_group_st *v9; // eax

  v3 = EC_GFp_nist_method();
  result = EC_GROUP_new(v3);
  v5 = result;
  if ( result )
  {
    if ( !EC_GROUP_set_curve_GFp(a3, result) )
    {
      error = ERR_peek_last_error();
      if ( (error & 0xFF000000) != 0x10000000 )
        goto LABEL_8;
      v7 = error & 0xFFF;
      if ( v7 != 135 && v7 != 136 )
        goto LABEL_8;
      ERR_clear_error(a3);
      EC_GROUP_clear_free(v5);
      v8 = EC_GFp_mont_method();
      v9 = EC_GROUP_new(v8);
      v5 = v9;
      if ( !v9 )
        return 0;
      if ( !EC_GROUP_set_curve_GFp(a3, v9) )
      {
LABEL_8:
        EC_GROUP_clear_free(v5);
        return 0;
      }
    }
    return v5;
  }
  return result;
}
