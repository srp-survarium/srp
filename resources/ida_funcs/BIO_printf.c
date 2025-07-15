unsigned int BIO_printf(bio_st *bio, char *format, ...)
{
  return BIO_vprintf(bio, format);
}
