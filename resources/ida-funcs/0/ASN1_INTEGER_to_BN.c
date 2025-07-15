bignum_st *__cdecl ASN1_INTEGER_to_BN(const asn1_string_st *ai, bignum_st *bn)
{
  bignum_st *result; // eax
  bignum_st *v3; // esi

  result = BN_bin2bn(ai->data, ai->length, bn);
  v3 = result;
  if ( result )
  {
    if ( ai->type == 258 )
    {
      BN_set_negative(result, 1);
      return v3;
    }
  }
  else
  {
    ERR_put_error(0xDu, 119, 105, ".\\crypto\\asn1\\a_int.c", 451);
    return 0;
  }
  return result;
}
