void __thiscall __noreturn stlp_std::ios_base::_M_throw_failure(stlp_std::ios_base *this)
{
  stlp_std::allocator<char> v1; // [esp+7h] [ebp-135h] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > __str; // [esp+8h] [ebp-134h] BYREF
  stlp_std::__Named_exception pExceptionObject; // [esp+20h] [ebp-11Ch] BYREF
  int v4; // [esp+138h] [ebp-4h]

  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    &__str,
    "ios failure",
    &v1);
  v4 = 0;
  stlp_std::__Named_exception::__Named_exception(&pExceptionObject, &__str);
  pExceptionObject.__vftable = (stlp_std::__Named_exception_vtbl *)&stlp_std::ios_base::failure::`vftable';
  _CxxThrowException((DWORD)&pExceptionObject, &_TI3_AVfailure_ios_base_stlp_std__);
}
