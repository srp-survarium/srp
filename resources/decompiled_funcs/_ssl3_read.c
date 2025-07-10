int __cdecl ssl3_read(ssl_st *s, unsigned __int8 *buf, int len)
{
  return ssl3_read_internal(s, len, 0, buf);
}
