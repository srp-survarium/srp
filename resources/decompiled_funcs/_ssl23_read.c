int __cdecl ssl23_read(ssl_st *s)
{
  int result; // eax

  SetLastError(0);
  if ( (SSL_state(s) & 0x3000) == 0 || s->in_handshake )
  {
    ssl_undefined_function();
    return -1;
  }
  else
  {
    result = s->handshake_func(s);
    if ( result >= 0 )
    {
      if ( result )
      {
        return SSL_read(s);
      }
      else
      {
        ERR_put_error(0x14u, 120, 229, ".\\ssl\\s23_lib.c", 131);
        return -1;
      }
    }
  }
  return result;
}
