void __userpurge boost::function3<void,vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum>::operator()(
        boost::function3<void,vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum> *this@<ecx>,
        _DWORD *eax0@<eax>,
        vostok::resources::query_result *a0,
        const vostok::resources::memory_usage_type *a1,
        vostok::resources::class_id_enum a2)
{
  const std::exception *v6; // eax
  boost::bad_function_call v7; // [esp+8h] [ebp-110h] BYREF

  if ( !*eax0 )
  {
    boost::bad_function_call::bad_function_call(&v7);
    boost::throw_exception(v6);
    stlp_std::__Named_exception::~__Named_exception((stlp_std::out_of_range *)&v7);
  }
  (*(void (__cdecl **)(_DWORD *, vostok::resources::query_result *, const vostok::resources::memory_usage_type *, vostok::resources::class_id_enum))((*eax0 & 0xFFFFFFFE) + 4))(
    eax0 + 2,
    a0,
    a1,
    a2);
}
