void __thiscall vostok::render::shadow_batched_geometry::build(
        vostok::render::shadow_batched_geometry *this,
        vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> *model_instances)
{
  vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> *m_object; // edi
  vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> *v3; // eax
  vostok::render::shadow_batched_geometry::build::__l2::surface_set *v4; // esi
  vostok::render::shadow_batched_geometry::build::__l2::surface_set *M_finish; // ebp
  vostok::render::render_model_instance_impl *v6; // ecx
  char *M_start; // eax
  void **v8; // ebx
  const void *v9; // esi
  vostok::render::shadow_batched_geometry::build::__l2::surface_set *v10; // edi
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi
  int v12; // eax
  int i; // ecx
  vostok::render::shadow_batched_geometry::build::__l2::surface_set *j; // edi
  vostok::render::grass_render_model *v15; // ecx
  const stlp_std::__true_type *v16; // [esp+10h] [ebp-78h]
  unsigned int v17; // [esp+14h] [ebp-74h]
  bool v18; // [esp+18h] [ebp-70h]
  void **end_surf; // [esp+24h] [ebp-64h]
  vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> *end; // [esp+28h] [ebp-60h]
  vostok::render::vector<`vostok::render::shadow_batched_geometry::build'::`2'::surface_set> surfaces; // [esp+2Ch] [ebp-5Ch] BYREF
  vostok::render::vector<vostok::render::render_surface_instance *> model_surfaces; // [esp+38h] [ebp-50h] BYREF
  vostok::render::shadow_batched_geometry::build::__l2::surface_set set; // [esp+44h] [ebp-44h] BYREF
  vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> *it; // [esp+8Ch] [ebp+4h]

  vostok::render::batched_geometry<vostok::render::lpv_vertex>::invalidate(
    (vostok::render::batched_geometry<vostok::render::lpv_vertex> *)this,
    (vostok::render::batched_geometry<vostok::render::lpv_vertex> *)this);
  m_object = (vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> *)model_instances->m_object;
  v3 = (vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> *)model_instances[1].m_object;
  v4 = 0;
  M_finish = 0;
  memset(&surfaces, 0, sizeof(surfaces));
  it = m_object;
  end = v3;
  if ( m_object != v3 )
  {
    do
    {
      v6 = m_object->m_object;
      memset(&model_surfaces, 0, sizeof(model_surfaces));
      v6->get_surfaces(v6, 0, 0, &model_surfaces, 0, 0, 3u);
      M_start = (char *)model_surfaces._M_impl._M_start;
      v8 = model_surfaces._M_impl._M_start;
      end_surf = model_surfaces._M_impl._M_finish;
      if ( model_surfaces._M_impl._M_start != model_surfaces._M_impl._M_finish )
      {
        do
        {
          if ( *(_DWORD *)(*(_DWORD *)*v8 + 148) )
          {
            v9 = (const void *)*((_DWORD *)*v8 + 1);
            set.surface = *(vostok::render::render_surface **)*v8;
            qmemcpy(&set, v9, 0x40u);
            if ( M_finish == surfaces._M_impl._M_end_of_storage._M_data )
            {
              __M_insert_overflow____Impl_vector_Usurface_set__1__build_shadow_batched_geometry_render_vostok__UAEXAAV__vector_V__resource_ptr_Vrender_model_instance_impl_render_vostok__Vunmanaged_intrusive_base_resources_3__resources_vostok___45__Z_V__std_allocator_Usurface_set__1__build_shadow_batched_geometry_render_vostok__UAEXAAV__vector_V__resource_ptr_Vrender_model_instance_impl_render_vostok__Vunmanaged_intrusive_base_resources_3__resources_vostok___45__Z__45__priv_stlp_std__AAEXPAUsurface_set__1__build_shadow_batched_geometry_render_vostok__UAEXAAV__vector_V__resource_ptr_Vrender_model_instance_impl_render_vostok__Vunmanaged_intrusive_base_resources_3__resources_vostok___78__Z_ABU4_1__5678_UAEX0_Z_ABU__true_type_3_I_N_Z(
                M_finish,
                (stlp_std::priv::_Impl_vector<stlp_std::pair<unsigned int,vostok::math::float4x4>,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::math::float4x4> > > *)&set,
                &surfaces._M_impl,
                &set,
                v16,
                v17,
                v18);
              M_finish = surfaces._M_impl._M_finish;
            }
            else
            {
              v10 = M_finish++;
              qmemcpy(v10, &set, sizeof(vostok::render::shadow_batched_geometry::build::__l2::surface_set));
              surfaces._M_impl._M_finish = M_finish;
            }
          }
          ++v8;
        }
        while ( v8 != end_surf );
        M_start = (char *)model_surfaces._M_impl._M_start;
        m_object = it;
      }
      if ( M_start )
      {
        m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
      }
      it = ++m_object;
    }
    while ( m_object != end );
    v4 = surfaces._M_impl._M_start;
  }
  LOBYTE(it) = 0;
  if ( v4 != M_finish )
  {
    v12 = M_finish - v4;
    for ( i = 0; v12 != 1; ++i )
      v12 >>= 1;
    _____introsort_loop_PAUsurface_set__1__build_shadow_batched_geometry_render_vostok__UAEXAAV__vector_V__resource_ptr_Vrender_model_instance_impl_render_vostok__Vunmanaged_intrusive_base_resources_3__resources_vostok___45__Z_U1_1__2345_UAEX0_Z_HUsort_predicate__8__2345_UAEX0_Z__priv_stlp_std__YAXPAUsurface_set__1__build_shadow_batched_geometry_render_vostok__UAEXAAV__vector_V__resource_ptr_Vrender_model_instance_impl_render_vostok__Vunmanaged_intrusive_base_resources_3__resources_vostok___56__Z_11HUsort_predicate__8__3456_UAEX0_Z__Z(
      v4,
      M_finish,
      0,
      2 * i,
      (vostok::render::shadow_batched_geometry::build::__l2::surface_set *)it);
    _____final_insertion_sort_PAUsurface_set__1__build_shadow_batched_geometry_render_vostok__UAEXAAV__vector_V__resource_ptr_Vrender_model_instance_impl_render_vostok__Vunmanaged_intrusive_base_resources_3__resources_vostok___45__Z_Usort_predicate__8__2345_UAEX0_Z__priv_stlp_std__YAXPAUsurface_set__1__build_shadow_batched_geometry_render_vostok__UAEXAAV__vector_V__resource_ptr_Vrender_model_instance_impl_render_vostok__Vunmanaged_intrusive_base_resources_3__resources_vostok___56__Z_1Usort_predicate__8__3456_UAEX0_Z__Z(
      v4,
      (vostok::render::shadow_batched_geometry::build::__l9::sort_predicate)m_object,
      M_finish,
      (vostok::render::shadow_batched_geometry::build::__l2::surface_set *)it);
  }
  for ( j = v4; j != M_finish; ++j )
    j->surface->add_shadow_vertices(j->surface, this, &j->transform);
  vostok::render::batched_geometry<vostok::render::shadow_vertex>::finalize_batch(this, this);
  if ( v4 )
  {
    v15 = vostok::render::g_allocator.m_object;
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free((malloc_state *)HIDWORD(v15->m_reconstruction_info_actuality_tick), (char *)v4);
  }
}
