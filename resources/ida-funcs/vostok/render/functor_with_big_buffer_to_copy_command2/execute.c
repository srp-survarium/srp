void __thiscall vostok::render::functor_with_big_buffer_to_copy_command2<vostok::math::float4x4>::execute(
        vostok::render::functor_with_big_buffer_to_copy_command2<vostok::math::float4x4> *this)
{
  const std::exception *v2; // eax
  stlp_std::out_of_range v3; // [esp+8h] [ebp-110h] BYREF

  if ( !this->m_on_execute.vtable )
  {
    boost::bad_function_call::bad_function_call((boost::bad_function_call *)this, (stlp_std::runtime_error *)&v3);
    boost::throw_exception(v2);
    stlp_std::__Named_exception::~__Named_exception(&v3);
  }
  (*(void (__cdecl **)(boost::detail::function::function_buffer *, const vostok::math::float4x4 *, const vostok::math::float4x4 *))(((int)this->m_on_execute.vtable & 0xFFFFFFFE) + 4))(
    &this->m_on_execute.functor,
    &this->m_data0,
    &this->m_data1);
}
