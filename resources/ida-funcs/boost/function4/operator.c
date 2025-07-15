void __userpurge boost::function4<void,char const *,enum survarium::hit_type_enum,float &,float &>::operator()(
        boost::function4<void,char const *,enum survarium::hit_type_enum,float &,float &> *this@<ecx>,
        _DWORD *eax0@<eax>,
        const char *a0,
        survarium::hit_type_enum a1,
        float *a2,
        float *a3)
{
  const std::exception *v7; // eax
  stlp_std::out_of_range v8; // [esp+8h] [ebp-110h] BYREF

  if ( !*eax0 )
  {
    boost::bad_function_call::bad_function_call((boost::bad_function_call *)this, (stlp_std::runtime_error *)&v8);
    boost::throw_exception(v7);
    stlp_std::__Named_exception::~__Named_exception(&v8);
  }
  (*(void (__cdecl **)(_DWORD *, const char *, survarium::hit_type_enum, float *, float *))((*eax0 & 0xFFFFFFFE) + 4))(
    eax0 + 2,
    a0,
    a1,
    a2,
    a3);
}
