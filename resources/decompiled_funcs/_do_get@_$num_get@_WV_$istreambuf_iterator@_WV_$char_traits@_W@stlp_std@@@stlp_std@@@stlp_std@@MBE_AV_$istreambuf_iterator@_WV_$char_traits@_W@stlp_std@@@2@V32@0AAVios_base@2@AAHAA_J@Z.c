stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__thiscall stlp_std::num_get<wchar_t,stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::do_get(
        stlp_std::num_get<wchar_t,stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > > *this,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __in_ite,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __end,
        stlp_std::ios_base *__str,
        int *__err,
        __int64 *__val)
{
  stlp_std::priv::__do_get_integer<stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,__int64,wchar_t>(
    result,
    &__in_ite,
    &__end,
    __str,
    __err,
    __val);
  return result;
}
