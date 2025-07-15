void __thiscall survarium::booby_trap_core::~booby_trap_core(survarium::booby_trap_core *this)
{
  survarium::collision_geometry **m_collision_geometries; // edi
  survarium::collision_sensor *v3; // ebx
  survarium::usable_object *v4; // ebp
  vostok::memory::doug_lea_allocator *v5; // [esp-4h] [ebp-14h]
  const char *v6; // [esp-4h] [ebp-14h]
  const char *v7; // [esp+0h] [ebp-10h]
  const char *v8; // [esp+0h] [ebp-10h]
  const char *v9; // [esp+4h] [ebp-Ch]
  unsigned int v10; // [esp+4h] [ebp-Ch]
  unsigned int v11; // [esp+8h] [ebp-8h]

  v5 = survarium::g_allocator;
  m_collision_geometries = this->survarium::usable_object::m_collision_geometries;
  v3 = &this->survarium::collision_sensor;
  v4 = &this->survarium::usable_object;
  this->survarium::hittable_object::survarium::hit_receiver::vostok::collision::game_object::__vftable = (survarium::booby_trap_core_vtbl *)&survarium::booby_trap_core::`vftable'{for `survarium::hittable_object'};
  this->survarium::collision_sensor::survarium::collision_geometry_subscriber::__vftable = (survarium::collision_sensor_vtbl *)&survarium::booby_trap_core::`vftable'{for `survarium::collision_geometry_subscriber's `survarium::collision_sensor'};
  this->survarium::collision_sensor::survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::booby_trap_core::`vftable'{for `survarium::link_resolver's `survarium::collision_sensor'};
  this->survarium::usable_object::survarium::collision_geometry_subscriber::__vftable = (survarium::usable_object_vtbl *)&survarium::booby_trap_core::`vftable'{for `survarium::collision_geometry_subscriber's `survarium::usable_object'};
  this->survarium::usable_object::survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::booby_trap_core::`vftable'{for `survarium::link_resolver's `survarium::usable_object'};
  this->survarium::tickable_object::__vftable = (survarium::tickable_object_vtbl *)&survarium::booby_trap_core::`vftable'{for `survarium::tickable_object'};
  this->survarium::serializable_object::__vftable = (survarium::serializable_object_vtbl *)&survarium::booby_trap_core::`vftable'{for `survarium::serializable_object'};
  this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::booby_trap_core::`vftable'{for `vostok::resources::unmanaged_resource'};
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,survarium::collision_geometry>(
    v5,
    m_collision_geometries,
    v7,
    v9,
    v11);
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,survarium::collision_geometry>(
    survarium::g_allocator,
    this->survarium::collision_sensor::m_collision_geometries,
    v6,
    v8,
    v10);
  vostok::resources::unmanaged_resource::~unmanaged_resource(&this->vostok::resources::unmanaged_resource);
  survarium::usable_object::~usable_object(v4);
  survarium::collision_sensor::~collision_sensor(v3);
  survarium::hittable_object::~hittable_object(this);
}
