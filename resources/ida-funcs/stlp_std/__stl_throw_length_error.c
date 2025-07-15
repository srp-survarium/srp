void __cdecl __noreturn stlp_std::__stl_throw_length_error(char *__msg)
{
  stlp_std::allocator<char> v1; // [esp+7h] [ebp-135h] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > __str; // [esp+8h] [ebp-134h] BYREF
  stlp_std::__Named_exception v3; // [esp+20h] [ebp-11Ch] BYREF
  int v4; // [esp+138h] [ebp-4h]

  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    &__str,
    __msg,
    &v1);
  v4 = 0;
  stlp_std::__Named_exception::__Named_exception(&v3, &__str);
  v3.__vftable = (stlp_std::__Named_exception_vtbl *)&stlp_std::length_error::`vftable';
  _CxxThrowException((DWORD)&v3, (const _s__ThrowInfo *)&_TI4_AVlength_error_stlp_std__);
}
