void __userpurge boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::operator()(
        boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *this@<ecx>,
        _DWORD *eax0@<eax>,
        void *a0,
        const char *a1,
        unsigned int a2,
        const char *a3,
        const char *a4,
        vostok::logging::verbosity a5,
        const char *a6,
        unsigned int a7,
        vostok::logging::callback_flag a8)
{
  const std::exception *v12; // eax
  stlp_std::out_of_range v13; // [esp+8h] [ebp-110h] BYREF

  if ( !*eax0 )
  {
    boost::bad_function_call::bad_function_call((boost::bad_function_call *)this, (stlp_std::runtime_error *)&v13);
    boost::throw_exception(v12);
    stlp_std::__Named_exception::~__Named_exception(&v13);
  }
  (*(void (__cdecl **)(_DWORD *, void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag))((*eax0 & 0xFFFFFFFE) + 4))(
    eax0 + 2,
    a0,
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8);
}
