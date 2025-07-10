bool __cdecl vostok::strings::less(const char *left, const char *right)
{
  int v2; // kr00_4

  v2 = strcmp(left, right);
  return v2 && -(v2 < 0) - ((v2 < 0) - 1) == -1;
}
