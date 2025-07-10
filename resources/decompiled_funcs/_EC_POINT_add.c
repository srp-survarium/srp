int __cdecl EC_POINT_add(
        const ec_group_st *group,
        ec_point_st *r,
        const ec_point_st *a,
        const ec_point_st *b,
        bignum_ctx *ctx)
{
  int (__cdecl *add)(const ec_group_st *, ec_point_st *, const ec_point_st *, const ec_point_st *, bignum_ctx *); // esi

  add = group->meth->add;
  if ( add )
  {
    if ( group->meth == r->meth && r->meth == a->meth && a->meth == b->meth )
    {
      return add(group, r, a, b, ctx);
    }
    else
    {
      ERR_put_error(0x10u, 112, 101, ".\\crypto\\ec\\ec_lib.c", 988);
      return 0;
    }
  }
  else
  {
    ERR_put_error(0x10u, 112, 66, ".\\crypto\\ec\\ec_lib.c", 983);
    return 0;
  }
}
