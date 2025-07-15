void __cdecl BUF_memdup(unsigned __int8 *data, unsigned int siz)
{
  unsigned __int8 *v2; // eax

  if ( data )
  {
    v2 = (unsigned __int8 *)CRYPTO_malloc(siz, ".\\crypto\\buffer\\buffer.c", 193);
    if ( v2 )
      memcpy(v2, data, siz);
    else
      ERR_put_error(7u, 103, 65, ".\\crypto\\buffer\\buffer.c", 196);
  }
}
