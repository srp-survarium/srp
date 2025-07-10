int __cdecl mbtowc(wchar_t *pwc, const char *s, unsigned int n)
{
  return _mbtowc_l(pwc, s, n, 0);
}
