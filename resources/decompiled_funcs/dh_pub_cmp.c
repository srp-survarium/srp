BOOL __cdecl dh_pub_cmp(const evp_pkey_st *a, const evp_pkey_st *b)
{
  return !BN_cmp(*((const bignum_st **)a->pkey.ptr + 2), *((const bignum_st **)b->pkey.ptr + 2))
      && !BN_cmp(*((const bignum_st **)a->pkey.ptr + 3), *((const bignum_st **)b->pkey.ptr + 3))
      && BN_cmp(*((const bignum_st **)b->pkey.ptr + 5), *((const bignum_st **)a->pkey.ptr + 5)) == 0;
}
