unsigned int __cdecl i2o_ECPublicKey(ec_key_st *a, unsigned __int8 **out)
{
  int v2; // ebp
  unsigned int result; // eax
  unsigned int v4; // ebx
  unsigned __int8 *v5; // eax

  v2 = 0;
  if ( !a )
  {
    ERR_put_error(0x10u, 151, 67, ".\\crypto\\ec\\ec_asn1.c", 1398);
    return 0;
  }
  result = EC_POINT_point2oct(a->group, a->pub_key, a->conv_form, 0, 0, 0);
  v4 = result;
  if ( out && result )
  {
    if ( !*out )
    {
      v5 = (unsigned __int8 *)CRYPTO_malloc(result, ".\\crypto\\ec\\ec_asn1.c", 1411);
      *out = v5;
      if ( !v5 )
      {
        ERR_put_error(0x10u, 151, 65, ".\\crypto\\ec\\ec_asn1.c", 1413);
        return 0;
      }
      v2 = 1;
    }
    if ( EC_POINT_point2oct(a->group, a->pub_key, a->conv_form, *out, v4, 0) )
    {
      if ( !v2 )
        *out += v4;
      return v4;
    }
    else
    {
      ERR_put_error(0x10u, 151, 16, ".\\crypto\\ec\\ec_asn1.c", 1421);
      CRYPTO_free(*out);
      *out = 0;
      return 0;
    }
  }
  return result;
}
