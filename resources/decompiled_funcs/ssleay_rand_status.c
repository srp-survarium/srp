unsigned int __cdecl ssleay_rand_status()
{
  unsigned int v0; // edi
  BOOL v1; // esi
  crypto_threadid_st id; // [esp+8h] [ebp-8h] BYREF

  CRYPTO_THREADID_current(&id);
  v0 = 1;
  if ( crypto_lock_rand )
  {
    CRYPTO_lock(1u, 5, 19, ".\\crypto\\rand\\md_rand.c", 558);
    v1 = CRYPTO_THREADID_cmp(&locking_threadid, &id) == 0;
    CRYPTO_lock(1u, 6, 19, ".\\crypto\\rand\\md_rand.c", 560);
    if ( v1 )
      goto LABEL_4;
  }
  else
  {
    v1 = 0;
  }
  CRYPTO_lock(1u, 9, 18, ".\\crypto\\rand\\md_rand.c", 567);
  CRYPTO_lock(1u, 9, 19, ".\\crypto\\rand\\md_rand.c", 570);
  CRYPTO_THREADID_cpy(&locking_threadid, &id);
  CRYPTO_lock(1u, 10, 19, ".\\crypto\\rand\\md_rand.c", 572);
  crypto_lock_rand = 1;
LABEL_4:
  if ( !initialized )
  {
    RAND_poll();
    initialized = 1;
  }
  if ( entropy < 32.0 )
    v0 = 0;
  if ( !v1 )
  {
    crypto_lock_rand = 0;
    CRYPTO_lock(v0, 10, 18, ".\\crypto\\rand\\md_rand.c", 589);
  }
  return v0;
}
