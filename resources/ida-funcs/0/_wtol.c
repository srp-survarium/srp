int __cdecl _wtol(const wchar_t *nptr)
{
  return wcstol(nptr, 0, 10);
}
