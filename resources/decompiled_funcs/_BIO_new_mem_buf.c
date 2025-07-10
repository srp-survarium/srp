bio_st *__cdecl BIO_new_mem_buf(const char *buf, int len)
{
  bio_st *result; // eax
  unsigned int v3; // esi
  _DWORD *ptr; // ecx

  if ( buf )
  {
    v3 = len;
    if ( len < 0 )
      v3 = strlen(buf);
    result = BIO_new(&mem_method);
    if ( result )
    {
      ptr = result->ptr;
      *ptr = v3;
      ptr[2] = v3;
      ptr[1] = buf;
      result->flags |= 0x200u;
      result->num = 0;
    }
  }
  else
  {
    ERR_put_error(0x20u, 126, 115, ".\\crypto\\bio\\bss_mem.c", 100);
    return 0;
  }
  return result;
}
