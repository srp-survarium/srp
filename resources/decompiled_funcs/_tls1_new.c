int __cdecl tls1_new(ssl_st *s)
{
  int result; // eax

  result = ssl3_new(s);
  if ( result )
  {
    s->method->ssl_clear(s);
    return 1;
  }
  return result;
}
