void __cdecl BUF_MEM_free(buf_mem_st *a)
{
  char *data; // eax

  if ( a )
  {
    data = a->data;
    if ( data )
    {
      memset((int)data, 0, a->max);
      CRYPTO_free(a->data);
    }
    CRYPTO_free(a);
  }
}
