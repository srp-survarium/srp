void __thiscall survarium::booby_trap_core::~booby_trap_core(survarium::booby_trap_core *this)
{
  vostok::memory::doug_lea_allocator *v1; // eax
  survarium::game_camera *v2; // ecx
  vostok::memory::doug_lea_allocator *v3; // eax

  this->survarium::game_world_object::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (survarium::booby_trap_core_vtbl *)&survarium::booby_trap_core::`vftable'{for `survarium::game_world_object'};
  this->survarium::hittable_object::survarium::hit_receiver::vostok::collision::game_object::__vftable = (survarium::hittable_object_vtbl *)&survarium::booby_trap_core::`vftable'{for `survarium::hittable_object'};
  this->survarium::collision_sensor::survarium::collision_geometry_subscriber::__vftable = (survarium::collision_sensor_vtbl *)&survarium::booby_trap_core::`vftable'{for `survarium::collision_geometry_subscriber's `survarium::collision_sensor'};
  this->survarium::collision_sensor::survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::booby_trap_core::`vftable'{for `survarium::link_resolver's `survarium::collision_sensor'};
  this->survarium::usable_object::survarium::collision_geometry_subscriber::__vftable = (survarium::usable_object_vtbl *)&survarium::booby_trap_core::`vftable'{for `survarium::collision_geometry_subscriber's `survarium::usable_object'};
  this->survarium::usable_object::survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::booby_trap_core::`vftable'{for `survarium::link_resolver's `survarium::usable_object'};
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,survarium::collision_geometry>(
    this->survarium::usable_object::m_collision_geometries,
    v1);
  survarium::weapon_user_dead_state::finalize(v2);
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,survarium::collision_geometry>(
    this->survarium::collision_sensor::m_collision_geometries,
    v3);
  survarium::usable_object::~usable_object(&this->survarium::usable_object);
  survarium::collision_sensor::~collision_sensor(&this->survarium::collision_sensor);
  survarium::hittable_object::~hittable_object(&this->survarium::hittable_object);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&this->next);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
