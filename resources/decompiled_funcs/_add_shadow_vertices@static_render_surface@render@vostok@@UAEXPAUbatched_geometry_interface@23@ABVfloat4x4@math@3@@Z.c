void __thiscall vostok::render::static_render_surface::add_shadow_vertices(
        vostok::render::static_render_surface *this,
        vostok::render::batched_geometry_interface *in_out_geometry,
        const vostok::math::float4x4 *transform)
{
  vostok::render::batched_vertex_source *v3; // eax
  vostok::render::enum_vertex_input_type m_vertex_input_type; // ecx
  vostok::render::batched_vertex_source *v6; // edi
  unsigned __int16 *M_start; // ebp
  unsigned __int16 *M_finish; // ebx
  const vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *p_m_materail_effects_instance; // edx
  char v10; // bl
  unsigned __int16 *v11; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::batched_vertex_source *v13; // eax
  void *v14; // esi
  vostok::render::grass_render_model *m_object; // ecx
  int v16; // [esp+8h] [ebp-30h]
  int v17; // [esp+Ch] [ebp-2Ch]
  int *v18; // [esp+10h] [ebp-28h]
  unsigned int v19; // [esp+14h] [ebp-24h]
  vostok::resources::unmanaged_resource *resource; // [esp+18h] [ebp-20h] BYREF
  unsigned int v21; // [esp+1Ch] [ebp-1Ch]
  vostok::render::vector<vostok::render::batched_vertex_source> out_vertices; // [esp+20h] [ebp-18h] BYREF
  vostok::render::vector<unsigned short> out_indices; // [esp+2Ch] [ebp-Ch] BYREF

  v3 = 0;
  resource = 0;
  m_vertex_input_type = this->m_vertex_input_type;
  v6 = 0;
  M_start = 0;
  M_finish = 0;
  memset(&out_vertices, 0, sizeof(out_vertices));
  memset(&out_indices, 0, sizeof(out_indices));
  if ( m_vertex_input_type == static_mesh_vertex_input_type )
  {
    vostok::render::fill_source_vertices_impl__vostok::render::fill_source_vertices_::_2_::static_vertex_(
      0,
      0,
      0,
      (int)this,
      &this->m_render_geometry,
      &out_vertices,
      &out_indices,
      v16,
      v17,
      v18,
      v19);
LABEL_5:
    M_start = out_indices._M_impl._M_start;
    M_finish = out_indices._M_impl._M_finish;
    v6 = out_vertices._M_impl._M_start;
    v3 = out_vertices._M_impl._M_finish;
    goto LABEL_6;
  }
  if ( m_vertex_input_type == static_mesh_vertex_colored_input_type )
  {
    vostok::render::fill_source_vertices_impl__vostok::render::fill_source_vertices_::_2_::colored_static_vertex_(
      0,
      0,
      0,
      (int)this,
      &this->m_render_geometry,
      &out_vertices,
      &out_indices,
      v16,
      v17,
      v18,
      v19);
    goto LABEL_5;
  }
LABEL_6:
  if ( v3 - v6 && (v21 = M_finish - M_start) != 0 )
  {
    p_m_materail_effects_instance = &this->m_materail_effects_instance;
    if ( this->m_materail_effects_instance.m_object->m_material_effects.is_use_alpha_test )
    {
      v10 = (char)resource;
    }
    else
    {
      v10 = 1;
      resource = 0;
      p_m_materail_effects_instance = (const vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *)&resource;
    }
    in_out_geometry->add_data(in_out_geometry, v6, v3 - v6, M_start, v21, transform, p_m_materail_effects_instance);
    if ( (v10 & 1) != 0 && resource && !_InterlockedExchangeAdd(&resource->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &resource->vostok::resources::unmanaged_intrusive_base,
        resource);
    v11 = out_indices._M_impl._M_start;
    if ( out_indices._M_impl._M_start )
    {
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v11);
    }
    v13 = out_vertices._M_impl._M_start;
    if ( out_vertices._M_impl._M_start )
      goto LABEL_23;
  }
  else
  {
    if ( M_start )
    {
      v14 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v14, M_start);
      v6 = out_vertices._M_impl._M_start;
    }
    if ( v6 )
    {
      v13 = v6;
LABEL_23:
      m_object = vostok::render::g_allocator.m_object;
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free((void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick), (void *)v13);
    }
  }
}
