int __cdecl mbstowcs_s(unsigned int *pConvertedChars, wchar_t *pwcs, unsigned int sizeInWords, char *s, unsigned int n)
{
  return _mbstowcs_s_l(pConvertedChars, pwcs, sizeInWords, s, n, 0);
}
