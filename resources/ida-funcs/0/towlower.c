int __cdecl towlower(wchar_t c)
{
  return _towlower_l(c, 0);
}
