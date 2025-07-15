void __cdecl CRYPTO_destroy_dynlockid(int i)
{
  int v1; // edi
  char *v2; // eax
  CRYPTO_dynlock_value **v3; // esi

  v1 = i;
  if ( i )
    v1 = -1 - i;
  if ( dynlock_destroy_callback )
  {
    CRYPTO_lock(v1, 9, 29, ".\\crypto\\cryptlib.c", 305);
    if ( dyn_locks && v1 < sk_num(&dyn_locks->stack) )
    {
      v2 = sk_value(&dyn_locks->stack, v1);
      v3 = (CRYPTO_dynlock_value **)v2;
      if ( v2 )
      {
        if ( (int)--*(_DWORD *)v2 > 0 )
          v3 = 0;
        else
          sk_set(&dyn_locks->stack, v1, 0);
      }
      CRYPTO_lock(v1, 10, 29, ".\\crypto\\cryptlib.c", 331);
      if ( v3 )
      {
        dynlock_destroy_callback(v3[1], ".\\crypto\\cryptlib.c", 335);
        CRYPTO_free(v3);
      }
    }
    else
    {
      CRYPTO_lock(v1, 10, 29, ".\\crypto\\cryptlib.c", 309);
    }
  }
}
