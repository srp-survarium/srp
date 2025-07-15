void __thiscall survarium::collision_geometry::~collision_geometry(survarium::collision_geometry *this)
{
  vostok::physics::bt_ghost_object *m_ghost_object; // [esp-4h] [ebp-8h]

  m_ghost_object = this->m_ghost_object;
  this->__vftable = (survarium::collision_geometry_vtbl *)&survarium::collision_geometry::`vftable';
  vostok::physics::destroy_ghost_object(m_ghost_object);
  stlp_std::priv::_Vector_base<void *,stlp_std::allocator<void *>>::~_Vector_base<void *,stlp_std::allocator<void *>>(&this->m_subscribers._M_impl);
}
