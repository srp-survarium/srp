int __cdecl atol(const char *nptr)
{
  return strtol(nptr, 0, 10);
}
