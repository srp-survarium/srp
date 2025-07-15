stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *__cdecl stlp_std::priv::__copy_float_and_fill<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>>(
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        const char *__first,
        const char *__last,
        __int64 __oi,
        char __flags,
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > __width,
        char __fill,
        char __xplus,
        char __xminus)
{
  __int64 v9; // rax
  unsigned int v11; // ecx
  char *v12; // ebx
  int v13; // eax
  unsigned int v14; // ebp
  stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *v15; // eax
  stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *v16; // eax

  v9 = __last - __first;
  if ( *(_QWORD *)&__width > v9 )
  {
    v11 = (unsigned __int64)(*(_QWORD *)&__width - v9) >> 32;
    v12 = (char *)__width._M_buf - v9;
    v13 = __flags & 7;
    v14 = v11;
    if ( v13 == 1 )
    {
      stlp_std::priv::__copy<char const *,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>,int>(
        &__width,
        __first,
        __last,
        (stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> >)__oi);
      __oi = (__int64)__width;
      stlp_std::priv::__fill_n<stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>,__int64,char>(
        result,
        __width,
        __SPAIR64__(v14, (unsigned int)v12),
        &__fill);
      return result;
    }
    else if ( v13 == 4 && __first != __last && (*__first == __xplus || *__first == __xminus) )
    {
      stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>::operator=(
        (stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *)&__oi,
        *__first);
      v15 = stlp_std::priv::__fill_n<stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>,__int64,char>(
              &__width,
              (stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> >)__oi,
              __SPAIR64__(v14, (unsigned int)v12),
              &__fill);
      __oi = *(__int64 *)v15;
      stlp_std::copy<char const *,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>>(
        result,
        __first + 1,
        __last,
        *v15);
      return result;
    }
    else
    {
      v16 = stlp_std::priv::__fill_n<stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>,__int64,char>(
              &__width,
              (stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> >)__oi,
              __SPAIR64__(v11, (unsigned int)v12),
              &__fill);
      __oi = *(__int64 *)v16;
      stlp_std::priv::__copy<char const *,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>,int>(
        result,
        __first,
        __last,
        *v16);
      return result;
    }
  }
  else
  {
    stlp_std::priv::__copy<char const *,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>,int>(
      result,
      __first,
      __last,
      (stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> >)__oi);
    return result;
  }
}


stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__cdecl stlp_std::priv::__copy_float_and_fill<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>(
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        wchar_t *__first,
        wchar_t *__last,
        __int64 __oi,
        char __flags,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __width,
        wchar_t __fill,
        wchar_t __xplus,
        wchar_t __xminus)
{
  __int64 v9; // rax
  unsigned int v11; // ecx
  char *v12; // ebx
  int v13; // eax
  unsigned int v14; // ebp
  wchar_t v15; // ax
  stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *v16; // eax
  stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *v17; // eax

  v9 = __last - __first;
  if ( *(_QWORD *)&__width > v9 )
  {
    v11 = (unsigned __int64)(*(_QWORD *)&__width - v9) >> 32;
    v12 = (char *)__width._M_buf - v9;
    v13 = __flags & 7;
    v14 = v11;
    if ( v13 == 1 )
    {
      stlp_std::priv::__copy<wchar_t const *,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,int>(
        &__width,
        __first,
        __last,
        (stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> >)__oi);
      __oi = (__int64)__width;
      stlp_std::priv::__fill_n<stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,__int64,wchar_t>(
        result,
        __width,
        __SPAIR64__(v14, (unsigned int)v12),
        &__fill);
      return result;
    }
    else if ( v13 == 4 && __first != __last && ((v15 = *__first, *__first == __xplus) || v15 == __xminus) )
    {
      stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>::operator=(
        (stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *)&__oi,
        v15);
      v16 = stlp_std::priv::__fill_n<stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,__int64,wchar_t>(
              &__width,
              (stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> >)__oi,
              __SPAIR64__(v14, (unsigned int)v12),
              &__fill);
      __oi = *(__int64 *)v16;
      stlp_std::copy<wchar_t const *,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>(
        result,
        __first + 1,
        __last,
        *v16);
      return result;
    }
    else
    {
      v17 = stlp_std::priv::__fill_n<stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,__int64,wchar_t>(
              &__width,
              (stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> >)__oi,
              __SPAIR64__(v11, (unsigned int)v12),
              &__fill);
      __oi = *(__int64 *)v17;
      stlp_std::priv::__copy<wchar_t const *,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,int>(
        result,
        __first,
        __last,
        *v17);
      return result;
    }
  }
  else
  {
    stlp_std::priv::__copy<wchar_t const *,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,int>(
      result,
      __first,
      __last,
      (stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> >)__oi);
    return result;
  }
}
