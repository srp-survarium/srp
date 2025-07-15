void __thiscall survarium::hittable_object::~hittable_object(survarium::hittable_object *this)
{
  survarium::game_camera *v1; // ecx

  this->__vftable = (survarium::hittable_object_vtbl *)&survarium::hittable_object::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v1);
  vostok::physics::destroy_static_rigid_body(this->m_rigid_body);
  survarium::hit_receiver::~hit_receiver(this);
}
