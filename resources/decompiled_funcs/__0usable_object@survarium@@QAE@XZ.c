void __thiscall survarium::usable_object::usable_object(survarium::usable_object *this)
{
  survarium::game_camera *v1; // ecx

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->survarium::link_resolver);
  this->survarium::collision_geometry_subscriber::__vftable = (survarium::usable_object_vtbl *)&survarium::collision_geometry_subscriber::`vftable';
  survarium::link_resolver::link_resolver((survarium::link_resolver *)this, &this->survarium::link_resolver::__vftable);
  this->survarium::collision_geometry_subscriber::__vftable = (survarium::usable_object_vtbl *)&survarium::usable_object::`vftable'{for `survarium::collision_geometry_subscriber'};
  this->survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::usable_object::`vftable'{for `survarium::link_resolver'};
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)&this->m_usable_object_users,
    &this->m_usable_object_users.m_size);
  survarium::weapon_user_dead_state::finalize(v1);
  this->m_usable_object_users.m_first = 0;
  this->m_usable_object_users.m_last = 0;
  this->m_collision_geometries = 0;
  this->m_collision_geometries_count = 0;
}
