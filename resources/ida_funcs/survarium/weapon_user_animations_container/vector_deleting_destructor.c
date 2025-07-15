survarium::weapon_user_animations_container *__thiscall survarium::weapon_user_animations_container::`vector deleting destructor'(
        survarium::weapon_user_animations_container *this,
        char a2)
{
  survarium::weapon_user_animations_container::~weapon_user_animations_container(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
