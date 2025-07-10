int __cdecl buffer_puts(bio_st *b, char *str)
{
  return buffer_write(b, str, strlen(str));
}
