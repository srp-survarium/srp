int __usercall i2d_ECParameters@<eax>(int a1@<ebx>, ec_key_st *a, unsigned __int8 **out)
{
  if ( a )
    return i2d_ECPKParameters(a1, (const ssl_st *)a->group, out);
  ERR_put_error(a1, 0x10u, 190, 67, ".\\crypto\\ec\\ec_asn1.c", 1324);
  return 0;
}
