int __usercall boost::function0<void>::operator()@<eax>(boost::function0<bool> *this@<ecx>, _DWORD *a2@<eax>)
{
  const std::exception *v3; // eax
  stlp_std::out_of_range v5; // [esp+8h] [ebp-110h] BYREF

  if ( !*a2 )
  {
    boost::bad_function_call::bad_function_call((boost::bad_function_call *)this, (stlp_std::runtime_error *)&v5);
    boost::throw_exception(v3);
    stlp_std::__Named_exception::~__Named_exception(&v5);
  }
  return (*(int (__cdecl **)(_DWORD *))((*a2 & 0xFFFFFFFE) + 4))(a2 + 2);
}
