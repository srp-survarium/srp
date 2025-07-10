stack_st *__cdecl sk_new(int (__cdecl *c)(const void *, const void *))
{
  _DWORD *v1; // esi
  _DWORD *v2; // eax

  v1 = CRYPTO_malloc(20, ".\\crypto\\stack\\stack.c", 125);
  if ( !v1 )
    return 0;
  v2 = CRYPTO_malloc(16, ".\\crypto\\stack\\stack.c", 127);
  v1[1] = v2;
  if ( !v2 )
  {
    CRYPTO_free(v1);
    return 0;
  }
  *v2 = 0;
  *(_DWORD *)(v1[1] + 4) = 0;
  *(_DWORD *)(v1[1] + 8) = 0;
  *(_DWORD *)(v1[1] + 12) = 0;
  *v1 = 0;
  v1[2] = 0;
  v1[4] = c;
  v1[3] = 4;
  return (stack_st *)v1;
}
