int __cdecl ec_GFp_nist_group_copy(ec_group_st *dest, const ec_group_st *src)
{
  dest->field_mod_func = src->field_mod_func;
  return ec_GFp_simple_group_copy(dest, src);
}
