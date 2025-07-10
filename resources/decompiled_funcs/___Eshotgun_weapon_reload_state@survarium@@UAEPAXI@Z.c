survarium::shotgun_weapon_reload_state *__thiscall survarium::shotgun_weapon_reload_state::`vector deleting destructor'(
        survarium::shotgun_weapon_reload_state *this,
        char a2)
{
  survarium::shotgun_weapon_reload_state::~shotgun_weapon_reload_state(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
