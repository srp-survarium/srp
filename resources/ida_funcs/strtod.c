double __cdecl strtod(char *nptr, char **endptr)
{
  return _strtod_l(nptr, endptr, 0);
}
