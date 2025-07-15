crypto_threadid_st *__cdecl BN_BLINDING_thread_id(bn_blinding_st *b)
{
  return &b->tid;
}
