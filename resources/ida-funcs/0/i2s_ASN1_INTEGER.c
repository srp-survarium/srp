char *__usercall i2s_ASN1_INTEGER@<eax>(int a1@<ebx>, v3_ext_method *method, asn1_string_st *a)
{
  char *result; // eax
  char *v4; // edi
  bignum_st *v5; // eax
  bignum_st *v6; // esi

  result = (char *)a;
  v4 = 0;
  if ( a )
  {
    v5 = ASN1_INTEGER_to_BN(a1, a, 0);
    v6 = v5;
    if ( !v5 || (v4 = BN_bn2dec(v5)) == 0 )
      ERR_put_error(a1, 0x22u, 120, 65, ".\\crypto\\x509v3\\v3_utl.c", 154);
    BN_free(v6);
    return v4;
  }
  return result;
}
