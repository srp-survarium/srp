survarium::weapon_core_cook *__thiscall vostok::particle::particle_system_cook::`vector deleting destructor'(
        survarium::weapon_core_cook *this,
        char a2)
{
  vostok::resources::unmanaged_cook::~unmanaged_cook((vostok::resources::unmanaged_cook *)this, this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
