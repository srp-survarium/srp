long double __cdecl atof(char *nptr)
{
  return _atof_l(nptr, 0);
}
