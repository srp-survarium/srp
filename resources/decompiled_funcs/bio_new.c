int __cdecl bio_new(bio_st *bio)
{
  int result; // eax

  result = (int)CRYPTO_malloc(28, ".\\crypto\\bio\\bss_bio.c", 149);
  if ( result )
  {
    *(_DWORD *)result = 0;
    *(_DWORD *)(result + 16) = 17408;
    *(_DWORD *)(result + 20) = 0;
    bio->ptr = (void *)result;
    return 1;
  }
  return result;
}
