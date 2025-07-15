int __cdecl BN_asc2bn(bignum_st **bn, char *a)
{
  char *v2; // eax
  char v3; // cl
  bignum_st **v4; // edi
  int result; // eax

  v2 = a;
  if ( *a == 45 )
    v2 = a + 1;
  if ( *v2 == 48 && ((v3 = v2[1], v3 == 88) || v3 == 120) )
  {
    v4 = bn;
    result = BN_hex2bn(bn, v2 + 2);
    if ( !result )
      return result;
  }
  else
  {
    v4 = bn;
    result = BN_dec2bn(bn, v2);
    if ( !result )
      return result;
  }
  result = 1;
  if ( *a == 45 )
    (*v4)->neg = 1;
  return result;
}
