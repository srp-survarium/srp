int __cdecl asn1_bio_puts(bio_st *b, const char *str)
{
  return asn1_bio_write(b, str, strlen(str));
}
