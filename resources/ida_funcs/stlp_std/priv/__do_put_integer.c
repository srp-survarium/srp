stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *__cdecl stlp_std::priv::__do_put_integer<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>,long>(
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > __s,
        stlp_std::ios_base *__f,
        char __fill,
        int __x)
{
  int M_fmtflags; // ebx
  char *v6; // eax
  char __iend[2]; // [esp+1Ah] [ebp-6h] BYREF

  M_fmtflags = __f->_M_fmtflags;
  v6 = stlp_std::priv::__write_integer_backward<long>(__iend, M_fmtflags, __x);
  stlp_std::priv::__put_integer<stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>>(
    result,
    v6,
    __iend,
    __s,
    __f,
    M_fmtflags,
    __fill);
  return result;
}


stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *__cdecl stlp_std::priv::__do_put_integer<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>,unsigned long>(
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > __s,
        stlp_std::ios_base *__f,
        char __fill,
        unsigned int __x)
{
  int M_fmtflags; // ebx
  char *v6; // eax
  char __iend[2]; // [esp+1Ah] [ebp-6h] BYREF

  M_fmtflags = __f->_M_fmtflags;
  v6 = stlp_std::priv::__write_integer_backward<unsigned long>(__iend, M_fmtflags, __x);
  stlp_std::priv::__put_integer<stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>>(
    result,
    v6,
    __iend,
    __s,
    __f,
    M_fmtflags,
    __fill);
  return result;
}


stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *__cdecl stlp_std::priv::__do_put_integer<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>,__int64>(
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > __s,
        stlp_std::ios_base *__f,
        char __fill,
        __int64 __x)
{
  int M_fmtflags; // ebx
  char *v6; // eax
  char __iend[2]; // [esp+26h] [ebp-6h] BYREF

  M_fmtflags = __f->_M_fmtflags;
  v6 = stlp_std::priv::__write_integer_backward<__int64>(__iend, M_fmtflags, __x);
  stlp_std::priv::__put_integer<stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>>(
    result,
    v6,
    __iend,
    __s,
    __f,
    M_fmtflags,
    __fill);
  return result;
}


stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *__cdecl stlp_std::priv::__do_put_integer<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>,unsigned __int64>(
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > __s,
        stlp_std::ios_base *__f,
        char __fill,
        unsigned __int64 __x)
{
  int M_fmtflags; // ebx
  char *v6; // eax
  char __iend[2]; // [esp+26h] [ebp-6h] BYREF

  M_fmtflags = __f->_M_fmtflags;
  v6 = stlp_std::priv::__write_integer_backward<unsigned __int64>(__iend, M_fmtflags, __x);
  stlp_std::priv::__put_integer<stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>>(
    result,
    v6,
    __iend,
    __s,
    __f,
    M_fmtflags,
    __fill);
  return result;
}


stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__cdecl stlp_std::priv::__do_put_integer<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,long>(
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __s,
        stlp_std::ios_base *__f,
        wchar_t __fill,
        int __x)
{
  int M_fmtflags; // ebx
  char *v6; // eax
  char __iend[2]; // [esp+1Ah] [ebp-6h] BYREF

  M_fmtflags = __f->_M_fmtflags;
  v6 = stlp_std::priv::__write_integer_backward<long>(__iend, M_fmtflags, __x);
  stlp_std::priv::__put_integer<stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>(
    result,
    v6,
    __iend,
    __s,
    __f,
    M_fmtflags,
    __fill);
  return result;
}


stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__cdecl stlp_std::priv::__do_put_integer<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,unsigned long>(
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __s,
        stlp_std::ios_base *__f,
        wchar_t __fill,
        unsigned int __x)
{
  int M_fmtflags; // ebx
  char *v6; // eax
  char __iend[2]; // [esp+1Ah] [ebp-6h] BYREF

  M_fmtflags = __f->_M_fmtflags;
  v6 = stlp_std::priv::__write_integer_backward<unsigned long>(__iend, M_fmtflags, __x);
  stlp_std::priv::__put_integer<stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>(
    result,
    v6,
    __iend,
    __s,
    __f,
    M_fmtflags,
    __fill);
  return result;
}


stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__cdecl stlp_std::priv::__do_put_integer<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,__int64>(
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __s,
        stlp_std::ios_base *__f,
        wchar_t __fill,
        __int64 __x)
{
  int M_fmtflags; // ebx
  char *v6; // eax
  char __iend[2]; // [esp+26h] [ebp-6h] BYREF

  M_fmtflags = __f->_M_fmtflags;
  v6 = stlp_std::priv::__write_integer_backward<__int64>(__iend, M_fmtflags, __x);
  stlp_std::priv::__put_integer<stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>(
    result,
    v6,
    __iend,
    __s,
    __f,
    M_fmtflags,
    __fill);
  return result;
}


stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__cdecl stlp_std::priv::__do_put_integer<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,unsigned __int64>(
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __s,
        stlp_std::ios_base *__f,
        wchar_t __fill,
        unsigned __int64 __x)
{
  int M_fmtflags; // ebx
  char *v6; // eax
  char __iend[2]; // [esp+26h] [ebp-6h] BYREF

  M_fmtflags = __f->_M_fmtflags;
  v6 = stlp_std::priv::__write_integer_backward<unsigned __int64>(__iend, M_fmtflags, __x);
  stlp_std::priv::__put_integer<stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>(
    result,
    v6,
    __iend,
    __s,
    __f,
    M_fmtflags,
    __fill);
  return result;
}
