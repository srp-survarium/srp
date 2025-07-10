stlp_std::pair<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base> > *__usercall stlp_std::pair<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>>::operator=@<eax>(
        stlp_std::pair<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base> > *this@<esi>,
        const stlp_std::pair<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base> > *__that@<eax>)
{
  vostok::render::binary_shader_source *m_object; // edi
  vostok::render::binary_shader_source *v4; // eax
  vostok::render::binary_shader_source *v5; // edx

  this->first.configuration.configuration[0] = __that->first.configuration.configuration[0];
  this->first.configuration.configuration[1] = __that->first.configuration.configuration[1];
  vostok::fs_new::virtual_path_string::operator=(&this->first.shader_name, &__that->first.shader_name);
  this->first.type = __that->first.type;
  m_object = __that->second.m_object;
  v4 = 0;
  if ( m_object )
  {
    v4 = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  v5 = this->second.m_object;
  this->second.m_object = v4;
  if ( v5 && !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v5->vostok::resources::unmanaged_intrusive_base, v5);
  return this;
}
