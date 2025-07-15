int __cdecl bio_free(bio_st *bio)
{
  int *ptr; // esi
  int v3; // ecx
  _DWORD *v4; // eax

  if ( !bio )
    return 0;
  ptr = (int *)bio->ptr;
  if ( *ptr )
  {
    if ( ptr )
    {
      v3 = *ptr;
      if ( *ptr )
      {
        v4 = *(_DWORD **)(v3 + 32);
        *v4 = 0;
        *(_DWORD *)(v3 + 12) = 0;
        v4[2] = 0;
        v4[3] = 0;
        *ptr = 0;
        bio->init = 0;
        ptr[2] = 0;
        ptr[3] = 0;
      }
    }
  }
  if ( ptr[5] )
    CRYPTO_free((void *)ptr[5]);
  CRYPTO_free(ptr);
  return 1;
}
