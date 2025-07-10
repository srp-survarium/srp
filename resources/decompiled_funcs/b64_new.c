int __cdecl b64_new(bio_st *bi)
{
  _DWORD *v1; // eax

  v1 = CRYPTO_malloc(2652, ".\\crypto\\evp\\bio_b64.c", 116);
  if ( !v1 )
    return 0;
  *v1 = 0;
  v1[2] = 0;
  v1[3] = 0;
  v1[1] = 0;
  v1[6] = 1;
  v1[5] = 1;
  v1[4] = 0;
  bi->ptr = v1;
  bi->init = 1;
  bi->flags = 0;
  bi->num = 0;
  return 1;
}
