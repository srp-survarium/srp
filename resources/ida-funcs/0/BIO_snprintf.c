int BIO_snprintf(char *buf, unsigned int n, char *format, ...)
{
  int result; // eax
  int v4; // [esp+0h] [ebp-8h] BYREF
  unsigned int v5; // [esp+4h] [ebp-4h] BYREF

  dopr((const __m128i **)&buf, 0, &n, &v5, &v4, format);
  if ( v4 )
    return -1;
  result = v5;
  if ( v5 > 0x7FFFFFFF )
    return -1;
  return result;
}
