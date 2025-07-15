vostok::render::effect_compiler *__userpurge vostok::render::effect_compiler::bind_constant@<eax>(
        const vostok::render::shader_constant_binding *binding@<eax>,
        vostok::render::effect_compiler *this)
{
  vostok::render::shader_constant_binding *M_finish; // esi

  if ( !this->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      s_no_effect_result.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_no_effect_result.m_type == type_recursive )
    {
      M_finish = this->m_bindings.m_bindings._M_impl._M_finish;
      if ( stlp_std::priv::__find<vostok::render::shader_constant_binding *,vostok::render::shader_constant_binding>(
             this->m_bindings.m_bindings._M_impl._M_start,
             M_finish,
             binding) == M_finish )
        stlp_std::priv::_Impl_vector<vostok::render::shader_constant_binding,vostok::render::std_allocator<vostok::render::shader_constant_binding>>::push_back(
          &this->m_bindings.m_bindings._M_impl,
          binding);
    }
  }
  return this;
}
