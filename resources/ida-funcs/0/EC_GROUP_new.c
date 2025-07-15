ec_group_st *__cdecl EC_GROUP_new(const ec_method_st *meth)
{
  ec_group_st *v2; // esi

  if ( meth )
  {
    if ( meth->group_init )
    {
      v2 = (ec_group_st *)CRYPTO_malloc(172, ".\\crypto\\ec\\ec_lib.c", 91);
      if ( v2 )
      {
        v2->meth = meth;
        v2->extra_data = 0;
        v2->generator = 0;
        BN_init(&v2->order);
        BN_init(&v2->cofactor);
        v2->curve_name = 0;
        v2->asn1_flag = 0;
        v2->asn1_form = POINT_CONVERSION_UNCOMPRESSED;
        v2->seed = 0;
        v2->seed_len = 0;
        if ( meth->group_init(v2) )
        {
          return v2;
        }
        else
        {
          CRYPTO_free(v2);
          return 0;
        }
      }
      else
      {
        ERR_put_error(0x10u, 108, 65, ".\\crypto\\ec\\ec_lib.c", 94);
        return 0;
      }
    }
    else
    {
      ERR_put_error(0x10u, 108, 66, ".\\crypto\\ec\\ec_lib.c", 87);
      return 0;
    }
  }
  else
  {
    ERR_put_error(0x10u, 108, 108, ".\\crypto\\ec\\ec_lib.c", 82);
    return 0;
  }
}
