void __userpurge vostok::render::grass_template::grass_template(
        vostok::render::grass_template *this@<eax>,
        const vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *in_model_ptr@<ecx>,
        unsigned int in_index)
{
  vostok::render::grass_render_model *m_object; // ecx

  this->m_render_model.m_object = 0;
  m_object = in_model_ptr->m_object;
  if ( m_object )
  {
    this->m_render_model.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  this->m_index = in_index;
  this->m_instances._M_impl._M_start = 0;
  this->m_instances._M_impl._M_finish = 0;
  this->m_instances._M_impl._M_end_of_storage._M_data = 0;
  *(_QWORD *)&this->m_sizes.x = 0;
  this->m_sizes.z = 0.0;
}
