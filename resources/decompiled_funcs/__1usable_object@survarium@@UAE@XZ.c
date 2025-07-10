void __thiscall survarium::usable_object::~usable_object(survarium::usable_object *this)
{
  vostok::memory::doug_lea_allocator *v1; // eax
  survarium::game_camera *v2; // ecx
  survarium::game_camera *p_m_collision_geometries; // [esp+4h] [ebp-Ch]

  this->survarium::collision_geometry_subscriber::__vftable = (survarium::usable_object_vtbl *)&survarium::usable_object::`vftable'{for `survarium::collision_geometry_subscriber'};
  this->survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::usable_object::`vftable'{for `survarium::link_resolver'};
  p_m_collision_geometries = (survarium::game_camera *)&this->m_collision_geometries;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( p_m_collision_geometries->__vftable )
  {
    vostok::memory::doug_lea_allocator::free_impl(v1, p_m_collision_geometries->__vftable);
    v2 = p_m_collision_geometries;
    p_m_collision_geometries->__vftable = 0;
  }
  survarium::weapon_user_dead_state::finalize(v2);
  this->survarium::collision_geometry_subscriber::__vftable = (survarium::usable_object_vtbl *)&survarium::collision_geometry_subscriber::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->survarium::link_resolver);
}
