void __thiscall survarium::hittable_object::~hittable_object(survarium::hittable_object *this)
{
  vostok::physics::bt_static_rigid_body *m_rigid_body; // esi

  m_rigid_body = this->m_rigid_body;
  this->__vftable = (survarium::hittable_object_vtbl *)&survarium::hittable_object::`vftable';
  vostok::physics::destroy_static_rigid_body(m_rigid_body);
  this->__vftable = (survarium::hittable_object_vtbl *)&survarium::hit_receiver::`vftable';
}
