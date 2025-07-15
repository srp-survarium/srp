ec_key_st *__cdecl d2i_ECParameters(ec_key_st **a, unsigned __int8 **in, unsigned __int8 *len)
{
  ec_key_st *v3; // esi
  ec_key_st *v4; // eax

  if ( in && *in )
  {
    if ( !a || (v3 = *a) == 0 )
    {
      v4 = EC_KEY_new();
      v3 = v4;
      if ( !v4 )
      {
        ERR_put_error(0x10u, 144, 65, ".\\crypto\\ec\\ec_asn1.c", 1344);
        return 0;
      }
      if ( a )
        *a = v4;
    }
    if ( !d2i_ECPKParameters(&v3->group, in, len) )
    {
      ERR_put_error(0x10u, 144, 16, ".\\crypto\\ec\\ec_asn1.c", 1355);
      return 0;
    }
    return v3;
  }
  else
  {
    ERR_put_error(0x10u, 144, 67, ".\\crypto\\ec\\ec_asn1.c", 1336);
    return 0;
  }
}
