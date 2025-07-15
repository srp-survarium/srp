const vostok::render::shader_constant_host *__userpurge vostok::render::resource_manager::register_constant_binding@<eax>(
        const vostok::render::shader_constant_binding *binding@<eax>,
        vostok::render::resource_manager *this)
{
  vostok::render::shader_constant_binding *M_finish; // esi
  vostok::render::backend *v4; // ecx
  const vostok::render::shader_constant_host *result; // eax

  M_finish = this->m_const_bindings.m_bindings._M_impl._M_finish;
  if ( stlp_std::priv::__find<vostok::render::shader_constant_binding *,vostok::render::shader_constant_binding>(
         this->m_const_bindings.m_bindings._M_impl._M_start,
         M_finish,
         binding) == M_finish )
    stlp_std::priv::_Impl_vector<vostok::render::shader_constant_binding,vostok::render::std_allocator<vostok::render::shader_constant_binding>>::push_back(
      &this->m_const_bindings.m_bindings._M_impl,
      binding);
  result = vostok::render::backend::register_constant_host(
             v4,
             (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
             &binding->m_name,
             binding->m_type);
  if ( result )
  {
    result->m_source.m_pointer = binding->m_source.m_pointer;
    result->m_source.m_size = binding->m_source.m_size;
  }
  return result;
}
