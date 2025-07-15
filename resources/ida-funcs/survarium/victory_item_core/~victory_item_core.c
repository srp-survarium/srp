void __thiscall survarium::victory_item_core::~victory_item_core(survarium::victory_item_core *this)
{
  vostok::ai::fsm *p_m_logic; // edi
  survarium::usable_object *v3; // ebx
  vostok::ai::fsm *v4; // ecx
  vostok::ai::fsm *i; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  vostok::ai::fsm *v7; // [esp-4h] [ebp-18h]
  const char *v8; // [esp+0h] [ebp-14h]
  const char *v9; // [esp+4h] [ebp-10h]
  unsigned int v10; // [esp+8h] [ebp-Ch]
  vostok::resources::unmanaged_resource *v11; // [esp+Ch] [ebp-8h]
  vostok::ai::fsm_state *pointer; // [esp+10h] [ebp-4h] BYREF

  v11 = &this->vostok::resources::unmanaged_resource;
  this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::victory_item_core::`vftable'{for `vostok::resources::unmanaged_resource'};
  p_m_logic = &this->m_logic;
  v3 = &this->survarium::usable_object;
  this->survarium::carryable_object::survarium::interactive_object::__vftable = (survarium::victory_item_core_vtbl *)&survarium::victory_item_core::`vftable'{for `survarium::carryable_object'};
  this->survarium::carryable_object::survarium::usable_object::survarium::collision_geometry_subscriber::__vftable = (survarium::usable_object_vtbl *)&survarium::victory_item_core::`vftable'{for `survarium::collision_geometry_subscriber'};
  this->survarium::carryable_object::survarium::usable_object::survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::victory_item_core::`vftable'{for `survarium::link_resolver'};
  this->survarium::spottable_object::__vftable = (survarium::spottable_object_vtbl *)&survarium::victory_item_core::`vftable'{for `survarium::spottable_object'};
  vostok::ai::fsm::clear_transitions((vostok::ai::fsm *)this, (int)&this->m_logic);
  for ( i = p_m_logic; ; i = &this->m_logic )
  {
    pointer = vostok::ai::fsm::pop_state(v4, i);
    if ( !pointer )
      break;
    vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
      survarium::g_allocator,
      &pointer,
      v8,
      v9,
      v10);
    v4 = v7;
  }
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,survarium::collision_geometry>(
    survarium::g_allocator,
    this->m_collision_geometries,
    v8,
    v9,
    v10);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_skeleton);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v6,
    (int *)&this->m_logic.m_on_transition);
  vostok::resources::unmanaged_resource::~unmanaged_resource(v11);
  survarium::usable_object::~usable_object(v3);
}
