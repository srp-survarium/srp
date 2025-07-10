void __userpurge vostok::render::stage_shadow_direct::prepare_models(
        const vostok::math::float3 *view_pos@<ecx>,
        vostok::render::stage_shadow_direct *this,
        vostok::render::vector<vostok::render::render_surface_instance *> *m_caster_model,
        const vostok::math::float4x4 *orig_view_projection,
        unsigned int cascade_index,
        unsigned int shadow_map_size)
{
  vostok::render::vector<vostok::render::render_surface_instance *> *v6; // edi
  void **M_finish; // esi
  vostok::render::render_surface_instance **v8; // eax
  void **v9; // ebx
  void **v10; // ebp
  vostok::sound::sound_world *v11; // esi
  vostok::render::render_surface_instance *const *v12; // eax
  void (__thiscall *tick)(vostok::sound::world *); // ecx
  int v14; // edx
  vostok::render::material_effects *v15; // ecx
  signed int v16; // ebp
  unsigned int v17; // eax
  int *v18; // ecx
  unsigned int v19; // edi
  unsigned __int8 *v20; // eax
  unsigned __int8 *v21; // esi
  int v22; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  void **v24; // eax
  vostok::render::lights_db *m_object; // eax
  vostok::render::light *v26; // ecx
  int v27; // edi
  bool v28; // zf
  vostok::render::grass_render_model *v29; // esi
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v30; // ecx
  vostok::render::renderer_context *m_context; // eax
  vostok::render::sun_cascade *m_begin; // edx
  __int64 v33; // xmm0_8
  void **v34; // eax
  vostok::render::grass_render_model *v35; // ecx
  vostok::render::remove_inappropriate_models v36; // [esp-18h] [ebp-194h]
  void **v37; // [esp-18h] [ebp-194h]
  vostok::sound::sound_world *M_start; // [esp-4h] [ebp-180h]
  stlp_std::priv::_STLP_alloc_proxy<unsigned int *,unsigned int,vostok::render::std_allocator<unsigned int> > *v39; // [esp+0h] [ebp-17Ch]
  vostok::render::render_surface_instance *const *i; // [esp+14h] [ebp-168h]
  int v41; // [esp+18h] [ebp-164h] BYREF
  vostok::render::vector<vostok::render::render_surface_instance *> opaque_models; // [esp+1Ch] [ebp-160h] BYREF
  vostok::render::render_surface_instance *const *e; // [esp+28h] [ebp-154h]
  int v44; // [esp+2Ch] [ebp-150h] BYREF
  __int128 v45; // [esp+30h] [ebp-14Ch]
  __int64 v46; // [esp+40h] [ebp-13Ch]
  vostok::math::float4x4 result; // [esp+48h] [ebp-134h] BYREF
  vostok::math::frustum frust; // [esp+88h] [ebp-F4h] BYREF
  vostok::math::frustum view_frustum; // [esp+100h] [ebp-7Ch] BYREF

  v6 = m_caster_model;
  vostok::render::scene::select_models(
    this->m_context->m_scene,
    &this->m_context->m_vp,
    m_caster_model,
    view_pos,
    2u,
    0);
  if ( cascade_index )
  {
    vostok::math::mul4x3(
      &result,
      (const vostok::math::float4x4 *)&this->m_previous_adjastment[3].elements[16 * cascade_index + 2],
      &this->m_previous_view_matrix[cascade_index + 3]);
    vostok::math::frustum::frustum(&frust, &result);
    if ( s_test_shadow_culling0 )
    {
      M_finish = m_caster_model->_M_impl._M_finish;
      v8 = stlp_std::priv::__find_if<vostok::render::render_surface_instance * *,vostok::render::remove_model_if_in_frustum_predicate>(
             (vostok::render::render_surface_instance **)m_caster_model->_M_impl._M_start,
             (vostok::render::render_surface_instance **)M_finish,
             (vostok::render::remove_model_if_in_frustum_predicate)&frust);
      if ( v8 != (vostok::render::render_surface_instance **)M_finish )
        v8 = stlp_std::remove_copy_if<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance * *,vostok::render::remove_model_if_in_frustum_predicate>(
               v8 + 1,
               (vostok::render::render_surface_instance **)M_finish,
               v8,
               (vostok::render::remove_model_if_in_frustum_predicate)&frust);
      stlp_std::vector<vostok::render::render_surface_instance *,vostok::render::std_allocator<vostok::render::render_surface_instance *>>::erase(
        (void **)v8,
        M_finish,
        (stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *)m_caster_model);
      v6 = m_caster_model;
    }
  }
  v9 = 0;
  v10 = 0;
  M_start = (vostok::sound::sound_world *)v6->_M_impl._M_start;
  memset(&opaque_models, 0, sizeof(opaque_models));
  v11 = boost::get_pointer<vostok::sound::sound_scene>(M_start);
  i = (vostok::render::render_surface_instance *const *)v11;
  v12 = (vostok::render::render_surface_instance *const *)boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)v6->_M_impl._M_finish);
  e = v12;
  if ( v11 != (vostok::sound::sound_world *)v12 )
  {
    do
    {
      tick = v11->tick;
      v14 = *((_DWORD *)tick + 37);
      if ( !v14 || s_use_one_material_value )
        v15 = s_nomaterial_material_effects[*((_DWORD *)tick + 1)];
      else
        v15 = (vostok::render::material_effects *)(v14 + 264);
      if ( v15->m_effects[28].m_object )
      {
        if ( v10 == opaque_models._M_impl._M_end_of_storage._M_data )
        {
          v16 = (char *)v10 - (char *)v9;
          v17 = v16 >> 2;
          v41 = 1;
          v44 = v16 >> 2;
          if ( v16 >> 2 == 0x3FFFFFFF )
          {
            opaque_models._M_impl._M_start = v9;
            stlp_std::__stl_throw_length_error("vector");
          }
          v18 = &v44;
          if ( v17 <= 1 )
            v18 = &v41;
          v19 = v17 + *v18;
          if ( v19 > 0x3FFFFFFF || v19 < v17 )
            v19 = 0x3FFFFFFF;
          v20 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>>>::allocate(
                                     v19,
                                     v39);
          v21 = v20;
          v41 = (int)v20;
          if ( v16 )
          {
            memmove(v20, (unsigned __int8 *)v9, v16);
            v20 = (unsigned __int8 *)(v16 + v22);
          }
          *(vostok::render::render_surface_instance **)v20 = *i;
          v10 = (void **)(v20 + 4);
          if ( v9 )
          {
            m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
            BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
            vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v9);
            v21 = (unsigned __int8 *)v41;
          }
          v24 = (void **)&v21[4 * v19];
          v9 = (void **)v21;
          v11 = (vostok::sound::sound_world *)i;
          opaque_models._M_impl._M_end_of_storage._M_data = v24;
          v12 = e;
        }
        else
        {
          *v10++ = v11->__vftable;
        }
        opaque_models._M_impl._M_finish = v10;
      }
      v11 = (vostok::sound::sound_world *)((char *)v11 + 4);
      i = (vostok::render::render_surface_instance *const *)v11;
    }
    while ( v11 != (vostok::sound::sound_world *)v12 );
    opaque_models._M_impl._M_start = v9;
  }
  m_object = this->m_context->m_scene->m_lights.m_object;
  v26 = m_object->m_sun.m_object;
  if ( v26
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    && !v26->m_enabled
    || (v27 = (int)m_object->m_sun.m_object, !v26) )
  {
    if ( v9 )
    {
      v35 = vostok::render::g_allocator.m_object;
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      goto LABEL_43;
    }
  }
  else
  {
    v28 = ++v26->m_reference_count == 1;
    --v26->m_reference_count;
    if ( v28 )
    {
      v29 = vostok::render::g_allocator.m_object;
      vostok::render::light::~light(v26, v27);
      BYTE2(v29->m_children_resources.m_lock) = 0;
      vostok_mspace_free((void *)HIDWORD(v29->m_reconstruction_info_actuality_tick), (void *)v27);
    }
    vostok::math::frustum::frustum(&view_frustum, orig_view_projection);
    if ( s_test_shadow_culling1 )
    {
      m_context = this->m_context;
      m_begin = m_context->m_sun_cascades.m_begin;
      v33 = *(_QWORD *)(v27 + 164);
      HIDWORD(v45) = *(_DWORD *)(v27 + 172);
      LODWORD(v45) = m_context;
      *(_QWORD *)((char *)&v45 + 4) = v33;
      *(float *)&v46 = m_begin[cascade_index].size;
      HIDWORD(v46) = &view_frustum;
      *(_QWORD *)&v36.m_context = v45;
      *(_QWORD *)&v36.m_sun_dir.elements[1] = *((_QWORD *)&v45 + 1);
      *(_QWORD *)&v36.m_cascade_size = v46;
      v34 = (void **)stlp_std::remove_if<vostok::render::render_surface_instance * *,vostok::render::remove_inappropriate_models>(
                       (vostok::render::render_surface_instance **)v9,
                       (vostok::render::render_surface_instance **)v10,
                       v36);
      if ( v34 != v10 )
      {
        v37 = stlp_std::priv::__copy_ptrs<void * *,void * *>(v10, v10, v34);
        stlp_std::_Destroy<vostok::fs_new::virtual_path_string>();
        v10 = v37;
        opaque_models._M_impl._M_finish = v37;
      }
    }
    if ( s_sorting_value )
      stlp_std::sort<vostok::render::render_surface_instance * *,vostok::render::sort_by_vs_predicate>(
        (vostok::render::render_surface_instance **)v9,
        (vostok::render::render_surface_instance **)v10,
        (vostok::render::sort_by_ps_predicate)28LL);
    if ( s_sorting3_value )
      stlp_std::sort<vostok::render::render_surface_instance * *,vostok::render::sort_by_texture_predicate>(
        (vostok::render::render_surface_instance **)v9,
        (vostok::render::render_surface_instance **)v10,
        (vostok::render::sort_by_texture_predicate)28LL);
    stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::operator=(
      v30,
      (int)m_caster_model,
      (unsigned int)&opaque_models);
    if ( v9 )
    {
      v35 = vostok::render::g_allocator.m_object;
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
LABEL_43:
      vostok_mspace_free((void *)HIDWORD(v35->m_reconstruction_info_actuality_tick), v9);
    }
  }
}
