char __cdecl stlp_std::priv::__get_fdigit_or_sep(wchar_t *c, wchar_t sep, const wchar_t *digits)
{
  const wchar_t *v4; // eax

  if ( *c == sep )
  {
    *c = 44;
    return 1;
  }
  else
  {
    v4 = stlp_std::priv::__find<wchar_t const *,wchar_t>(digits, digits + 10, c);
    if ( v4 == digits + 10 )
    {
      return 0;
    }
    else
    {
      *c = (char)(v4 - digits + 48);
      return 1;
    }
  }
}
