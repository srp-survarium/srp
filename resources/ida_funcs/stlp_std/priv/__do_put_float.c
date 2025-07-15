stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *__cdecl stlp_std::priv::__do_put_float<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>,double>(
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > __s,
        stlp_std::ios_base *__f,
        char __fill,
        long double __x)
{
  int M_precision_high; // edx
  char *v6; // ebx
  stlp_std::locale *v7; // eax
  stlp_std::moneypunct<wchar_t,0> *v8; // edi
  wchar_t (__thiscall *do_thousands_sep)(stlp_std::moneypunct<wchar_t,0> *); // edx
  char v10; // al
  stlp_std::moneypunct<wchar_t,0>_vtbl *v11; // edx
  char v12; // al
  int M_fmtflags; // [esp-8h] [ebp-27Ch]
  int M_precision; // [esp-4h] [ebp-278h]
  char v16; // [esp-4h] [ebp-278h]
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *x_4; // [esp+4h] [ebp-270h]
  stlp_std::locale v18; // [esp+1Ch] [ebp-258h] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__grouping; // [esp+20h] [ebp-254h]
  char __sep[4]; // [esp+24h] [ebp-250h]
  int v21; // [esp+28h] [ebp-24Ch]
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > v22; // [esp+2Ch] [ebp-248h] BYREF
  stlp_std::priv::__iostring_allocator<char> __a; // [esp+47h] [ebp-22Dh] BYREF
  stlp_std::priv::__basic_iostring<char> __buf; // [esp+148h] [ebp-12Ch] BYREF
  int v25; // [esp+270h] [ebp-4h]

  stlp_std::priv::_String_base<char,stlp_std::priv::__iostring_allocator<char>>::_String_base<char,stlp_std::priv::__iostring_allocator<char>>(
    &__buf,
    &__a,
    0x101u);
  *__buf._M_finish = 0;
  M_precision_high = HIDWORD(__f->_M_precision);
  M_precision = __f->_M_precision;
  M_fmtflags = __f->_M_fmtflags;
  v25 = 0;
  v21 = M_precision_high;
  v6 = (char *)stlp_std::priv::__write_float(&__buf, M_fmtflags, M_precision, __x);
  v7 = stlp_std::ios_base::getloc(__f, &v18);
  LOBYTE(v25) = 1;
  v8 = (stlp_std::moneypunct<wchar_t,0> *)stlp_std::locale::_M_use_facet(v7, &stlp_std::numpunct<char>::id);
  LOBYTE(v25) = 0;
  stlp_std::locale::~locale(&v18);
  __grouping = stlp_std::moneypunct<wchar_t,1>::grouping(v8, &v22);
  do_thousands_sep = v8->do_thousands_sep;
  LOBYTE(v25) = 2;
  v10 = do_thousands_sep(v8);
  v11 = v8->__vftable;
  __sep[0] = v10;
  x_4 = __grouping;
  v16 = v10;
  v12 = v11->do_decimal_point(v8);
  stlp_std::priv::__put_float<stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>>(
    result,
    &__buf,
    __s,
    __f,
    __fill,
    v12,
    v16,
    v6,
    x_4);
  LOBYTE(v25) = 0;
  if ( (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)v22._M_start_of_storage._M_data != &v22
    && v22._M_start_of_storage._M_data )
  {
    if ( (unsigned int)(v22._M_buffers._M_end_of_storage - v22._M_start_of_storage._M_data) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)v22._M_start_of_storage._M_data,
        v22._M_buffers._M_end_of_storage - v22._M_start_of_storage._M_data);
    else
      operator delete(v22._M_start_of_storage._M_data);
  }
  v25 = -1;
  if ( (stlp_std::priv::__basic_iostring<char> *)__buf._M_start_of_storage._M_data != &__buf
    && __buf._M_start_of_storage._M_data
    && (stlp_std::priv::_STLP_alloc_proxy<char *,char,stlp_std::priv::__iostring_allocator<char> > *)__buf._M_start_of_storage._M_data != &__buf._M_start_of_storage )
  {
    if ( (unsigned int)(__buf._M_buffers._M_end_of_storage - __buf._M_start_of_storage._M_data) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)__buf._M_start_of_storage._M_data,
        __buf._M_buffers._M_end_of_storage - __buf._M_start_of_storage._M_data);
    else
      operator delete(__buf._M_start_of_storage._M_data);
  }
  return result;
}


stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *__cdecl stlp_std::priv::__do_put_float<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>,long double>(
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > __s,
        stlp_std::ios_base *__f,
        char __fill,
        long double __x)
{
  int M_precision_high; // edx
  char *v6; // ebx
  stlp_std::locale *v7; // eax
  stlp_std::moneypunct<wchar_t,0> *v8; // edi
  wchar_t (__thiscall *do_thousands_sep)(stlp_std::moneypunct<wchar_t,0> *); // edx
  char v10; // al
  stlp_std::moneypunct<wchar_t,0>_vtbl *v11; // edx
  char v12; // al
  int M_fmtflags; // [esp-8h] [ebp-27Ch]
  int M_precision; // [esp-4h] [ebp-278h]
  char v16; // [esp-4h] [ebp-278h]
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *x_4; // [esp+4h] [ebp-270h]
  stlp_std::locale v18; // [esp+1Ch] [ebp-258h] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__grouping; // [esp+20h] [ebp-254h]
  char __sep[4]; // [esp+24h] [ebp-250h]
  int v21; // [esp+28h] [ebp-24Ch]
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > v22; // [esp+2Ch] [ebp-248h] BYREF
  stlp_std::priv::__iostring_allocator<char> __a; // [esp+47h] [ebp-22Dh] BYREF
  stlp_std::priv::__basic_iostring<char> __buf; // [esp+148h] [ebp-12Ch] BYREF
  int v25; // [esp+270h] [ebp-4h]

  stlp_std::priv::_String_base<char,stlp_std::priv::__iostring_allocator<char>>::_String_base<char,stlp_std::priv::__iostring_allocator<char>>(
    &__buf,
    &__a,
    0x101u);
  *__buf._M_finish = 0;
  M_precision_high = HIDWORD(__f->_M_precision);
  M_precision = __f->_M_precision;
  M_fmtflags = __f->_M_fmtflags;
  v25 = 0;
  v21 = M_precision_high;
  v6 = (char *)stlp_std::priv::__write_float(&__buf, M_fmtflags, M_precision, __x);
  v7 = stlp_std::ios_base::getloc(__f, &v18);
  LOBYTE(v25) = 1;
  v8 = (stlp_std::moneypunct<wchar_t,0> *)stlp_std::locale::_M_use_facet(v7, &stlp_std::numpunct<char>::id);
  LOBYTE(v25) = 0;
  stlp_std::locale::~locale(&v18);
  __grouping = stlp_std::moneypunct<wchar_t,1>::grouping(v8, &v22);
  do_thousands_sep = v8->do_thousands_sep;
  LOBYTE(v25) = 2;
  v10 = do_thousands_sep(v8);
  v11 = v8->__vftable;
  __sep[0] = v10;
  x_4 = __grouping;
  v16 = v10;
  v12 = v11->do_decimal_point(v8);
  stlp_std::priv::__put_float<stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>>(
    result,
    &__buf,
    __s,
    __f,
    __fill,
    v12,
    v16,
    v6,
    x_4);
  LOBYTE(v25) = 0;
  if ( (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)v22._M_start_of_storage._M_data != &v22
    && v22._M_start_of_storage._M_data )
  {
    if ( (unsigned int)(v22._M_buffers._M_end_of_storage - v22._M_start_of_storage._M_data) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)v22._M_start_of_storage._M_data,
        v22._M_buffers._M_end_of_storage - v22._M_start_of_storage._M_data);
    else
      operator delete(v22._M_start_of_storage._M_data);
  }
  v25 = -1;
  if ( (stlp_std::priv::__basic_iostring<char> *)__buf._M_start_of_storage._M_data != &__buf
    && __buf._M_start_of_storage._M_data
    && (stlp_std::priv::_STLP_alloc_proxy<char *,char,stlp_std::priv::__iostring_allocator<char> > *)__buf._M_start_of_storage._M_data != &__buf._M_start_of_storage )
  {
    if ( (unsigned int)(__buf._M_buffers._M_end_of_storage - __buf._M_start_of_storage._M_data) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)__buf._M_start_of_storage._M_data,
        __buf._M_buffers._M_end_of_storage - __buf._M_start_of_storage._M_data);
    else
      operator delete(__buf._M_start_of_storage._M_data);
  }
  return result;
}


stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__cdecl stlp_std::priv::__do_put_float<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,double>(
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __s,
        stlp_std::ios_base *__f,
        wchar_t __fill,
        long double __x)
{
  int M_precision_high; // edx
  unsigned int v6; // ebx
  stlp_std::locale *v7; // eax
  stlp_std::moneypunct<wchar_t,0> *v8; // edi
  wchar_t (__thiscall *do_thousands_sep)(stlp_std::moneypunct<wchar_t,0> *); // edx
  wchar_t v10; // ax
  wchar_t v11; // ax
  int M_fmtflags; // [esp-8h] [ebp-278h]
  int M_precision; // [esp-4h] [ebp-274h]
  wchar_t v15; // [esp-4h] [ebp-274h]
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *x_4; // [esp+4h] [ebp-26Ch]
  stlp_std::locale v17; // [esp+1Ch] [ebp-254h] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__grouping; // [esp+20h] [ebp-250h]
  int v19; // [esp+24h] [ebp-24Ch]
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > v20; // [esp+28h] [ebp-248h] BYREF
  stlp_std::priv::__iostring_allocator<char> __a; // [esp+43h] [ebp-22Dh] BYREF
  stlp_std::priv::__basic_iostring<char> __buf; // [esp+144h] [ebp-12Ch] BYREF
  int v23; // [esp+26Ch] [ebp-4h]

  stlp_std::priv::_String_base<char,stlp_std::priv::__iostring_allocator<char>>::_String_base<char,stlp_std::priv::__iostring_allocator<char>>(
    &__buf,
    &__a,
    0x101u);
  *__buf._M_finish = 0;
  M_precision_high = HIDWORD(__f->_M_precision);
  M_precision = __f->_M_precision;
  M_fmtflags = __f->_M_fmtflags;
  v23 = 0;
  v19 = M_precision_high;
  v6 = stlp_std::priv::__write_float(&__buf, M_fmtflags, M_precision, __x);
  v7 = stlp_std::ios_base::getloc(__f, &v17);
  LOBYTE(v23) = 1;
  v8 = (stlp_std::moneypunct<wchar_t,0> *)stlp_std::locale::_M_use_facet(v7, &stlp_std::numpunct<wchar_t>::id);
  LOBYTE(v23) = 0;
  stlp_std::locale::~locale(&v17);
  __grouping = stlp_std::moneypunct<wchar_t,1>::grouping(v8, &v20);
  do_thousands_sep = v8->do_thousands_sep;
  LOBYTE(v23) = 2;
  v10 = do_thousands_sep(v8);
  x_4 = __grouping;
  v15 = v10;
  v11 = v8->do_decimal_point(v8);
  stlp_std::priv::__put_float<stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>(
    result,
    &__buf,
    __s,
    __f,
    __fill,
    v11,
    v15,
    v6,
    x_4);
  LOBYTE(v23) = 0;
  if ( (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)v20._M_start_of_storage._M_data != &v20
    && v20._M_start_of_storage._M_data )
  {
    if ( (unsigned int)(v20._M_buffers._M_end_of_storage - v20._M_start_of_storage._M_data) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)v20._M_start_of_storage._M_data,
        v20._M_buffers._M_end_of_storage - v20._M_start_of_storage._M_data);
    else
      operator delete(v20._M_start_of_storage._M_data);
  }
  v23 = -1;
  if ( (stlp_std::priv::__basic_iostring<char> *)__buf._M_start_of_storage._M_data != &__buf
    && __buf._M_start_of_storage._M_data
    && (stlp_std::priv::_STLP_alloc_proxy<char *,char,stlp_std::priv::__iostring_allocator<char> > *)__buf._M_start_of_storage._M_data != &__buf._M_start_of_storage )
  {
    if ( (unsigned int)(__buf._M_buffers._M_end_of_storage - __buf._M_start_of_storage._M_data) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)__buf._M_start_of_storage._M_data,
        __buf._M_buffers._M_end_of_storage - __buf._M_start_of_storage._M_data);
    else
      operator delete(__buf._M_start_of_storage._M_data);
  }
  return result;
}


stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__cdecl stlp_std::priv::__do_put_float<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,long double>(
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __s,
        stlp_std::ios_base *__f,
        wchar_t __fill,
        long double __x)
{
  int M_precision_high; // edx
  unsigned int v6; // ebx
  stlp_std::locale *v7; // eax
  stlp_std::moneypunct<wchar_t,0> *v8; // edi
  wchar_t (__thiscall *do_thousands_sep)(stlp_std::moneypunct<wchar_t,0> *); // edx
  wchar_t v10; // ax
  wchar_t v11; // ax
  int M_fmtflags; // [esp-8h] [ebp-278h]
  int M_precision; // [esp-4h] [ebp-274h]
  wchar_t v15; // [esp-4h] [ebp-274h]
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *x_4; // [esp+4h] [ebp-26Ch]
  stlp_std::locale v17; // [esp+1Ch] [ebp-254h] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__grouping; // [esp+20h] [ebp-250h]
  int v19; // [esp+24h] [ebp-24Ch]
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > v20; // [esp+28h] [ebp-248h] BYREF
  stlp_std::priv::__iostring_allocator<char> __a; // [esp+43h] [ebp-22Dh] BYREF
  stlp_std::priv::__basic_iostring<char> __buf; // [esp+144h] [ebp-12Ch] BYREF
  int v23; // [esp+26Ch] [ebp-4h]

  stlp_std::priv::_String_base<char,stlp_std::priv::__iostring_allocator<char>>::_String_base<char,stlp_std::priv::__iostring_allocator<char>>(
    &__buf,
    &__a,
    0x101u);
  *__buf._M_finish = 0;
  M_precision_high = HIDWORD(__f->_M_precision);
  M_precision = __f->_M_precision;
  M_fmtflags = __f->_M_fmtflags;
  v23 = 0;
  v19 = M_precision_high;
  v6 = stlp_std::priv::__write_float(&__buf, M_fmtflags, M_precision, __x);
  v7 = stlp_std::ios_base::getloc(__f, &v17);
  LOBYTE(v23) = 1;
  v8 = (stlp_std::moneypunct<wchar_t,0> *)stlp_std::locale::_M_use_facet(v7, &stlp_std::numpunct<wchar_t>::id);
  LOBYTE(v23) = 0;
  stlp_std::locale::~locale(&v17);
  __grouping = stlp_std::moneypunct<wchar_t,1>::grouping(v8, &v20);
  do_thousands_sep = v8->do_thousands_sep;
  LOBYTE(v23) = 2;
  v10 = do_thousands_sep(v8);
  x_4 = __grouping;
  v15 = v10;
  v11 = v8->do_decimal_point(v8);
  stlp_std::priv::__put_float<stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>(
    result,
    &__buf,
    __s,
    __f,
    __fill,
    v11,
    v15,
    v6,
    x_4);
  LOBYTE(v23) = 0;
  if ( (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)v20._M_start_of_storage._M_data != &v20
    && v20._M_start_of_storage._M_data )
  {
    if ( (unsigned int)(v20._M_buffers._M_end_of_storage - v20._M_start_of_storage._M_data) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)v20._M_start_of_storage._M_data,
        v20._M_buffers._M_end_of_storage - v20._M_start_of_storage._M_data);
    else
      operator delete(v20._M_start_of_storage._M_data);
  }
  v23 = -1;
  if ( (stlp_std::priv::__basic_iostring<char> *)__buf._M_start_of_storage._M_data != &__buf
    && __buf._M_start_of_storage._M_data
    && (stlp_std::priv::_STLP_alloc_proxy<char *,char,stlp_std::priv::__iostring_allocator<char> > *)__buf._M_start_of_storage._M_data != &__buf._M_start_of_storage )
  {
    if ( (unsigned int)(__buf._M_buffers._M_end_of_storage - __buf._M_start_of_storage._M_data) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)__buf._M_start_of_storage._M_data,
        __buf._M_buffers._M_end_of_storage - __buf._M_start_of_storage._M_data);
    else
      operator delete(__buf._M_start_of_storage._M_data);
  }
  return result;
}
