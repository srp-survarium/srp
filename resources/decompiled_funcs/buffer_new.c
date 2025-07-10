int __cdecl buffer_new(bio_st *bi)
{
  _DWORD *v1; // esi
  void *v2; // eax
  void *v4; // eax

  v1 = CRYPTO_malloc(32, ".\\crypto\\bio\\bf_buff.c", 97);
  if ( !v1 )
    return 0;
  v2 = CRYPTO_malloc(4096, ".\\crypto\\bio\\bf_buff.c", 99);
  v1[2] = v2;
  if ( !v2 )
  {
    CRYPTO_free(v1);
    return 0;
  }
  v4 = CRYPTO_malloc(4096, ".\\crypto\\bio\\bf_buff.c", 101);
  v1[5] = v4;
  if ( v4 )
  {
    v1[3] = 0;
    v1[4] = 0;
    v1[6] = 0;
    v1[7] = 0;
    *v1 = 4096;
    v1[1] = 4096;
    bi->flags = 0;
    bi->ptr = v1;
    bi->init = 1;
    return 1;
  }
  else
  {
    CRYPTO_free((void *)v1[2]);
    CRYPTO_free(v1);
    return 0;
  }
}
