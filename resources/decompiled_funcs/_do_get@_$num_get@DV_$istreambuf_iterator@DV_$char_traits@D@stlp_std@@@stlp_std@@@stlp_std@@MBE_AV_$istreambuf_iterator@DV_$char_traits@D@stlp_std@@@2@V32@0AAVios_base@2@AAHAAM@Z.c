stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *__thiscall stlp_std::num_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>>::do_get(
        stlp_std::num_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > > *this,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > __in_ite,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > __end,
        stlp_std::ios_base *__str,
        int *__err,
        float *__val)
{
  stlp_std::priv::__do_get_float<stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>,float,char>(
    result,
    &__in_ite,
    &__end,
    __str,
    __err,
    __val);
  return result;
}
