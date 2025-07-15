const env_md_st *__cdecl ECDSA_size(const env_md_st *r)
{
  const env_md_st *result; // eax
  const ec_group_st *v2; // edi
  bignum_st *v3; // eax
  bignum_st *v4; // esi
  int v5; // eax
  int v6; // edi
  asn1_string_st a; // [esp+0h] [ebp-10h] BYREF

  result = r;
  if ( r )
  {
    result = (const env_md_st *)EVP_CIPHER_block_size(r);
    v2 = (const ec_group_st *)result;
    if ( result )
    {
      v3 = BN_new();
      v4 = v3;
      if ( !v3 )
        return 0;
      if ( !EC_GROUP_get_order(v2, v3) )
      {
        BN_clear_free(v4);
        return 0;
      }
      a.length = (BN_num_bits(v4) + 7) / 8;
      a.data = (unsigned __int8 *)&r;
      a.type = 2;
      LOBYTE(r) = -1;
      v5 = i2d_ASN1_INTEGER(&a, 0);
      v6 = ASN1_object_size(1, 2 * v5, 16);
      BN_clear_free(v4);
      return (const env_md_st *)v6;
    }
  }
  return result;
}
