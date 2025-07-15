void __usercall vostok::render::backend::set_gs_samplers(
        vostok::render::backend *this@<edi>,
        vostok::render::res_sampler_list *samplers@<eax>)
{
  unsigned int v2; // ecx

  if ( this->m_gs_samplers_handler.m_current.m_object != samplers )
  {
    v2 = 0;
    this->m_gs_samplers_handler.m_diff_range_start = 0;
    if ( samplers )
      v2 = samplers->m_samplers.m_end - samplers->m_samplers.m_begin;
    this->m_gs_samplers_handler.m_diff_range_end = v2;
    vostok::intrusive_ptr<vostok::render::res_sampler_list const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::operator=(
      (vostok::intrusive_ptr<vostok::render::res_sampler_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&this->m_gs_samplers_handler.m_current,
      samplers);
    this->m_dirty_objects.geometry_samplers = 1;
  }
}
