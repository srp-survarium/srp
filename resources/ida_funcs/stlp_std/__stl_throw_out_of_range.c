void __cdecl __noreturn stlp_std::__stl_throw_out_of_range(char *__msg)
{
  stlp_std::allocator<char> __a; // [esp+7h] [ebp-135h] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > __str; // [esp+8h] [ebp-134h] BYREF
  stlp_std::__Named_exception pExceptionObject; // [esp+20h] [ebp-11Ch] BYREF
  int v4; // [esp+138h] [ebp-4h]

  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    &__str,
    __msg,
    &__a);
  v4 = 0;
  stlp_std::__Named_exception::__Named_exception(&pExceptionObject, &__str);
  pExceptionObject.__vftable = (stlp_std::__Named_exception_vtbl *)&stlp_std::out_of_range::`vftable';
  _CxxThrowException(&pExceptionObject, &_TI4_AVout_of_range_stlp_std__);
}
