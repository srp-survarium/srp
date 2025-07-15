void __cdecl __noreturn stlp_std::_Locale_impl::_M_throw_bad_cast()
{
  std::bad_cast pExceptionObject; // [esp+0h] [ebp-Ch] BYREF

  std::bad_cast::bad_cast(&pExceptionObject, &stru_984D24.m_working_macro_list.m_buffer[1].m_store[404]);
  _CxxThrowException(&pExceptionObject, &_TI2_AVbad_cast_std__);
}
