char *__cdecl i2s_ASN1_INTEGER(v3_ext_method *method, asn1_string_st *a)
{
  char *result; // eax
  char *v3; // edi
  const bignum_st *v4; // eax
  bignum_st *v5; // esi

  result = (char *)a;
  v3 = 0;
  if ( a )
  {
    v4 = ASN1_INTEGER_to_BN(a, 0);
    v5 = (bignum_st *)v4;
    if ( !v4 || (v3 = BN_bn2dec(v4)) == 0 )
      ERR_put_error(0x22u, 120, 65, ".\\crypto\\x509v3\\v3_utl.c", 154);
    BN_free(v5);
    return v3;
  }
  return result;
}
