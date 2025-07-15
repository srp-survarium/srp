int __usercall mbstowcs_s@<eax>(
        int a1@<edi>,
        unsigned int *pConvertedChars,
        wchar_t *pwcs,
        unsigned int sizeInWords,
        char *s,
        unsigned int n)
{
  return _mbstowcs_s_l(a1, pConvertedChars, pwcs, sizeInWords, s, n, 0);
}
