void __noreturn stlp_std::_Locale_impl::_M_throw_bad_cast()
{
  std::bad_cast pExceptionObject; // [esp+0h] [ebp-Ch] BYREF

  std::bad_cast::bad_cast(&pExceptionObject, "bad cast");
  _CxxThrowException((DWORD)&pExceptionObject, &_TI2_AVbad_cast_std__);
}
