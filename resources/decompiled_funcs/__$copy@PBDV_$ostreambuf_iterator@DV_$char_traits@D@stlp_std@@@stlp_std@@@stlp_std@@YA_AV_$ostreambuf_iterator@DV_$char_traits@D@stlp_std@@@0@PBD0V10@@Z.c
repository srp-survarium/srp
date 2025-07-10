stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *__cdecl stlp_std::copy<char const *,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>>(
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        const char *__first,
        const char *__last,
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > __result)
{
  stlp_std::priv::__copy<char const *,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>,int>(
    result,
    __first,
    __last,
    __result);
  return result;
}
