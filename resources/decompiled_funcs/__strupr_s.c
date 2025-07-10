int __cdecl _strupr_s(char *string, unsigned int sizeInBytes)
{
  return _strupr_s_l(string, sizeInBytes, 0);
}
