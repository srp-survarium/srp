void __thiscall vostok::render::scene_view::~scene_view(vostok::render::scene_view *this)
{
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *M_start; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  void **v4; // eax
  void *v5; // esi
  void **v6; // eax
  void *v7; // esi
  void **v8; // eax
  void *v9; // esi
  void **v10; // eax
  void *v11; // esi
  vostok::render::post_process_parameters *v12; // ecx
  vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v13; // eax
  void *v14; // esi
  void **v15; // eax
  void *v16; // esi
  void **v17; // eax
  void *v18; // esi
  void **v19; // eax
  void *v20; // esi
  vostok::render::base_scene_view *m_object; // eax

  this->__vftable = (vostok::render::scene_view_vtbl *)&vostok::render::scene_view::`vftable';
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *>,vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>>(
    (stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *>)this->m_flash_movies._M_impl._M_finish,
    (stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *>)this->m_flash_movies._M_impl._M_start);
  M_start = this->m_flash_movies._M_impl._M_start;
  if ( M_start )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
  }
  v4 = this->m_visible_ambient_volumes._M_impl._M_start;
  if ( v4 )
  {
    v5 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v5, v4);
  }
  v6 = this->m_visible_grass_patches._M_impl._M_start;
  if ( v6 )
  {
    v7 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v7, v6);
  }
  if ( this->m_visible_particle_instances._M_impl._M_start )
    this->m_visible_particle_instances._M_impl._M_end_of_storage.m_allocator->call_free(
      this->m_visible_particle_instances._M_impl._M_end_of_storage.m_allocator,
      this->m_visible_particle_instances._M_impl._M_start);
  v8 = this->m_visible_environment_probes._M_impl._M_start;
  if ( v8 )
  {
    v9 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v9, v8);
  }
  v10 = this->m_visible_decals._M_impl._M_start;
  if ( v10 )
  {
    v11 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v11, v10);
  }
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *>,vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>(
    (stlp_std::reverse_iterator<vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *>)this->m_visible_lights._M_impl._M_finish,
    (stlp_std::reverse_iterator<vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *>)this->m_visible_lights._M_impl._M_start);
  v13 = this->m_visible_lights._M_impl._M_start;
  if ( v13 )
  {
    v14 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v14, v13);
  }
  v15 = this->m_visible_opaque_models._M_impl._M_start;
  if ( v15 )
  {
    v16 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v16, v15);
  }
  v17 = this->m_visible_models._M_impl._M_start;
  if ( v17 )
  {
    v18 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v18, v17);
  }
  v19 = this->m_visible_moved_models._M_impl._M_start;
  if ( v19 )
  {
    v20 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v20, v19);
  }
  vostok::render::post_process_parameters::~post_process_parameters(
    v12,
    &this->m_post_process_parameters.dof_height_lights.x);
  m_object = this->next_scene_view.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->next_scene_view.m_object->vostok::resources::unmanaged_intrusive_base,
      this->next_scene_view.m_object);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
