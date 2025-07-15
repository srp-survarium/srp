void __thiscall survarium::effect_zone::~effect_zone(survarium::effect_zone *this)
{
  survarium::effect_zone_core *v2; // ecx

  v2 = &this->survarium::effect_zone_core;
  this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (survarium::effect_zone_vtbl *)&survarium::effect_zone::`vftable'{for `vostok::resources::unmanaged_resource'};
  v2->survarium::collision_sensor::survarium::collision_geometry_subscriber::__vftable = (survarium::effect_zone_core_vtbl *)&survarium::effect_zone::`vftable'{for `survarium::collision_geometry_subscriber'};
  this->survarium::effect_zone_core::survarium::collision_sensor::survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::effect_zone::`vftable'{for `survarium::link_resolver'};
  this->survarium::effect_zone_core::survarium::tickable_object::__vftable = (survarium::tickable_object_vtbl *)&survarium::effect_zone::`vftable'{for `survarium::tickable_object'};
  this->survarium::effect_zone_core::survarium::serializable_object::__vftable = (survarium::serializable_object_vtbl *)&survarium::effect_zone::`vftable'{for `survarium::serializable_object'};
  this->survarium::drawable_object::__vftable = (survarium::drawable_object_vtbl *)&survarium::effect_zone::`vftable'{for `survarium::drawable_object'};
  survarium::effect_zone_core::~effect_zone_core(v2);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
