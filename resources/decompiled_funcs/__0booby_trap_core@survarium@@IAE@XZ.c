void __thiscall survarium::booby_trap_core::booby_trap_core(survarium::booby_trap_core *this)
{
  vostok::resources::unmanaged_resource::unmanaged_resource(this, 1u);
  this->survarium::game_world_object::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (survarium::booby_trap_core_vtbl *)&survarium::game_world_object::`vftable';
  this->next.m_object = 0;
  survarium::hittable_object::hittable_object(&this->survarium::hittable_object);
  survarium::collision_sensor::collision_sensor(&this->survarium::collision_sensor);
  survarium::usable_object::usable_object(&this->survarium::usable_object);
  this->survarium::game_world_object::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (survarium::booby_trap_core_vtbl *)&survarium::booby_trap_core::`vftable'{for `survarium::game_world_object'};
  this->survarium::hittable_object::survarium::hit_receiver::vostok::collision::game_object::__vftable = (survarium::hittable_object_vtbl *)&survarium::booby_trap_core::`vftable'{for `survarium::hittable_object'};
  this->survarium::collision_sensor::survarium::collision_geometry_subscriber::__vftable = (survarium::collision_sensor_vtbl *)&survarium::booby_trap_core::`vftable'{for `survarium::collision_geometry_subscriber's `survarium::collision_sensor'};
  this->survarium::collision_sensor::survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::booby_trap_core::`vftable'{for `survarium::link_resolver's `survarium::collision_sensor'};
  this->survarium::usable_object::survarium::collision_geometry_subscriber::__vftable = (survarium::usable_object_vtbl *)&survarium::booby_trap_core::`vftable'{for `survarium::collision_geometry_subscriber's `survarium::usable_object'};
  this->survarium::usable_object::survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::booby_trap_core::`vftable'{for `survarium::link_resolver's `survarium::usable_object'};
  this->m_owner = 0;
  this->m_trap_state = booby_trap_state_removed;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_transform);
  this->m_state_timer = 0;
  vostok::math::float4x4::identity(&this->m_transform);
}
