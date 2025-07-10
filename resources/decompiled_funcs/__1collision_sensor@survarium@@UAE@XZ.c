void __thiscall survarium::collision_sensor::~collision_sensor(survarium::collision_sensor *this)
{
  vostok::memory::doug_lea_allocator *v1; // eax
  survarium::vector<vostok::resources::request> *v2; // ecx
  survarium::vector<vostok::resources::request> *p_m_collision_geometries; // [esp+20h] [ebp-Ch]

  this->survarium::collision_geometry_subscriber::__vftable = (survarium::collision_sensor_vtbl *)&survarium::collision_sensor::`vftable'{for `survarium::collision_geometry_subscriber'};
  this->survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::collision_sensor::`vftable'{for `survarium::link_resolver'};
  p_m_collision_geometries = (survarium::vector<vostok::resources::request> *)&this->m_collision_geometries;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( p_m_collision_geometries->_M_impl._M_start )
  {
    vostok::memory::doug_lea_allocator::free_impl(v1, (void *)p_m_collision_geometries->_M_impl._M_start);
    v2 = p_m_collision_geometries;
    p_m_collision_geometries->_M_impl._M_start = 0;
  }
  stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::~_Impl_vector<void *,survarium::std_allocator<void *>>(
    v2,
    (void **)&this->m_old_objects._M_impl._M_start);
  this->survarium::collision_geometry_subscriber::__vftable = (survarium::collision_sensor_vtbl *)&survarium::collision_geometry_subscriber::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->survarium::link_resolver);
}
