unsigned int __usercall EC_POINT_point2oct@<eax>(
        int a1@<ebx>,
        const ec_group_st *group,
        const ec_point_st *point,
        point_conversion_form_t form,
        unsigned __int8 *buf,
        unsigned int len,
        bignum_ctx *ctx)
{
  unsigned int (__cdecl *point2oct)(const ec_group_st *, const ec_point_st *, point_conversion_form_t, unsigned __int8 *, unsigned int, bignum_ctx *); // ecx

  point2oct = group->meth->point2oct;
  if ( point2oct )
  {
    if ( group->meth == point->meth )
    {
      return point2oct(group, point, form, buf, len, ctx);
    }
    else
    {
      ERR_put_error(a1, 0x10u, 123, 101, ".\\crypto\\ec\\ec_lib.c", 955);
      return 0;
    }
  }
  else
  {
    ERR_put_error(a1, 0x10u, 123, 66, ".\\crypto\\ec\\ec_lib.c", 950);
    return 0;
  }
}
