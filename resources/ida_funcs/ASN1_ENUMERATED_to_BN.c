bignum_st *__cdecl ASN1_ENUMERATED_to_BN(asn1_string_st *ai, bignum_st *bn)
{
  bignum_st *result; // eax
  bignum_st *v3; // esi

  result = BN_bin2bn(ai->data, ai->length, bn);
  v3 = result;
  if ( result )
  {
    if ( ai->type == 266 )
    {
      BN_set_negative(result, 1);
      return v3;
    }
  }
  else
  {
    ERR_put_error(0xDu, 113, 105, ".\\crypto\\asn1\\a_enum.c", 179);
    return 0;
  }
  return result;
}
