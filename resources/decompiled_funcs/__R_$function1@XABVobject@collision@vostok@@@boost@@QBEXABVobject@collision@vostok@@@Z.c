void __userpurge boost::function1<void,vostok::collision::object const &>::operator()(
        boost::function1<void,vostok::collision::object const &> *this@<ecx>,
        _DWORD *a2@<eax>,
        const vostok::collision::object *a0)
{
  const std::exception *v4; // eax
  boost::bad_function_call v5; // [esp+8h] [ebp-110h] BYREF

  if ( !*a2 )
  {
    boost::bad_function_call::bad_function_call(&v5);
    boost::throw_exception(v4);
    stlp_std::__Named_exception::~__Named_exception((stlp_std::out_of_range *)&v5);
  }
  (*(void (__cdecl **)(_DWORD *, const vostok::collision::object *))((*a2 & 0xFFFFFFFE) + 4))(a2 + 2, a0);
}
