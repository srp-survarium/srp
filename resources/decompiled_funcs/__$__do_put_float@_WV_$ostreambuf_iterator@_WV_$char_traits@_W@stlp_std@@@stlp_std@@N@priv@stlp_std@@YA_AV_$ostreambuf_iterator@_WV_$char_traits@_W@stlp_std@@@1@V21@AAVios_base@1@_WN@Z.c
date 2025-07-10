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
