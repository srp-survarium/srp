bignum_st *__usercall ASN1_ENUMERATED_to_BN@<eax>(int a1@<ebx>, asn1_string_st *ai, bignum_st *bn)
{
  bignum_st *result; // eax
  bignum_st *v4; // esi

  result = BN_bin2bn(ai->data, ai->length, bn);
  v4 = result;
  if ( result )
  {
    if ( ai->type == 266 )
    {
      BN_set_negative(result, 1);
      return v4;
    }
  }
  else
  {
    ERR_put_error(a1, 0xDu, 113, 105, ".\\crypto\\asn1\\a_enum.c", 179);
    return 0;
  }
  return result;
}
