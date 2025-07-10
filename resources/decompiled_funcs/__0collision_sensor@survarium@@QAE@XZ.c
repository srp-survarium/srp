void __thiscall survarium::collision_sensor::collision_sensor(survarium::collision_sensor *this)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->survarium::link_resolver);
  this->survarium::collision_geometry_subscriber::__vftable = (survarium::collision_sensor_vtbl *)&survarium::collision_geometry_subscriber::`vftable';
  survarium::link_resolver::link_resolver((survarium::link_resolver *)this, &this->survarium::link_resolver::__vftable);
  this->survarium::collision_geometry_subscriber::__vftable = (survarium::collision_sensor_vtbl *)&survarium::collision_sensor::`vftable'{for `survarium::collision_geometry_subscriber'};
  this->survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::collision_sensor::`vftable'{for `survarium::link_resolver'};
  stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::_Impl_vector<void *,survarium::std_allocator<void *>>(
    (survarium::vector<vostok::resources::request> *)&this->m_old_objects,
    &this->m_old_objects._M_impl._M_start);
  this->m_collision_geometries = 0;
  this->m_collision_geometries_count = 0;
  this->m_is_active = 0;
}
