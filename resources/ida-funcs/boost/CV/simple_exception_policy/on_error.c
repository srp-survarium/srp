void __cdecl boost::CV::simple_exception_policy<unsigned short,1,31,boost::gregorian::bad_day_of_month>::on_error()
{
  const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *v0; // eax
  stlp_std::out_of_range v1; // [esp+4h] [ebp-12Ch] BYREF
  stlp_std::priv::_String_base<char,stlp_std::allocator<char> > v2; // [esp+114h] [ebp-1Ch] BYREF
  stlp_std::allocator<char> v3; // [esp+12Fh] [ebp-1h] BYREF

  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)&v2,
    "Day of month value is out of range 1..31",
    &v3);
  stlp_std::out_of_range::out_of_range(&v1, v0);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&v2);
  v1.__vftable = (stlp_std::out_of_range_vtbl *)&boost::gregorian::bad_day_of_month::`vftable';
  boost::throw_exception(&v1);
  stlp_std::__Named_exception::~__Named_exception(&v1);
}


void __cdecl boost::CV::simple_exception_policy<unsigned short,1,12,boost::gregorian::bad_month>::on_error()
{
  const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *v0; // eax
  stlp_std::out_of_range v1; // [esp+4h] [ebp-12Ch] BYREF
  stlp_std::priv::_String_base<char,stlp_std::allocator<char> > v2; // [esp+114h] [ebp-1Ch] BYREF
  stlp_std::allocator<char> v3; // [esp+12Fh] [ebp-1h] BYREF

  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)&v2,
    "Month number is out of range 1..12",
    &v3);
  stlp_std::out_of_range::out_of_range(&v1, v0);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&v2);
  v1.__vftable = (stlp_std::out_of_range_vtbl *)&boost::gregorian::bad_month::`vftable';
  boost::throw_exception(&v1);
  stlp_std::__Named_exception::~__Named_exception(&v1);
}


void __cdecl boost::CV::simple_exception_policy<unsigned short,1400,10000,boost::gregorian::bad_year>::on_error()
{
  const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *v0; // eax
  stlp_std::out_of_range v1; // [esp+4h] [ebp-12Ch] BYREF
  stlp_std::priv::_String_base<char,stlp_std::allocator<char> > v2; // [esp+114h] [ebp-1Ch] BYREF
  stlp_std::allocator<char> v3; // [esp+12Fh] [ebp-1h] BYREF

  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)&v2,
    "Year is out of valid range: 1400..10000",
    &v3);
  stlp_std::out_of_range::out_of_range(&v1, v0);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&v2);
  v1.__vftable = (stlp_std::out_of_range_vtbl *)&boost::gregorian::bad_year::`vftable';
  boost::throw_exception(&v1);
  stlp_std::__Named_exception::~__Named_exception(&v1);
}
