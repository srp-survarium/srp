// attributes: thunk
int __cdecl err_state_LHASH_COMP(const crypto_threadid_st *a1, const crypto_threadid_st *a2)
{
  return CRYPTO_THREADID_cmp(a1, a2);
}
