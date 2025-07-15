ec_group_st *__cdecl EC_GROUP_new_curve_GFp()
{
  const ec_method_st *v0; // eax
  ec_group_st *result; // eax
  ec_group_st *v2; // esi
  unsigned int error; // eax
  int v4; // eax
  const ec_method_st *v5; // eax
  ec_group_st *v6; // eax

  v0 = EC_GFp_nist_method();
  result = EC_GROUP_new(v0);
  v2 = result;
  if ( result )
  {
    if ( !EC_GROUP_set_curve_GFp(result) )
    {
      error = ERR_peek_last_error();
      if ( (error & 0xFF000000) != 0x10000000 )
        goto LABEL_8;
      v4 = error & 0xFFF;
      if ( v4 != 135 && v4 != 136 )
        goto LABEL_8;
      ERR_clear_error();
      EC_GROUP_clear_free(v2);
      v5 = EC_GFp_mont_method();
      v6 = EC_GROUP_new(v5);
      v2 = v6;
      if ( !v6 )
        return 0;
      if ( !EC_GROUP_set_curve_GFp(v6) )
      {
LABEL_8:
        EC_GROUP_clear_free(v2);
        return 0;
      }
    }
    return v2;
  }
  return result;
}
