int __cdecl vsprintf_s(char *string, unsigned int sizeInBytes, const char *format, char *ap)
{
  return _vsprintf_s_l(string, sizeInBytes, format, 0, ap);
}
