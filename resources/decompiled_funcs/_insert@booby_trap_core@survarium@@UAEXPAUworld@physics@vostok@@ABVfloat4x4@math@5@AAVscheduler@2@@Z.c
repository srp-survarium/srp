void __thiscall survarium::booby_trap_core::insert(
        survarium::booby_trap_core *this,
        vostok::physics::world *world,
        const vostok::math::float4x4 *transform,
        survarium::scheduler *scheduler)
{
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  survarium::booby_trap_set_core *v6; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v4);
  this->set_transform(this, transform);
  this->register_tick(this, scheduler);
  survarium::weapon_user_dead_state::finalize(v5);
  survarium::collision_sensor::insert(&this->survarium::collision_sensor, world);
  survarium::usable_object::insert(&this->survarium::usable_object, world);
  if ( survarium::booby_trap_set_core::config(v6, (int)this->m_owner)->defuse_by_hit )
    survarium::hittable_object::insert(&this->survarium::hittable_object, world);
  this->switch_to_state(this, booby_trap_state_armed);
}
