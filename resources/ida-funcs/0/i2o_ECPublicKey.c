int __usercall i2o_ECPublicKey@<eax>(int a1@<ebx>, ec_key_st *a, unsigned __int8 **out)
{
  int v3; // ebp
  int result; // eax
  unsigned int v5; // ebx
  unsigned __int8 *v6; // eax

  v3 = 0;
  if ( !a )
  {
    ERR_put_error(a1, 0x10u, 151, 67, ".\\crypto\\ec\\ec_asn1.c", 1398);
    return 0;
  }
  result = EC_POINT_point2oct(a->group, a->pub_key, a->conv_form, 0, 0, 0);
  v5 = result;
  if ( out && result )
  {
    if ( !*out )
    {
      v6 = (unsigned __int8 *)CRYPTO_malloc(result, ".\\crypto\\ec\\ec_asn1.c", 1411);
      *out = v6;
      if ( !v6 )
      {
        ERR_put_error(v5, 0x10u, 151, 65, ".\\crypto\\ec\\ec_asn1.c", 1413);
        return 0;
      }
      v3 = 1;
    }
    if ( EC_POINT_point2oct(a->group, a->pub_key, a->conv_form, *out, v5, 0) )
    {
      if ( !v3 )
        *out += v5;
      return v5;
    }
    else
    {
      ERR_put_error(v5, 0x10u, 151, 16, ".\\crypto\\ec\\ec_asn1.c", 1421);
      CRYPTO_free(*out);
      *out = 0;
      return 0;
    }
  }
  return result;
}
