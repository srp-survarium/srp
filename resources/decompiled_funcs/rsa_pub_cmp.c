BOOL __cdecl rsa_pub_cmp(const evp_pkey_st *a, const evp_pkey_st *b)
{
  return !BN_cmp(*((const bignum_st **)b->pkey.ptr + 4), *((const bignum_st **)a->pkey.ptr + 4))
      && !BN_cmp(*((const bignum_st **)b->pkey.ptr + 5), *((const bignum_st **)a->pkey.ptr + 5));
}
