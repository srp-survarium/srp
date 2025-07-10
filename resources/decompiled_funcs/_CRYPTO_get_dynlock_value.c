CRYPTO_dynlock_value *__cdecl CRYPTO_get_dynlock_value(int i)
{
  int v1; // edi
  _DWORD *v2; // esi
  _DWORD *v3; // eax

  v1 = i;
  v2 = 0;
  if ( i )
    v1 = -1 - i;
  CRYPTO_lock(9, 29, ".\\crypto\\cryptlib.c", 346);
  if ( dyn_locks )
  {
    if ( v1 < sk_num(&dyn_locks->stack) )
    {
      v3 = sk_value(&dyn_locks->stack, v1);
      v2 = v3;
      if ( v3 )
        ++*v3;
    }
  }
  CRYPTO_lock(10, 29, ".\\crypto\\cryptlib.c", 353);
  if ( v2 )
    return (CRYPTO_dynlock_value *)v2[1];
  else
    return 0;
}
