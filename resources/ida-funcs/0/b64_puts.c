int __usercall b64_puts@<eax>(unsigned int a1@<edi>, bio_st *b, char *str)
{
  return b64_write(a1, b, str, strlen(str));
}
