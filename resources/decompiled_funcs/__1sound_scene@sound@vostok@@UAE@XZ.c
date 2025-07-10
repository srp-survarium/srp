void __thiscall vostok::sound::sound_scene::~sound_scene(vostok::sound::sound_scene *this)
{
  vostok::configs::binary_config **p_m_graph; // [esp+70h] [ebp-10h]
  vostok::configs::binary_config *m_object; // [esp+74h] [ebp-Ch]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v4; // [esp+78h] [ebp-8h] BYREF
  char v5; // [esp+7Eh] [ebp-2h]
  vostok::sound::receiver_unconditional_erasing_predicate pred; // [esp+7Fh] [ebp-1h] BYREF

  this->__vftable = (vostok::sound::sound_scene_vtbl *)&vostok::sound::sound_scene::`vftable';
  p_m_graph = (vostok::configs::binary_config **)&this->m_graph;
  v4.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v4,
    0);
  m_object = v4.m_object;
  v4.m_object = *p_m_graph;
  *p_m_graph = m_object;
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&v4);
  vostok::collision::delete_space_partitioning_tree(this->m_spatial_tree);
  if ( this->m_receivers.m_first )
  {
    vostok::intrusive_list<vostok::sound::receiver_collision,vostok::sound::receiver_collision *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::sound::receiver_unconditional_erasing_predicate>(
      &this->m_receivers,
      &pred);
    vostok::intrusive_list<vostok::sound::receiver_collision,vostok::sound::receiver_collision *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::clear(&this->m_receivers);
  }
  v5 = 0;
  vostok::threading::mutex_tasks_unaware::~mutex_tasks_unaware(&this->m_active_voices.m_mutex);
  vostok::threading::mutex_tasks_unaware::~mutex_tasks_unaware(&this->m_receivers.m_mutex);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&this->m_graph);
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_memory_arena_resources_ptr);
  stlp_std::priv::_Impl_vector<stlp_std::pair<vostok::fixed_string<64>,XAUDIO2FX_REVERB_I3DL2_PARAMETERS *>,vostok::vectora_allocator<stlp_std::pair<vostok::fixed_string<64>,XAUDIO2FX_REVERB_I3DL2_PARAMETERS *>>>::~_Impl_vector<stlp_std::pair<vostok::fixed_string<64>,XAUDIO2FX_REVERB_I3DL2_PARAMETERS *>,vostok::vectora_allocator<stlp_std::pair<vostok::fixed_string<64>,XAUDIO2FX_REVERB_I3DL2_PARAMETERS *>>>(&this->m_environment_parameters._M_impl);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
