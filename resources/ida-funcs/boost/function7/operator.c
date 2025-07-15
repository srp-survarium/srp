int __userpurge boost::function7<bool,unsigned int,unsigned int,char const *,char const *,int,char const *,unsigned int>::operator()@<eax>(
        boost::function7<bool,unsigned int,unsigned int,char const *,char const *,int,char const *,unsigned int> *this@<ecx>,
        _DWORD *eax0@<eax>,
        unsigned int a0,
        unsigned int a1,
        const char *a2,
        const char *a3,
        int a4,
        const char *a5,
        unsigned int a6)
{
  const std::exception *v10; // eax
  stlp_std::out_of_range v12; // [esp+8h] [ebp-114h] BYREF

  if ( !*eax0 )
  {
    boost::bad_function_call::bad_function_call((boost::bad_function_call *)this, (stlp_std::runtime_error *)&v12);
    boost::throw_exception(v10);
    stlp_std::__Named_exception::~__Named_exception(&v12);
  }
  return (*(int (__cdecl **)(_DWORD *, unsigned int, unsigned int, const char *, const char *, int, const char *, unsigned int))((*eax0 & 0xFFFFFFFE) + 4))(
           eax0 + 2,
           a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6);
}
