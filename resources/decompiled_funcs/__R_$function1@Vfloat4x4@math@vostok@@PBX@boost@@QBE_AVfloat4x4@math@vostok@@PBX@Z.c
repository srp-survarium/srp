vostok::math::float4x4 *__userpurge boost::function1<vostok::math::float4x4,void const *>::operator()@<eax>(
        boost::function1<vostok::math::float4x4,void const *> *this@<ecx>,
        _DWORD *a2@<eax>,
        vostok::math::float4x4 *result,
        const void *a0)
{
  const std::exception *v5; // eax
  _BYTE v7[64]; // [esp+10h] [ebp-154h] BYREF
  boost::bad_function_call v8; // [esp+50h] [ebp-114h] BYREF

  if ( !*a2 )
  {
    boost::bad_function_call::bad_function_call(&v8);
    boost::throw_exception(v5);
    stlp_std::__Named_exception::~__Named_exception((stlp_std::out_of_range *)&v8);
  }
  qmemcpy(
    (void *)result,
    (const void *)(*(int (__cdecl **)(_BYTE *, _DWORD *, const void *))((*a2 & 0xFFFFFFFE) + 4))(v7, a2 + 2, a0),
    sizeof(vostok::math::float4x4));
  return result;
}
