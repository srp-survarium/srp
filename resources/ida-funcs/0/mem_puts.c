unsigned int __usercall mem_puts@<eax>(int a1@<ebx>, bio_st *bp, const __m128i *str)
{
  return mem_write(a1, bp, str, strlen(str->m128i_i8));
}
