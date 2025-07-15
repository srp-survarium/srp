void __thiscall vostok::network::string_response::execute(vostok::network::string_response *this)
{
  const vostok::resources::memory_usage_type *m_string1; // eax

  m_string1 = (const vostok::resources::memory_usage_type *)this->m_string1;
  if ( m_string1 )
  {
    if ( this->m_string2 )
      boost::function2<void,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>::operator()(
        (boost::function3<void,vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum> *)this,
        &this->m_functor2.vtable,
        (vostok::resources::query_result *)this->m_string0,
        m_string1,
        (vostok::resources::class_id_enum)this->m_string2);
    else
      boost::function1<void,boost::system::error_code>::operator()(
        (boost::function2<void,vostok::math::float4x4 *,unsigned int> *)this,
        &this->m_functor1.vtable,
        (vostok::math::float4x4 *)this->m_string0,
        (unsigned int)this->m_string1);
  }
  else
  {
    boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
      (boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *)this,
      &this->m_functor0.vtable,
      (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)this->m_string0);
  }
}
