void __cdecl vostok::render::resource_intrusive_base::destroy<vostok::render::res_shader_technique>(
        vostok::render::res_pass *instance)
{
  vostok::memory::doug_lea_allocator *v1; // esi
  vostok::memory::doug_lea_allocator *v2; // ecx
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *v3; // [esp-4h] [ebp-14h]
  const char *v4; // [esp+0h] [ebp-10h]
  const char *v5; // [esp+4h] [ebp-Ch]
  unsigned int v6; // [esp+8h] [ebp-8h]

  if ( LOBYTE(instance[5].m_vs.m_object) )
  {
    if ( vostok::render::reclaim<vostok::render::res_geometry,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_geometry>>(
           (vostok::render::set<vostok::render::res_pass *,vostok::render::effect_manager::compare_predicate<vostok::render::res_pass> > *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->m_techniques,
           instance) )
    {
      v1 = vostok::render::g_allocator;
      vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::clear(
        v3,
        (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&instance->m_vs);
      vostok::memory::doug_lea_allocator::free_impl(v2, (int)v1, (char *)instance, v4, v5, v6);
    }
  }
}


void __usercall vostok::render::resource_intrusive_base::destroy<vostok::render::untyped_buffer>(
        const vostok::render::untyped_buffer *const instance@<esi>,
        vostok::render::hw_buffer_pool *a2)
{
  vostok::render::resource_manager *v2; // edi
  unsigned int m_size; // ecx
  vostok::render::hw_buffer_pool *v4; // [esp+0h] [ebp-8h]

  if ( instance->pool_range.owner )
  {
    v2 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
    if ( instance->m_type == enum_buffer_type_index
      && vostok::quasi_singleton<vostok::render::resource_manager>::pinst->m_indices_pool )
    {
      vostok::render::hw_buffer_pool::deallocate(&instance->pool_range, v4);
    }
    if ( instance->m_type == enum_buffer_type_vertex )
    {
      if ( v2->m_vertices_pool )
        vostok::render::hw_buffer_pool::deallocate(&instance->pool_range, a2);
    }
  }
  else
  {
    m_size = instance->m_size;
    if ( instance->m_type == enum_buffer_type_index )
      vostok::quasi_singleton<vostok::render::resource_manager>::pinst->m_total_index_buffers_size -= m_size;
    else
      vostok::quasi_singleton<vostok::render::resource_manager>::pinst->m_total_vertex_buffers_size -= m_size;
  }
}
