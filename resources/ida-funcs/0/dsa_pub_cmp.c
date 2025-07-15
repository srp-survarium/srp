BOOL __cdecl dsa_pub_cmp(const evp_pkey_st *a, const evp_pkey_st *b)
{
  return BN_cmp(*((const bignum_st **)b->pkey.ptr + 6), *((const bignum_st **)a->pkey.ptr + 6)) == 0;
}
