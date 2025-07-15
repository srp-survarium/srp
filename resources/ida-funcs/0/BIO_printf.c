int BIO_printf(bio_st *bio, char *format, ...)
{
  va_list va; // [esp+Ch] [ebp+Ch] BYREF

  va_start(va, format);
  return BIO_vprintf(bio, format, (int)va);
}
