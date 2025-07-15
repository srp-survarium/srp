int __cdecl i2r_NAME_CONSTRAINTS(const v3_ext_method *method, stack_st **a, bio_st *bp, int ind)
{
  do_i2r_name_constraints(ind, bp, *a, (stack_st_GENERAL_SUBTREE *)"Permitted");
  do_i2r_name_constraints(ind, bp, a[1], (stack_st_GENERAL_SUBTREE *)"Excluded");
  return 1;
}
