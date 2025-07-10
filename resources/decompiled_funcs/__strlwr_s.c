int __cdecl _strlwr_s(char *string, unsigned int sizeInBytes)
{
  return _strlwr_s_l(string, sizeInBytes, 0);
}
