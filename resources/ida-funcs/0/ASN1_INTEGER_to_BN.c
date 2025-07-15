bignum_st *__usercall ASN1_INTEGER_to_BN@<eax>(int a1@<ebx>, const asn1_string_st *ai, bignum_st *bn)
{
  bignum_st *result; // eax
  bignum_st *v4; // esi

  result = BN_bin2bn(ai->data, ai->length, bn);
  v4 = result;
  if ( result )
  {
    if ( ai->type == 258 )
    {
      BN_set_negative(result, 1);
      return v4;
    }
  }
  else
  {
    ERR_put_error(a1, 0xDu, 119, 105, ".\\crypto\\asn1\\a_int.c", 451);
    return 0;
  }
  return result;
}
