ec_point_st *__cdecl EC_POINT_new(const ec_group_st *group)
{
  ec_point_st *v2; // esi
  const ec_method_st *meth; // eax

  if ( group )
  {
    if ( group->meth->point_init )
    {
      v2 = (ec_point_st *)CRYPTO_malloc(68, ".\\crypto\\ec\\ec_lib.c", 708);
      if ( v2 )
      {
        meth = group->meth;
        v2->meth = group->meth;
        if ( meth->point_init(v2) )
        {
          return v2;
        }
        else
        {
          CRYPTO_free((void *)v2);
          return 0;
        }
      }
      else
      {
        ERR_put_error(0x10u, 121, 65, ".\\crypto\\ec\\ec_lib.c", 711);
        return 0;
      }
    }
    else
    {
      ERR_put_error(0x10u, 121, 66, ".\\crypto\\ec\\ec_lib.c", 704);
      return 0;
    }
  }
  else
  {
    ERR_put_error(0x10u, 121, 67, ".\\crypto\\ec\\ec_lib.c", 699);
    return 0;
  }
}
