int __usercall asn1_bio_puts@<eax>(int a1@<ebx>, bio_st *b, char *str)
{
  return asn1_bio_write(a1, b, str, strlen(str));
}
