stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *__thiscall stlp_std::num_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>>::do_get(
        stlp_std::num_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > > *this,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > __in_ite,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > __end,
        stlp_std::ios_base *__str,
        int *__err,
        unsigned __int16 *__val)
{
  stlp_std::priv::__do_get_integer<stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>,unsigned short,char>(
    result,
    &__in_ite,
    &__end,
    __str,
    __err,
    __val);
  return result;
}


stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *__thiscall stlp_std::num_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>>::do_get(
        stlp_std::num_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > > *this,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > __in_ite,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > __end,
        stlp_std::ios_base *__str,
        int *__err,
        unsigned int *__val)
{
  stlp_std::priv::__do_get_integer<stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>,unsigned int,char>(
    result,
    &__in_ite,
    &__end,
    __str,
    __err,
    __val);
  return result;
}


stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *__thiscall stlp_std::num_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>>::do_get(
        stlp_std::num_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > > *this,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > __in_ite,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > __end,
        stlp_std::ios_base *__str,
        int *__err,
        int *__val)
{
  stlp_std::priv::__do_get_integer<stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>,long,char>(
    result,
    &__in_ite,
    &__end,
    __str,
    __err,
    __val);
  return result;
}


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


stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *__thiscall stlp_std::num_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>>::do_get(
        stlp_std::num_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > > *this,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > __in_ite,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > __end,
        stlp_std::ios_base *__str,
        int *__err,
        long double *__val)
{
  stlp_std::priv::__do_get_float<stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>,long double,char>(
    result,
    &__in_ite,
    &__end,
    __str,
    __err,
    __val);
  return result;
}


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


stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *__thiscall stlp_std::num_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>>::do_get(
        stlp_std::num_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > > *this,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > __in_ite,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > __end,
        stlp_std::ios_base *__str,
        int *__err,
        __int64 *__val)
{
  stlp_std::priv::__do_get_integer<stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>,__int64,char>(
    result,
    &__in_ite,
    &__end,
    __str,
    __err,
    __val);
  return result;
}


stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *__thiscall stlp_std::num_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>>::do_get(
        stlp_std::num_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > > *this,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > __in_ite,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > __end,
        stlp_std::ios_base *__str,
        int *__err,
        unsigned __int64 *__val)
{
  stlp_std::priv::__do_get_integer<stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>,unsigned __int64,char>(
    result,
    &__in_ite,
    &__end,
    __str,
    __err,
    __val);
  return result;
}


stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *__thiscall stlp_std::num_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>>::do_get(
        stlp_std::num_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > > *this,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > __in_ite,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > __end,
        stlp_std::ios_base *__s,
        int *__err,
        bool *__x)
{
  stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *v7; // eax
  int *v8; // esi
  int v9; // ecx
  stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > __tmp; // [esp+4h] [ebp-8h] BYREF

  if ( (__s->_M_fmtflags & 0x100) != 0 )
  {
    stlp_std::priv::__do_get_alphabool<stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>,char>(
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
    stlp_std::priv::__do_get_integer<stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>,long,char>(
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


stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__thiscall stlp_std::num_get<wchar_t,stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::do_get(
        stlp_std::num_get<wchar_t,stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > > *this,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __in_ite,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __end,
        stlp_std::ios_base *__str,
        int *__err,
        unsigned __int16 *__val)
{
  stlp_std::priv::__do_get_integer<stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,unsigned short,wchar_t>(
    result,
    &__in_ite,
    &__end,
    __str,
    __err,
    __val);
  return result;
}


stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__thiscall stlp_std::num_get<wchar_t,stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::do_get(
        stlp_std::num_get<wchar_t,stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > > *this,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __in_ite,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __end,
        stlp_std::ios_base *__str,
        int *__err,
        unsigned int *__val)
{
  stlp_std::priv::__do_get_integer<stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,unsigned int,wchar_t>(
    result,
    &__in_ite,
    &__end,
    __str,
    __err,
    __val);
  return result;
}


stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__thiscall stlp_std::num_get<wchar_t,stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::do_get(
        stlp_std::num_get<wchar_t,stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > > *this,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __in_ite,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __end,
        stlp_std::ios_base *__str,
        int *__err,
        int *__val)
{
  stlp_std::priv::__do_get_integer<stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,long,wchar_t>(
    result,
    &__in_ite,
    &__end,
    __str,
    __err,
    __val);
  return result;
}


stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__thiscall stlp_std::num_get<wchar_t,stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::do_get(
        stlp_std::num_get<wchar_t,stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > > *this,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __in_ite,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __end,
        stlp_std::ios_base *__str,
        int *__err,
        float *__val)
{
  stlp_std::priv::__do_get_float<stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,float,wchar_t>(
    result,
    &__in_ite,
    &__end,
    __str,
    __err,
    __val);
  return result;
}


stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__thiscall stlp_std::num_get<wchar_t,stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::do_get(
        stlp_std::num_get<wchar_t,stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > > *this,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __in_ite,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __end,
        stlp_std::ios_base *__str,
        int *__err,
        long double *__val)
{
  stlp_std::priv::__do_get_float<stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,long double,wchar_t>(
    result,
    &__in_ite,
    &__end,
    __str,
    __err,
    __val);
  return result;
}


stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__thiscall stlp_std::num_get<wchar_t,stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::do_get(
        stlp_std::num_get<wchar_t,stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > > *this,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __in_ite,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __end,
        stlp_std::ios_base *__str,
        int *__err,
        void **__p)
{
  int *v7; // esi
  stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *v8; // eax
  unsigned __int64 __val; // [esp+8h] [ebp-8h] BYREF

  v7 = __err;
  stlp_std::priv::__do_get_integer<stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,unsigned __int64,wchar_t>(
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


stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__thiscall stlp_std::num_get<wchar_t,stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::do_get(
        stlp_std::num_get<wchar_t,stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > > *this,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __in_ite,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __end,
        stlp_std::ios_base *__str,
        int *__err,
        unsigned __int64 *__val)
{
  stlp_std::priv::__do_get_integer<stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,unsigned __int64,wchar_t>(
    result,
    &__in_ite,
    &__end,
    __str,
    __err,
    __val);
  return result;
}


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
