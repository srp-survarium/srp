unsigned int BIO_snprintf(char *buf, unsigned int n, char *format, ...)
{
  unsigned int result; // eax
  int truncated; // [esp+0h] [ebp-8h] BYREF
  unsigned int retlen; // [esp+4h] [ebp-4h] BYREF

  dopr(&buf, 0, &n, &retlen, &truncated, format);
  if ( truncated )
    return -1;
  result = retlen;
  if ( retlen > 0x7FFFFFFF )
    return -1;
  return result;
}
