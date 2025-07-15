void __usercall vostok::render::res_shader_technique::~res_shader_technique(
        vostok::render::res_shader_technique *this@<ecx>,
        stlp_std::reverse_iterator<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *> *a2@<eax>)
{
  char *current; // eax
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi

  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *>,vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>(
    a2[3],
    a2[2]);
  current = (char *)a2[2].current;
  if ( current )
  {
    m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, current);
  }
}
