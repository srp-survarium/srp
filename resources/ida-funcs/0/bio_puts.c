unsigned int __cdecl bio_puts(bio_st *bio, const __m128i *str)
{
  return bio_write(bio, str, strlen(str->m128i_i8));
}
