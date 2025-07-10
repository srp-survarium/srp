asn1_string_st *__cdecl BN_to_ASN1_INTEGER(const bignum_st *bn, asn1_string_st *ai)
{
  asn1_string_st *v2; // esi
  int v3; // eax
  int v4; // eax
  unsigned __int8 *v5; // eax
  int v7; // eax

  if ( ai )
    v2 = ai;
  else
    v2 = ASN1_STRING_type_new(2);
  if ( !v2 )
  {
    ERR_put_error(0xDu, 139, 58, ".\\crypto\\asn1\\a_int.c", 415);
LABEL_11:
    if ( v2 != ai )
      ASN1_STRING_free(v2);
    return 0;
  }
  v2->type = bn->neg != 0 ? 258 : 2;
  v3 = BN_num_bits(bn);
  if ( v3 )
    v3 = v3 / 8 + 1;
  v4 = v3 + 4;
  if ( v2->length < v4 )
  {
    v5 = (unsigned __int8 *)CRYPTO_realloc(v2->data, v4, ".\\crypto\\asn1\\a_int.c", 425);
    if ( !v5 )
    {
      ERR_put_error(0xDu, 139, 65, ".\\crypto\\asn1\\a_int.c", 428);
      goto LABEL_11;
    }
    v2->data = v5;
  }
  v7 = BN_bn2bin(bn, v2->data);
  v2->length = v7;
  if ( !v7 )
  {
    *v2->data = 0;
    v2->length = 1;
  }
  return v2;
}
