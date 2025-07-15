int __usercall ssl23_peek@<eax>(int a1@<ebx>, ssl_st *s)
{
  int result; // eax

  SetLastError(0);
  if ( (SSL_state(s) & 0x3000) == 0 || s->in_handshake )
  {
    ssl_undefined_function(a1);
    return -1;
  }
  else
  {
    result = s->handshake_func(s);
    if ( result >= 0 )
    {
      if ( result )
      {
        return SSL_peek(a1, s);
      }
      else
      {
        ERR_put_error(a1, 0x14u, 237, 229, ".\\ssl\\s23_lib.c", 154);
        return -1;
      }
    }
  }
  return result;
}
