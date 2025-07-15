buf_mem_st *__usercall BUF_MEM_new@<eax>(int a1@<ebx>)
{
  buf_mem_st *result; // eax

  result = (buf_mem_st *)CRYPTO_malloc(12, ".\\crypto\\buffer\\buffer.c", 67);
  if ( result )
  {
    result->length = 0;
    result->max = 0;
    result->data = 0;
  }
  else
  {
    ERR_put_error(a1, 7u, 101, 65, ".\\crypto\\buffer\\buffer.c", 70);
    return 0;
  }
  return result;
}
