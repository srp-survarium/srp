int __usercall EC_POINT_is_on_curve@<eax>(
        int a1@<ebx>,
        const ec_group_st *group,
        const ec_point_st *point,
        bignum_ctx *ctx)
{
  int (__cdecl *is_on_curve)(const ec_group_st *, const ec_point_st *, bignum_ctx *); // ecx

  is_on_curve = group->meth->is_on_curve;
  if ( is_on_curve )
  {
    if ( group->meth == point->meth )
    {
      return is_on_curve(group, point, ctx);
    }
    else
    {
      ERR_put_error(a1, 0x10u, 119, 101, ".\\crypto\\ec\\ec_lib.c", 1052);
      return 0;
    }
  }
  else
  {
    ERR_put_error(a1, 0x10u, 119, 66, ".\\crypto\\ec\\ec_lib.c", 1047);
    return 0;
  }
}
