int __cdecl sock_puts(bio_st *bp, const char *str)
{
  return sock_write(bp, str, strlen(str));
}
