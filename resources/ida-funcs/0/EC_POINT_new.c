ec_point_st *__usercall EC_POINT_new@<eax>(int a1@<ebx>, const ec_group_st *group)
{
  ec_point_st *v3; // esi
  const ec_method_st *meth; // eax

  if ( group )
  {
    if ( group->meth->point_init )
    {
      v3 = (ec_point_st *)CRYPTO_malloc(68, ".\\crypto\\ec\\ec_lib.c", 708);
      if ( v3 )
      {
        meth = group->meth;
        v3->meth = group->meth;
        if ( meth->point_init(v3) )
        {
          return v3;
        }
        else
        {
          CRYPTO_free((void *)v3);
          return 0;
        }
      }
      else
      {
        ERR_put_error(a1, 0x10u, 121, 65, ".\\crypto\\ec\\ec_lib.c", 711);
        return 0;
      }
    }
    else
    {
      ERR_put_error(a1, 0x10u, 121, 66, ".\\crypto\\ec\\ec_lib.c", 704);
      return 0;
    }
  }
  else
  {
    ERR_put_error(a1, 0x10u, 121, 67, ".\\crypto\\ec\\ec_lib.c", 699);
    return 0;
  }
}
