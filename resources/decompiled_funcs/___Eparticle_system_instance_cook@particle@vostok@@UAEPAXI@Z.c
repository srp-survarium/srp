vostok::particle::particle_system_instance_cook *__thiscall vostok::particle::particle_system_instance_cook::`vector deleting destructor'(
        vostok::particle::particle_system_instance_cook *this,
        char a2)
{
  vostok::resources::unmanaged_cook *v2; // ecx

  this->__vftable = (vostok::particle::particle_system_instance_cook_vtbl *)&vostok::particle::particle_system_instance_cook::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this[1]);
  vostok::resources::unmanaged_cook::~unmanaged_cook(v2, this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
