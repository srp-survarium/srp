unsigned int __cdecl mem_puts(bio_st *bp, char *str)
{
  return mem_write(bp, str, strlen(str));
}
