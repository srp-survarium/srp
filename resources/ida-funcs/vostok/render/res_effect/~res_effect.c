void __thiscall vostok::render::res_effect::~res_effect(vostok::render::res_effect *this)
{
  char *M_start; // eax
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi
  char *v4; // eax
  malloc_state *v5; // esi

  this->__vftable = (vostok::render::res_effect_vtbl *)&vostok::render::res_effect::`vftable';
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *>,vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>(
    (stlp_std::reverse_iterator<vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *>)this->m_techniques._M_impl._M_finish,
    (stlp_std::reverse_iterator<vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *>)this->m_techniques._M_impl._M_start);
  M_start = (char *)this->m_techniques._M_impl._M_start;
  if ( M_start )
  {
    m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
  }
  v4 = (char *)this->m_used_textures._M_impl._M_start;
  if ( v4 )
  {
    v5 = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v5, v4);
  }
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
