int __cdecl wcstombs_s(
        unsigned int *pConvertedChars,
        char *dst,
        unsigned int sizeInBytes,
        wchar_t *src,
        unsigned int n)
{
  return _wcstombs_s_l(pConvertedChars, dst, sizeInBytes, src, n, 0);
}
