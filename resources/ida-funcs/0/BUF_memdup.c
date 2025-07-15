void __usercall BUF_memdup(int a1@<ebx>, const __m128i *data, unsigned int siz)
{
  void *v3; // eax

  if ( data )
  {
    v3 = CRYPTO_malloc(siz, ".\\crypto\\buffer\\buffer.c", 193);
    if ( v3 )
      memcpy((int)v3, data, siz);
    else
      ERR_put_error(a1, 7u, 103, 65, ".\\crypto\\buffer\\buffer.c", 196);
  }
}
