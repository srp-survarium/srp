stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__cdecl stlp_std::copy<wchar_t const *,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>(
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        wchar_t *__first,
        const wchar_t *__last,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __result)
{
  stlp_std::priv::__copy<wchar_t const *,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,int>(
    result,
    __first,
    __last,
    __result);
  return result;
}
