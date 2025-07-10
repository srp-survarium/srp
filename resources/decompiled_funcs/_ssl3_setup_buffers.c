int __cdecl ssl3_setup_buffers(ssl_st *s)
{
  int result; // eax

  result = ssl3_setup_read_buffer(s);
  if ( result )
    return ssl3_setup_write_buffer(s) != 0;
  return result;
}
