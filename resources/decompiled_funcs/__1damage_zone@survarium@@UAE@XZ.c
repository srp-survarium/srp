void __thiscall survarium::damage_zone::~damage_zone(survarium::damage_zone *this)
{
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *M_start; // eax
  void *v3; // esi

  this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (survarium::damage_zone_vtbl *)&survarium::damage_zone::`vftable';
  this->survarium::damage_zone_core::survarium::collision_sensor::survarium::collision_geometry_subscriber::__vftable = (survarium::damage_zone_core_vtbl *)&survarium::damage_zone::`vftable'{for `survarium::collision_geometry_subscriber'};
  this->survarium::damage_zone_core::survarium::collision_sensor::survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::damage_zone::`vftable'{for `survarium::link_resolver'};
  this->survarium::damage_zone_core::survarium::hit_initiator::__vftable = (survarium::hit_initiator_vtbl *)&survarium::damage_zone::`vftable'{for `survarium::hit_initiator'};
  this->survarium::damage_zone_core::survarium::player_actions_subscriber::__vftable = (survarium::player_actions_subscriber_vtbl *)&survarium::damage_zone::`vftable'{for `survarium::player_actions_subscriber'};
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>(
    (stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>)this->m_particles._M_impl._M_finish,
    (stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>)this->m_particles._M_impl._M_start);
  M_start = this->m_particles._M_impl._M_start;
  if ( M_start )
  {
    v3 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v3, M_start);
  }
  survarium::damage_zone_core::~damage_zone_core(&this->survarium::damage_zone_core);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
