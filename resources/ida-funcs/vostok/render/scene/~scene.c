void __thiscall vostok::render::scene::~scene(vostok::render::scene *this)
{
  vostok::render::unique_ptr<vostok::render::lights_db> *v2; // ecx
  vostok::render::texture_streaming_async_worker *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  vostok::buffer_vector<vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> > *v5; // ecx
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> > > *v6; // ecx
  vostok::buffer_vector<vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> > *v7; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v8; // edi
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **v9; // esi
  vostok::fixed_vector<vostok::resources::managed_resource *,10000>::allign_helper *v10; // esi
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *i; // edi
  vostok::render::batched_geometry<vostok::render::shadow_vertex> *v12; // ecx
  vostok::render::batched_geometry<vostok::render::lpv_vertex> *v13; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v14; // ecx
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> > > *v15; // ecx
  vostok::render::streaming_ready_texture **v16; // edi
  vostok::buffer_vector<vostok::render::requested_streamable_texture> *v17; // ecx
  vostok::buffer_vector<vostok::render::streamable_texture_info> *v18; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v19; // ecx

  this->__vftable = (vostok::render::scene_vtbl *)&vostok::render::scene::`vftable';
  vostok::render::delete_tree((vostok::collision::space_partitioning_tree **)((char *)&dword_8B965C + (_DWORD)this));
  vostok::render::delete_tree((vostok::collision::space_partitioning_tree **)((char *)&dword_8B9658 + (_DWORD)this));
  vostok::render::delete_tree((vostok::collision::space_partitioning_tree **)((char *)&dword_8B9654 + (_DWORD)this));
  vostok::render::delete_tree((vostok::collision::space_partitioning_tree **)((char *)&dword_8B9650 + (_DWORD)this));
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((char *)&dword_8B9668 + (_DWORD)this));
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((char *)&dword_8B9664 + (_DWORD)this));
  vostok::render::unique_ptr<vostok::render::lights_db>::~unique_ptr<vostok::render::lights_db>(
    v2,
    (vostok::render::lights_db **)((char *)&dword_8B9660 + (_DWORD)this));
  vostok::render::texture_streaming_async_worker::ensure_completion(v3, (int)&unk_8B9588 + (_DWORD)this);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v4,
    (int *)((char *)&unk_8B9588 + (_DWORD)this + 40));
  survarium::registry_of_artefacts::unregister_artefacts(
    v5,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)&this->m_render_model_instances);
  stlp_std::priv::_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128>>,stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *>>>::~_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128>>,stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *>>>(
    v6,
    (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> > > *)((char *)&btDiscreteCollisionDetectorInterface `RTTI Type Descriptor' + (_DWORD)this));
  *(_DWORD *)&aAvbtcollisionw[(_DWORD)this + 8] = *(_DWORD *)&aAvbtcollisionw[(_DWORD)this + 4];
  this->m_ready_potential_requests.m_end = this->m_ready_potential_requests.m_begin;
  *(const float *)((char *)&SNaN_33 + (_DWORD)this + 4) = *(const float *)((char *)&SNaN_33 + (_DWORD)this);
  *(vostok::fixed_vector<vostok::resources::managed_resource *,10000>::allign_helper *)((char *)&vostok::memory::s_resources.m_buffer[9315]
                                                                                      + (_DWORD)this) = *(vostok::fixed_vector<vostok::resources::managed_resource *,10000>::allign_helper *)((char *)&vostok::memory::s_resources.m_buffer[9314] + (_DWORD)this);
  v7 = *(vostok::buffer_vector<vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> > **)((char *)&vostok::memory::s_resources.m_buffer[8287] + (_DWORD)this);
  *(vostok::fixed_vector<vostok::resources::managed_resource *,10000>::allign_helper *)((char *)&vostok::memory::s_resources.m_buffer[8288]
                                                                                      + (_DWORD)this) = (vostok::fixed_vector<vostok::resources::managed_resource *,10000>::allign_helper)v7;
  v8 = *(vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)((char *)&vostok::memory::s_resources.m_buffer[7260] + (_DWORD)this);
  v9 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)((char *)&vostok::memory::s_resources.m_buffer[7261] + (_DWORD)this);
  while ( v8 != *v9 )
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(v8++);
  *v9 = *(vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)((char *)&vostok::memory::s_resources.m_buffer[7260] + (_DWORD)this);
  v10 = (vostok::fixed_vector<vostok::resources::managed_resource *,10000>::allign_helper *)((char *)&vostok::memory::s_resources.m_buffer[6233]
                                                                                           + (_DWORD)this);
  for ( i = *(vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)((char *)&vostok::memory::s_resources.m_buffer[6233] + (_DWORD)this);
        i != (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v10[1];
        ++i )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(i);
  }
  v10[1] = *v10;
  survarium::registry_of_artefacts::unregister_artefacts(
    v7,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)((char *)&vostok::memory::s_resources.m_buffer[4182] + (_DWORD)this));
  this->m_triangle_indices.m_end = this->m_triangle_indices.m_begin;
  *(_UNKNOWN **)((char *)&off_6F34D4 + (_DWORD)this + 4) = *(_UNKNOWN **)((char *)&off_6F34D4 + (_DWORD)this);
  *(_DWORD *)((char *)&loc_6534C8 + (_DWORD)this + 4) = *(_DWORD *)((char *)&loc_6534C8 + (_DWORD)this);
  v12 = *(vostok::render::batched_geometry<vostok::render::shadow_vertex> **)((char *)&loc_5534BC + (_DWORD)this);
  *(_DWORD *)((char *)&loc_5534BC + (_DWORD)this + 4) = v12;
  vostok::render::batched_geometry<vostok::render::shadow_vertex>::~batched_geometry<vostok::render::shadow_vertex>(
    v12,
    (int)&loc_330B64 + (_DWORD)this);
  vostok::render::batched_geometry<vostok::render::lpv_vertex>::~batched_geometry<vostok::render::lpv_vertex>(
    v13,
    (int)this + (_DWORD)&loc_1CE217 + 1);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v14,
    (int *)((char *)&loc_1CE1E0 + (_DWORD)this));
  stlp_std::priv::_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128>>,stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *>>>::~_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128>>,stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *>>>(
    v15,
    (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> > > *)((char *)survarium::weapon_user_animations_selector::stand_from_crouch_predicate + (_DWORD)this));
  *(int *)((char *)&dword_1CA194 + (_DWORD)this + 4) = *(int *)((char *)&dword_1CA194 + (_DWORD)this);
  *(_DWORD *)((char *)&loc_1C6188 + (_DWORD)this + 4) = *(_DWORD *)((char *)&loc_1C6188 + (_DWORD)this);
  *(_DWORD *)((char *)&loc_1BE17C + (_DWORD)this + 4) = *(_DWORD *)((char *)&loc_1BE17C + (_DWORD)this);
  v16 = (vostok::render::streaming_ready_texture **)((char *)&loc_12E16C + (_DWORD)this + 4);
  vostok::buffer_vector<vostok::render::streaming_ready_texture>::destroy(
    *(vostok::render::streaming_ready_texture **)((char *)&loc_12E16C + (_DWORD)this),
    v16);
  *v16 = *(vostok::render::streaming_ready_texture **)((char *)&loc_12E16C + (_DWORD)this);
  vostok::buffer_vector<vostok::render::requested_streamable_texture>::clear(
    v17,
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)((char *)&dword_E8160 + (_DWORD)this));
  vostok::buffer_vector<vostok::render::streamable_texture_info>::clear(
    v18,
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)((char *)&dword_96154 + (_DWORD)this));
  v19 = *(boost::function1<void,vostok::sound::create_sound_propagator_params const &> **)((char *)&loc_90148
                                                                                         + (_DWORD)this);
  *(_DWORD *)((char *)&loc_90148 + (_DWORD)this + 4) = v19;
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v19,
    (int *)&this->m_streaming_texture_instance_allocator);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->next_scene);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
