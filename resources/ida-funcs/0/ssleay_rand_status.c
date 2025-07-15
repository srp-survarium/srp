int __usercall ssleay_rand_status@<eax>(unsigned int a1@<ebx>)
{
  int v1; // edi
  unsigned int v2; // esi
  crypto_threadid_st id; // [esp+8h] [ebp-8h] BYREF

  CRYPTO_THREADID_current(&id);
  v1 = 1;
  if ( crypto_lock_rand )
  {
    CRYPTO_lock(1, a1, 5, 19, ".\\crypto\\rand\\md_rand.c", 558);
    v2 = CRYPTO_THREADID_cmp(&locking_threadid, &id) == 0;
    CRYPTO_lock(1, a1, 6, 19, ".\\crypto\\rand\\md_rand.c", 560);
    if ( v2 )
      goto LABEL_4;
  }
  else
  {
    v2 = 0;
  }
  CRYPTO_lock(1, a1, 9, 18, ".\\crypto\\rand\\md_rand.c", 567);
  CRYPTO_lock(1, a1, 9, 19, ".\\crypto\\rand\\md_rand.c", 570);
  CRYPTO_THREADID_cpy(&locking_threadid, &id);
  CRYPTO_lock(1, a1, 10, 19, ".\\crypto\\rand\\md_rand.c", 572);
  crypto_lock_rand = 1;
LABEL_4:
  if ( !initialized )
  {
    RAND_poll(a1, 1, v2);
    initialized = 1;
  }
  if ( entropy < 32.0 )
    v1 = 0;
  if ( !v2 )
  {
    crypto_lock_rand = 0;
    CRYPTO_lock(v1, a1, 10, 18, ".\\crypto\\rand\\md_rand.c", 589);
  }
  return v1;
}
