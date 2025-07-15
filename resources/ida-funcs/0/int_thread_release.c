void __cdecl int_thread_release(lhash_st_ERR_STATE **hash)
{
  if ( hash && *hash && CRYPTO_add_lock(&int_thread_hash_references, -1, 1, ".\\crypto\\err\\err.c", 469) <= 0 )
    *hash = 0;
}
