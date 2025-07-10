vostok::render::gs_data *__userpurge vostok::render::gs_data::operator=@<eax>(
        const vostok::render::gs_data *__that@<edi>,
        vostok::render::gs_data *this)
{
  vostok::render::gs_data *v2; // ebx
  stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > > *v3; // ecx
  vostok::render::sampler_slot *m_begin; // eax
  vostok::render::texture_slot *v5; // eax

  v2 = this;
  this->instruction_count = __that->instruction_count;
  v2->hardware_shader = __that->hardware_shader;
  v2->constants.m_reference_count = __that->constants.m_reference_count;
  stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant>>::operator=(
    &v2->constants.m_table._M_impl,
    &v2->constants.m_table._M_impl);
  stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>>::operator=(
    v3,
    &__that->constants.m_const_buffers._M_impl);
  v2->constants.m_is_registered = __that->constants.m_is_registered;
  m_begin = __that->samplers.m_begin;
  this = (vostok::render::gs_data *)__that->samplers.m_end;
  vostok::buffer_vector<vostok::render::sampler_slot>::assign<vostok::render::sampler_slot const *>(
    &v2->samplers,
    m_begin,
    (const vostok::render::sampler_slot *const *)&this);
  v5 = __that->textures.m_begin;
  this = (vostok::render::gs_data *)__that->textures.m_end;
  vostok::buffer_vector<vostok::render::texture_slot>::assign<vostok::render::texture_slot const *>(
    &v2->textures,
    v5,
    (const vostok::render::texture_slot *const *)&this);
  return v2;
}
