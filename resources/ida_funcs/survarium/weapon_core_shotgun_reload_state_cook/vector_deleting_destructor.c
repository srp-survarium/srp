survarium::weapon_core_shotgun_reload_state_cook *__thiscall survarium::weapon_core_shotgun_reload_state_cook::`vector deleting destructor'(
        survarium::weapon_core_shotgun_reload_state_cook *this,
        char a2)
{
  survarium::weapon_core_shotgun_reload_state_cook::~weapon_core_shotgun_reload_state_cook(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
