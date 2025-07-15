void __thiscall survarium::usable_object::~usable_object(survarium::usable_object *this)
{
  const char *v2; // [esp+0h] [ebp-Ch]
  const char *v3; // [esp+4h] [ebp-8h]
  unsigned int v4; // [esp+8h] [ebp-4h]

  this->survarium::collision_geometry_subscriber::__vftable = (survarium::usable_object_vtbl *)&survarium::usable_object::`vftable'{for `survarium::collision_geometry_subscriber'};
  this->survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::usable_object::`vftable'{for `survarium::link_resolver'};
  if ( this->m_collision_geometries )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)survarium::g_allocator,
      (char *)this->m_collision_geometries,
      v2,
      v3,
      v4);
    this->m_collision_geometries = 0;
  }
  this->m_deserialized_users.m_end = this->m_deserialized_users.m_begin;
  this->survarium::collision_geometry_subscriber::__vftable = (survarium::usable_object_vtbl *)&survarium::collision_geometry_subscriber::`vftable';
}
