BOOL __cdecl vostok::strings::less(char *left, char *right)
{
  return vostok::strings::compare(left, right) == -1;
}
