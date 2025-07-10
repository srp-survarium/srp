unsigned int __cdecl bio_puts(bio_st *bio, char *str)
{
  return bio_write(bio, str, strlen(str));
}
