BOOL __cdecl _isnan(long double x)
{
  return (HIWORD(x) & 0x7FF8) == 0x7FF0 && ((HIDWORD(x) & 0x7FFFF) != 0 || LODWORD(x)) || (HIWORD(x) & 0x7FF8) == 0x7FF8;
}
