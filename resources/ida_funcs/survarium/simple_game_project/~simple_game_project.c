void __thiscall survarium::simple_game_project::~simple_game_project(survarium::simple_game_project *this)
{
  survarium::render_visual **p_m_render_visuals; // esi
  survarium::base_project *v3; // ebp
  vostok::memory::doug_lea_allocator *v4; // eax
  void **M_start; // eax
  void *v6; // esi
  void **v7; // eax
  void *v8; // esi
  vostok::resources::resource_ptr<survarium::ladder,vostok::resources::unmanaged_intrusive_base> *v9; // eax
  void *v10; // esi
  void **v11; // eax
  void *v12; // esi
  vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *v13; // eax
  void *v14; // esi
  void **v15; // eax
  void *v16; // esi
  void **v17; // eax
  void *v18; // esi
  vostok::configs::binary_config *m_object; // eax

  p_m_render_visuals = &this->m_render_visuals;
  v3 = &this->survarium::base_project;
  this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (survarium::simple_game_project_vtbl *)&survarium::simple_game_project::`vftable'{for `vostok::resources::unmanaged_resource'};
  this->survarium::base_project::__vftable = (survarium::base_project_vtbl *)&survarium::simple_game_project::`vftable'{for `survarium::base_project'};
  if ( this->m_render_visuals )
  {
    v4 = (vostok::memory::doug_lea_allocator *)boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
    vostok::memory::detail::delete_array_helper_impl<vostok::memory::doug_lea_allocator,survarium::render_visual,vostok::memory::detail::call_destructor_predicate>(
      p_m_render_visuals,
      v4);
  }
  M_start = this->m_victory_items_containers._M_impl._M_start;
  if ( M_start )
  {
    v6 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v6, M_start);
  }
  v7 = this->m_anomalies._M_impl._M_start;
  if ( v7 )
  {
    v8 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v8, v7);
  }
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *>,vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>>(
    (stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *>)this->m_ladders._M_impl._M_finish,
    (stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *>)this->m_ladders._M_impl._M_start);
  v9 = this->m_ladders._M_impl._M_start;
  if ( v9 )
  {
    v10 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v10, v9);
  }
  v11 = this->m_artefact_containers._M_impl._M_start;
  if ( v11 )
  {
    v12 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v12, v11);
  }
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *>,vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>>(
    (stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *>)this->m_damage_zones._M_impl._M_finish,
    (stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *>)this->m_damage_zones._M_impl._M_start);
  v13 = this->m_damage_zones._M_impl._M_start;
  if ( v13 )
  {
    v14 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v14, v13);
  }
  v15 = this->m_collision_geometries._M_impl._M_start;
  if ( v15 )
  {
    v16 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v16, v15);
  }
  if ( this->m_respawn_points._M_t._M_node_count )
  {
    stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,survarium::respawn_point_core *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,survarium::respawn_point_core *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,survarium::respawn_point_core *>>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::respawn_point_core *>>>::_M_erase(
      &this->m_respawn_points._M_t,
      this->m_respawn_points._M_t._M_header._M_data._M_parent);
    this->m_respawn_points._M_t._M_header._M_data._M_left = &this->m_respawn_points._M_t._M_header._M_data;
    this->m_respawn_points._M_t._M_header._M_data._M_parent = 0;
    this->m_respawn_points._M_t._M_header._M_data._M_right = &this->m_respawn_points._M_t._M_header._M_data;
    this->m_respawn_points._M_t._M_node_count = 0;
  }
  v17 = this->m_objects._M_impl._M_start;
  if ( v17 )
  {
    v18 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v18, v17);
  }
  m_object = this->m_config.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_config.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_config.m_object);
  survarium::base_project::~base_project(v3);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
