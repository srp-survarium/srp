void __thiscall vostok::render::scene::~scene(vostok::render::scene *this)
{
  vostok::render::material_effects_instance *m_object; // ecx
  vostok::render::speedtree_forest *m_speedtree_forest; // esi
  vostok::render::grass_render_model *v4; // ebp
  vostok::render::speedtree_forest *v5; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::grass_render_model *v7; // ebp
  _BYTE *v8; // esi
  void *v9; // eax
  void *v10; // esi
  vostok::collision::space_partitioning_tree *m_decals_tree; // esi
  void (__thiscall *insert)(vostok::collision::space_partitioning_tree *, vostok::collision::object *, const vostok::math::float4x4 *); // ebp
  vostok::collision::space_partitioning_tree *m_models_tree; // esi
  void (__thiscall *v14)(vostok::collision::space_partitioning_tree *, vostok::collision::object *, const vostok::math::float4x4 *); // ebp
  vostok::collision::space_partitioning_tree *m_environment_probes_tree; // esi
  void (__thiscall *v16)(vostok::collision::space_partitioning_tree *, vostok::collision::object *, const vostok::math::float4x4 *); // ebp
  vostok::particle::world *v17; // eax
  vostok::render::lights_db *v18; // esi
  vostok::render::grass_render_model *v19; // ebp
  vostok::render::lights_db *v20; // eax
  void *v21; // esi
  vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> *M_start; // eax
  void *v23; // esi
  stlp_std::pair<unsigned int,vostok::math::float4x4> *v24; // eax
  void *v25; // esi
  void **v26; // eax
  void *v27; // esi
  void **v28; // eax
  void *v29; // esi
  void **v30; // eax
  void *v31; // esi
  vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *v32; // eax
  void *v33; // esi
  vostok::resources::resource_ptr<vostok::render::speedtree_instance,vostok::resources::unmanaged_intrusive_base> *v34; // eax
  void *v35; // esi
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v36; // eax
  void *v37; // esi
  vostok::render::batched_geometry<vostok::render::shadow_vertex> *v38; // ecx
  vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> *v39; // eax
  void *v40; // esi
  unsigned __int16 *v41; // eax
  void *v42; // esi
  vostok::render::vertex_colored *v43; // eax
  void *v44; // esi
  unsigned __int16 *v45; // eax
  void *v46; // esi
  vostok::render::vertex_colored *v47; // eax
  void *v48; // esi
  vostok::render::batched_geometry<vostok::render::lpv_vertex> *v49; // ecx
  vostok::render::material_effects_instance *v50; // eax
  stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *v51; // eax
  void *v52; // esi
  vostok::render::streaming_ready_texture *v53; // eax
  void *v54; // esi
  vostok::render::requested_streamable_texture *v55; // eax
  void *v56; // esi
  vostok::render::streamable_texture_info *v57; // eax
  void *v58; // esi
  vostok::render::base_scene *v59; // eax
  _BYTE *v60; // [esp+18h] [ebp-4h]
  _BYTE *v61; // [esp+18h] [ebp-4h]
  _BYTE *v62; // [esp+18h] [ebp-4h]

  m_object = this->m_sky_material.m_object;
  this->__vftable = (vostok::render::scene_vtbl *)&vostok::render::scene::`vftable';
  if ( m_object )
    vostok::render::material_manager::remove_material_effects(
      (vostok::render::material_manager *)m_object,
      (const vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.y);
  m_speedtree_forest = this->m_speedtree_forest;
  v4 = vostok::render::g_allocator.m_object;
  if ( m_speedtree_forest )
  {
    vostok::render::speedtree_forest::~speedtree_forest(
      (vostok::render::speedtree_forest *)m_object,
      this->m_speedtree_forest);
    v5 = m_speedtree_forest;
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(v4->m_reconstruction_info_actuality_tick);
    BYTE2(v4->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v5);
    this->m_speedtree_forest = 0;
  }
  v7 = vostok::render::g_allocator.m_object;
  if ( this->m_grass )
  {
    v8 = __RTCastToVoid((void **)&this->m_grass->__vftable);
    ((void (__thiscall *)(vostok::render::grass_world *, _DWORD))this->m_grass->~vostok::resources::resource_base)(
      this->m_grass,
      0);
    if ( v8 )
    {
      v9 = v8;
      v10 = (void *)HIDWORD(v7->m_reconstruction_info_actuality_tick);
      BYTE2(v7->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v10, v9);
    }
    this->m_grass = 0;
  }
  m_decals_tree = this->m_decals_tree;
  if ( m_decals_tree )
  {
    insert = m_decals_tree[4].insert;
    v60 = __RTCastToVoid((void **)&this->m_decals_tree->__vftable);
    ((void (__thiscall *)(vostok::collision::space_partitioning_tree *, _DWORD))m_decals_tree->~vostok::collision::space_partitioning_tree)(
      m_decals_tree,
      0);
    (*(void (__thiscall **)(void (__thiscall *)(vostok::collision::space_partitioning_tree *, vostok::collision::object *, const vostok::math::float4x4 *), _BYTE *))(*(_DWORD *)insert + 24))(
      insert,
      v60);
  }
  m_models_tree = this->m_models_tree;
  if ( m_models_tree )
  {
    v14 = m_models_tree[4].insert;
    v61 = __RTCastToVoid((void **)&this->m_models_tree->__vftable);
    ((void (__thiscall *)(vostok::collision::space_partitioning_tree *, _DWORD))m_models_tree->~vostok::collision::space_partitioning_tree)(
      m_models_tree,
      0);
    (*(void (__thiscall **)(void (__thiscall *)(vostok::collision::space_partitioning_tree *, vostok::collision::object *, const vostok::math::float4x4 *), _BYTE *))(*(_DWORD *)v14 + 24))(
      v14,
      v61);
  }
  m_environment_probes_tree = this->m_environment_probes_tree;
  if ( m_environment_probes_tree )
  {
    v16 = m_environment_probes_tree[4].insert;
    v62 = __RTCastToVoid((void **)&this->m_environment_probes_tree->__vftable);
    ((void (__thiscall *)(vostok::collision::space_partitioning_tree *, _DWORD))m_environment_probes_tree->~vostok::collision::space_partitioning_tree)(
      m_environment_probes_tree,
      0);
    (*(void (__thiscall **)(void (__thiscall *)(vostok::collision::space_partitioning_tree *, vostok::collision::object *, const vostok::math::float4x4 *), _BYTE *))(*(_DWORD *)v16 + 24))(
      v16,
      v62);
  }
  v17 = this->m_particle_world.m_object;
  if ( v17 )
  {
    m_object = (vostok::render::material_effects_instance *)_InterlockedExchangeAdd(&v17->m_reference_count, 0xFFFFFFFF);
    if ( !m_object )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &this->m_particle_world.m_object->vostok::resources::unmanaged_intrusive_base,
        this->m_particle_world.m_object);
  }
  v18 = this->m_lights.m_object;
  v19 = vostok::render::g_allocator.m_object;
  if ( v18 )
  {
    vostok::render::lights_db::~lights_db(
      (vostok::render::lights_db *)m_object,
      (stlp_std::reverse_iterator<vostok::render::light_data *> *)this->m_lights.m_object);
    v20 = v18;
    v21 = (void *)HIDWORD(v19->m_reconstruction_info_actuality_tick);
    BYTE2(v19->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v21, v20);
    this->m_lights.m_object = 0;
  }
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *>,vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>>(
    (stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *>)this->m_render_model_instances._M_impl._M_finish,
    (stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *>)this->m_render_model_instances._M_impl._M_start);
  M_start = this->m_render_model_instances._M_impl._M_start;
  if ( M_start )
  {
    v23 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v23, M_start);
  }
  v24 = this->m_lpv_occluders._M_impl._M_start;
  if ( v24 )
  {
    v25 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v25, v24);
  }
  v26 = this->m_environment_probes._M_impl._M_start;
  if ( v26 )
  {
    v27 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v27, v26);
  }
  v28 = this->m_ambient_volumes._M_impl._M_start;
  if ( v28 )
  {
    v29 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v29, v28);
  }
  v30 = this->m_sky_ao_volumes._M_impl._M_start;
  if ( v30 )
  {
    v31 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v31, v30);
  }
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *>,vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>>(
    (stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *>)this->m_tracers._M_impl._M_finish,
    (stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *>)this->m_tracers._M_impl._M_start);
  v32 = this->m_tracers._M_impl._M_start;
  if ( v32 )
  {
    v33 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v33, v32);
  }
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *>,vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>>(
    (stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *>)this->m_speedtree_instances._M_impl._M_finish,
    (stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *>)this->m_speedtree_instances._M_impl._M_start);
  v34 = this->m_speedtree_instances._M_impl._M_start;
  if ( v34 )
  {
    v35 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v35, v34);
  }
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>(
    (stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>)this->m_particle_system_instances._M_impl._M_finish,
    (stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>)this->m_particle_system_instances._M_impl._M_start);
  v36 = this->m_particle_system_instances._M_impl._M_start;
  if ( v36 )
  {
    v37 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v37, v36);
  }
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *>,vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>>(
    (stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *>)this->m_selected_models._M_impl._M_finish,
    (stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *>)this->m_selected_models._M_impl._M_start);
  v39 = this->m_selected_models._M_impl._M_start;
  if ( v39 )
  {
    v40 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v40, v39);
  }
  v41 = this->m_triangle_indices._M_impl._M_start;
  if ( v41 )
  {
    v42 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v42, v41);
  }
  v43 = this->m_triangle_vertices._M_impl._M_start;
  if ( v43 )
  {
    v44 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v44, v43);
  }
  v45 = this->m_line_indices._M_impl._M_start;
  if ( v45 )
  {
    v46 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v46, v45);
  }
  v47 = this->m_line_vertices._M_impl._M_start;
  if ( v47 )
  {
    v48 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v48, v47);
  }
  vostok::render::batched_geometry<vostok::render::shadow_vertex>::~batched_geometry<vostok::render::shadow_vertex>(
    v38,
    (vostok::render::geometry_batch *)this,
    &this->m_shadow_geometry);
  vostok::render::batched_geometry<vostok::render::lpv_vertex>::~batched_geometry<vostok::render::lpv_vertex>(
    v49,
    (vostok::render::geometry_batch *)this,
    &this->m_lpv_geometry);
  v50 = this->m_sky_material.m_object;
  if ( v50 && !_InterlockedExchangeAdd(&v50->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_sky_material.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_sky_material.m_object);
  v51 = this->m_volume_fogs._M_impl._M_start;
  if ( v51 )
  {
    v52 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v52, v51);
  }
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::render::streaming_ready_texture *>,vostok::render::streaming_ready_texture>(
    (stlp_std::reverse_iterator<vostok::render::streaming_ready_texture *>)this->ready_streaming_textures._M_impl._M_finish,
    (stlp_std::reverse_iterator<vostok::render::streaming_ready_texture *>)this->ready_streaming_textures._M_impl._M_start);
  v53 = this->ready_streaming_textures._M_impl._M_start;
  if ( v53 )
  {
    v54 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v54, v53);
  }
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::render::requested_streamable_texture *>,vostok::render::requested_streamable_texture>(
    (stlp_std::reverse_iterator<vostok::render::requested_streamable_texture *>)this->requested_streamable_textures._M_impl._M_finish,
    (stlp_std::reverse_iterator<vostok::render::requested_streamable_texture *>)this->requested_streamable_textures._M_impl._M_start);
  v55 = this->requested_streamable_textures._M_impl._M_start;
  if ( v55 )
  {
    v56 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v56, v55);
  }
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::render::streamable_texture_info *>,vostok::render::streamable_texture_info>(
    (stlp_std::reverse_iterator<vostok::render::streamable_texture_info *>)this->streaming_textures._M_impl._M_finish,
    (stlp_std::reverse_iterator<vostok::render::streamable_texture_info *>)this->streaming_textures._M_impl._M_start);
  v57 = this->streaming_textures._M_impl._M_start;
  if ( v57 )
  {
    v58 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v58, v57);
  }
  v59 = this->next_scene.m_object;
  if ( v59 && !_InterlockedExchangeAdd(&v59->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->next_scene.m_object->vostok::resources::unmanaged_intrusive_base,
      this->next_scene.m_object);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
