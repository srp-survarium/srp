int __usercall b64_puts@<eax>(int a1@<edi>, bio_st *b, const __m128i *str)
{
  return b64_write(a1, b, str, strlen(str->m128i_i8));
}
