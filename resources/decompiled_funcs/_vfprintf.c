int __cdecl vfprintf(_iobuf *str, const char *format, char *ap)
{
  return vfprintf_helper(_output_l, str, format, 0, ap);
}
