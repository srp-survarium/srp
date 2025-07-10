vostok::render::vs_data *__userpurge vostok::render::vs_data::operator=@<eax>(
        const vostok::render::vs_data *__that@<eax>,
        vostok::render::vs_data *this)
{
  vostok::render::vs_data *v2; // ebx
  stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > > *v4; // ecx
  vostok::render::sampler_slot *m_begin; // eax
  vostok::render::texture_slot *v6; // eax
  const vostok::render::res_signature *m_object; // edi
  const vostok::render::res_signature *v8; // eax
  const vostok::render::res_signature *v9; // ecx

  v2 = this;
  this->instruction_count = __that->instruction_count;
  v2->hardware_shader = __that->hardware_shader;
  v2->constants.m_reference_count = __that->constants.m_reference_count;
  stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant>>::operator=(
    &v2->constants.m_table._M_impl,
    &v2->constants.m_table._M_impl);
  stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>>::operator=(
    v4,
    &__that->constants.m_const_buffers._M_impl);
  v2->constants.m_is_registered = __that->constants.m_is_registered;
  m_begin = __that->samplers.m_begin;
  this = (vostok::render::vs_data *)__that->samplers.m_end;
  vostok::buffer_vector<vostok::render::sampler_slot>::assign<vostok::render::sampler_slot const *>(
    &v2->samplers,
    m_begin,
    (const vostok::render::sampler_slot *const *)&this);
  v6 = __that->textures.m_begin;
  this = (vostok::render::vs_data *)__that->textures.m_end;
  vostok::buffer_vector<vostok::render::texture_slot>::assign<vostok::render::texture_slot const *>(
    &v2->textures,
    v6,
    (const vostok::render::texture_slot *const *)&this);
  m_object = __that->signature.m_object;
  v8 = 0;
  if ( m_object )
  {
    v8 = m_object;
    ++m_object->m_reference_count;
  }
  v9 = v2->signature.m_object;
  v2->signature.m_object = v8;
  if ( v9 )
  {
    if ( v9->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v9);
  }
  return v2;
}
