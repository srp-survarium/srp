stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__thiscall stlp_std::num_get<wchar_t,stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::do_get(
        stlp_std::num_get<wchar_t,stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > > *this,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __in_ite,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __end,
        stlp_std::ios_base *__s,
        int *__err,
        bool *__x)
{
  stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *v7; // eax
  int *v8; // esi
  int v9; // ecx
  stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __tmp; // [esp+4h] [ebp-8h] BYREF

  if ( (__s->_M_fmtflags & 0x100) != 0 )
  {
    stlp_std::priv::__do_get_alphabool<stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,wchar_t>(
      result,
      &__in_ite,
      &__end,
      __s,
      __err,
      __x);
    return result;
  }
  else
  {
    v8 = __err;
    stlp_std::priv::__do_get_integer<stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,long,wchar_t>(
      &__tmp,
      &__in_ite,
      &__end,
      __s,
      __err,
      (int *)&__err);
    if ( (*v8 & 4) == 0 )
    {
      if ( __err )
      {
        if ( __err == (int *)1 )
          *__x = 1;
        else
          *v8 |= 4u;
      }
      else
      {
        *__x = 0;
      }
    }
    v7 = result;
    v9 = *(_DWORD *)&__tmp._M_c;
    result->_M_buf = __tmp._M_buf;
    *(_DWORD *)&result->_M_c = v9;
  }
  return v7;
}
