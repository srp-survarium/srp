const ec_group_st *__usercall ECDSA_size@<eax>(int a1@<ebx>, const env_md_st *r)
{
  const ec_group_st *result; // eax
  const ec_group_st *v3; // edi
  bignum_st *v4; // eax
  bignum_st *v5; // esi
  int v6; // eax
  int v7; // edi
  asn1_string_st a; // [esp+0h] [ebp-10h] BYREF

  result = (const ec_group_st *)r;
  if ( r )
  {
    result = (const ec_group_st *)EVP_CIPHER_block_size(r);
    v3 = result;
    if ( result )
    {
      v4 = BN_new(a1);
      v5 = v4;
      if ( !v4 )
        return 0;
      if ( !EC_GROUP_get_order(v3, v4) )
      {
        BN_clear_free(v5);
        return 0;
      }
      a.length = (BN_num_bits(v5) + 7) / 8;
      a.data = (unsigned __int8 *)&r;
      a.type = 2;
      LOBYTE(r) = -1;
      v6 = i2d_ASN1_INTEGER(&a, 0);
      v7 = ASN1_object_size(1, 2 * v6, 16);
      BN_clear_free(v5);
      return (const ec_group_st *)v7;
    }
  }
  return result;
}
