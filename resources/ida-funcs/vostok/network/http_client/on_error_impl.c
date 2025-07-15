void __thiscall vostok::network::http_client::on_error_impl(
        vostok::network::http_client *this,
        boost::system::error_code error_code)
{
  boost::function<void __cdecl(boost::system::error_code)> *p_m_on_error; // eax
  int v3; // ecx

  p_m_on_error = &this->m_on_error;
  this->m_busy = 0;
  v3 = -(this->m_on_error.vtable != 0);
  if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v3) != 0 )
    boost::function1<void,boost::system::error_code>::operator()(
      (boost::function2<void,vostok::math::float4x4 *,unsigned int> *)v3,
      p_m_on_error,
      (vostok::math::float4x4 *)error_code.m_val,
      (unsigned int)error_code.m_cat);
}
