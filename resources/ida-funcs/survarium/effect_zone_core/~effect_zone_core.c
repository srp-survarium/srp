void __thiscall survarium::effect_zone_core::~effect_zone_core(survarium::effect_zone_core *this)
{
  this->survarium::collision_sensor::survarium::collision_geometry_subscriber::__vftable = (survarium::effect_zone_core_vtbl *)&survarium::effect_zone_core::`vftable'{for `survarium::collision_geometry_subscriber'};
  this->survarium::collision_sensor::survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::effect_zone_core::`vftable'{for `survarium::link_resolver'};
  this->survarium::tickable_object::__vftable = (survarium::tickable_object_vtbl *)&survarium::effect_zone_core::`vftable'{for `survarium::tickable_object'};
  this->survarium::serializable_object::__vftable = (survarium::serializable_object_vtbl *)&survarium::effect_zone_core::`vftable'{for `survarium::serializable_object'};
  survarium::collision_sensor::~collision_sensor(this);
}
