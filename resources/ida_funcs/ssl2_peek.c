int __cdecl ssl2_peek(ssl_st *s, unsigned __int8 *buf, int len)
{
  return ssl2_read_internal(s, buf, len, 1);
}
