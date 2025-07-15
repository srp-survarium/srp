char __cdecl stlp_std::priv::__get_fdigit(wchar_t *c, const wchar_t *digits)
{
  const wchar_t *v2; // eax

  v2 = stlp_std::priv::__find<wchar_t const *,wchar_t>(digits, digits + 10, c);
  if ( v2 == digits + 10 )
    return 0;
  *c = (char)(v2 - digits + 48);
  return 1;
}
