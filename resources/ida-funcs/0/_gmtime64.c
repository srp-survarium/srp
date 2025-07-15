tm *__usercall _gmtime64@<eax>(int a1@<ebx>, const __int64 *timp)
{
  tm *result; // eax

  result = (tm *)__getgmtimebuf();
  if ( result )
    return _gmtime64_s(a1, result, timp) == 0 ? result : 0;
  return result;
}
