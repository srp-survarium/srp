survarium::pistol_weapon_core_fire_state *__thiscall survarium::double_barreled_weapon_core_reload_state::`vector deleting destructor'(
        survarium::pistol_weapon_core_fire_state *this,
        char a2)
{
  survarium::pistol_weapon_core_reload_state::~pistol_weapon_core_reload_state(
    (survarium::double_barreled_weapon_core_reload_state *)this,
    (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


survarium::pistol_weapon_core_fire_state *__thiscall survarium::double_barreled_weapon_core_reload_state::`vector deleting destructor'(
        char *this,
        char a2)
{
  return survarium::double_barreled_weapon_core_reload_state::`vector deleting destructor'(
           (survarium::pistol_weapon_core_fire_state *)(this - 24),
           a2);
}
