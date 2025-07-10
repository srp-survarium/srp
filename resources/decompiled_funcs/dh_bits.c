int __cdecl dh_bits(const evp_pkey_st *pkey)
{
  return BN_num_bits(*((const bignum_st **)pkey->pkey.ptr + 2));
}
