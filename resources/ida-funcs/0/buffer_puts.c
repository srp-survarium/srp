int __cdecl buffer_puts(bio_st *b, const __m128i *str)
{
  return buffer_write(b, str, strlen(str->m128i_i8));
}
