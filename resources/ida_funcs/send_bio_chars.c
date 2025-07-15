BOOL __cdecl send_bio_chars(bio_st *arg, const char *buf, int len)
{
  return !arg || BIO_write(arg, buf, len) == len;
}
