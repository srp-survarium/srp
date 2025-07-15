int __usercall EC_POINT_dbl@<eax>(
        int a1@<ebx>,
        const ec_group_st *group,
        ec_point_st *r,
        const ec_point_st *a,
        bignum_ctx *ctx)
{
  int (__cdecl *dbl)(const ec_group_st *, ec_point_st *, const ec_point_st *, bignum_ctx *); // edx

  dbl = group->meth->dbl;
  if ( dbl )
  {
    if ( group->meth == r->meth && r->meth == a->meth )
    {
      return dbl(group, r, a, ctx);
    }
    else
    {
      ERR_put_error(a1, 0x10u, 115, 101, ".\\crypto\\ec\\ec_lib.c", 1004);
      return 0;
    }
  }
  else
  {
    ERR_put_error(a1, 0x10u, 115, 66, ".\\crypto\\ec\\ec_lib.c", 999);
    return 0;
  }
}
