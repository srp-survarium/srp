int __cdecl CRYPTO_THREADID_cmp(const crypto_threadid_st *a, const crypto_threadid_st *b)
{
  unsigned int v4; // eax
  int v6; // eax

  v4 = 8;
  while ( a->ptr == b->ptr )
  {
    v4 -= 4;
    b = (const crypto_threadid_st *)((char *)b + 4);
    a = (const crypto_threadid_st *)((char *)a + 4);
    if ( v4 < 4 )
      return 0;
  }
  v6 = LOBYTE(a->ptr) - LOBYTE(b->ptr);
  if ( !v6 )
  {
    v6 = BYTE1(a->ptr) - BYTE1(b->ptr);
    if ( !v6 )
    {
      v6 = BYTE2(a->ptr) - BYTE2(b->ptr);
      if ( !v6 )
        v6 = HIBYTE(a->ptr) - HIBYTE(b->ptr);
    }
  }
  return (v6 >> 31) | 1;
}
