int __usercall EC_POINT_invert@<eax>(int a1@<ebx>, const ec_group_st *group, ec_point_st *a, bignum_ctx *ctx)
{
  const ec_method_st *meth; // eax

  meth = group->meth;
  if ( group->meth->dbl )
  {
    if ( meth == a->meth )
    {
      return meth->invert(group, a, ctx);
    }
    else
    {
      ERR_put_error(a1, 0x10u, 210, 101, ".\\crypto\\ec\\ec_lib.c", 1020);
      return 0;
    }
  }
  else
  {
    ERR_put_error(a1, 0x10u, 210, 66, ".\\crypto\\ec\\ec_lib.c", 1015);
    return 0;
  }
}
