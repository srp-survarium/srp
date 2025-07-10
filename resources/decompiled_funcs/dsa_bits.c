int __cdecl dsa_bits(const evp_pkey_st *pkey)
{
  return BN_num_bits(*((const bignum_st **)pkey->pkey.ptr + 3));
}
