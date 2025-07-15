bio_st *__usercall BIO_new_mem_buf@<eax>(int a1@<ebx>, const char *buf, int len)
{
  bio_st *result; // eax
  unsigned int v4; // esi
  _DWORD *ptr; // ecx

  if ( buf )
  {
    v4 = len;
    if ( len < 0 )
      v4 = strlen(buf);
    result = BIO_new(a1, &mem_method);
    if ( result )
    {
      ptr = result->ptr;
      *ptr = v4;
      ptr[2] = v4;
      ptr[1] = buf;
      result->flags |= 0x200u;
      result->num = 0;
    }
  }
  else
  {
    ERR_put_error(a1, 0x20u, 126, 115, ".\\crypto\\bio\\bss_mem.c", 100);
    return 0;
  }
  return result;
}
