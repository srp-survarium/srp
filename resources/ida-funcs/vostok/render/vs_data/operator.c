vostok::render::vs_data *__usercall vostok::render::vs_data::operator=@<eax>(
        vostok::render::vs_data *this@<edi>,
        const vostok::render::vs_data *__that@<eax>,
        vostok::render::shader_constant_table *a3@<ecx>)
{
  const vostok::render::res_signature *m_object; // esi
  const vostok::render::res_signature *v5; // eax
  vostok::intrusive_ptr<vostok::render::res_signature const ,vostok::render::res_signature const ,vostok::threading::single_threading_policy> *p_signature; // ecx
  const vostok::render::res_signature *v7; // edx
  vostok::render::res_pass *v8; // eax

  this->instruction_count = __that->instruction_count;
  this->hardware_shader = __that->hardware_shader;
  vostok::render::shader_constant_table::operator=(
    a3,
    &this->constants,
    (const vostok::render::shader_constant *)&__that->constants);
  vostok::fixed_vector<vostok::render::sampler_slot,16>::operator=(&__that->samplers, &this->samplers);
  vostok::fixed_vector<vostok::render::texture_slot,128>::operator=(&__that->textures, &this->textures);
  vostok::fixed_vector<vostok::render::buffer_slot,128>::operator=(&__that->buffers, &this->buffers);
  m_object = __that->signature.m_object;
  v5 = 0;
  p_signature = &this->signature;
  if ( m_object )
  {
    v5 = m_object;
    ++m_object->m_reference_count;
  }
  v7 = v5;
  v8 = (vostok::render::res_pass *)p_signature->m_object;
  p_signature->m_object = v7;
  if ( v8 )
  {
    if ( v8->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(vostok::quasi_singleton<vostok::render::resource_manager>::pinst, v8);
  }
  return this;
}
