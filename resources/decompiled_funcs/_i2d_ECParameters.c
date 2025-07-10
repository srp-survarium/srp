int __cdecl i2d_ECParameters(ec_key_st *a, unsigned __int8 **out)
{
  if ( a )
    return i2d_ECPKParameters((const ssl_st *)a->group, out);
  ERR_put_error(0x10u, 190, 67, ".\\crypto\\ec\\ec_asn1.c", 1324);
  return 0;
}
