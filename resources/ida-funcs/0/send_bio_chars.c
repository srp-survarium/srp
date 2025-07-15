BOOL __usercall send_bio_chars@<eax>(int a1@<ebx>, bio_st *arg, const char *buf, int len)
{
  return !arg || BIO_write(a1, arg, buf, len) == len;
}
