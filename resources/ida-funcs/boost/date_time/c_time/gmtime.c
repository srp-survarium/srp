tm *__usercall boost::date_time::c_time::gmtime@<eax>(int a1@<ebx>, __int64 *t)
{
  tm *v2; // esi
  stlp_std::allocator<char> v4; // [esp+7h] [ebp-129h] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > __str; // [esp+8h] [ebp-128h] BYREF
  stlp_std::__Named_exception v6; // [esp+20h] [ebp-110h] BYREF

  v2 = _gmtime64(a1, t);
  if ( !v2 )
  {
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
      &__str,
      "could not convert calendar time to UTC time",
      &v4);
    stlp_std::__Named_exception::__Named_exception(&v6, &__str);
    v6.__vftable = (stlp_std::__Named_exception_vtbl *)&stlp_std::runtime_error::`vftable';
    boost::throw_exception(&v6);
    stlp_std::__Named_exception::~__Named_exception((stlp_std::out_of_range *)&v6);
    stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&__str);
  }
  return v2;
}
