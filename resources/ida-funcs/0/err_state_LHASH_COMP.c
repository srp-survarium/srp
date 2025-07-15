// attributes: thunk
int __cdecl err_state_LHASH_COMP(const crypto_threadid_st *arg1, const crypto_threadid_st *arg2)
{
  return CRYPTO_THREADID_cmp(arg1, arg2);
}
