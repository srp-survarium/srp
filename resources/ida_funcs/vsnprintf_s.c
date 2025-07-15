int __cdecl vsnprintf_s(char *string, unsigned int sizeInBytes, unsigned int count, const char *format, char *ap)
{
  return _vsnprintf_s_l(string, sizeInBytes, count, format, 0, ap);
}
