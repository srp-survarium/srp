int __cdecl DH_compute_key(unsigned __int8 *key, const bignum_st *pub_key, dh_st *dh)
{
  return ((int (*)(void))dh->meth->compute_key)();
}
