void __thiscall survarium::hittable_object::hittable_object(survarium::hittable_object *this)
{
  survarium::hit_receiver::hit_receiver(this, this);
  this->__vftable = (survarium::hittable_object_vtbl *)&survarium::hittable_object::`vftable';
  this->m_rigid_body = 0;
  this->m_physics_world = 0;
  this->m_group = 0;
  this->m_mask = 0;
}
