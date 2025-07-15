int __usercall ssl2_peek@<eax>(int a1@<ebx>, ssl_st *s, unsigned __int8 *buf, int len)
{
  return ssl2_read_internal(s, a1, buf, len, 1);
}
