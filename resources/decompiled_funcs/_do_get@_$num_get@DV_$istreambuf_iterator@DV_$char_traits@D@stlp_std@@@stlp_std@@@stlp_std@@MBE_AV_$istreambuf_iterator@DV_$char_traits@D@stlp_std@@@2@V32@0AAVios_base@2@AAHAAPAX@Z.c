stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *__thiscall stlp_std::num_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>>::do_get(
        stlp_std::num_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > > *this,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > __in_ite,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > __end,
        stlp_std::ios_base *__str,
        int *__err,
        void **__p)
{
  int *v7; // esi
  stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *v8; // eax
  unsigned __int64 __val; // [esp+8h] [ebp-8h] BYREF

  v7 = __err;
  stlp_std::priv::__do_get_integer<stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>,unsigned __int64,char>(
    result,
    &__in_ite,
    &__end,
    __str,
    __err,
    &__val);
  v8 = result;
  if ( (*(_BYTE *)v7 & 4) == 0 )
    *__p = (void *)__val;
  return v8;
}
