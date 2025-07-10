survarium::pistol_weapon_core_hide_state *__thiscall survarium::pistol_weapon_core_show_state::`vector deleting destructor'(
        survarium::pistol_weapon_core_hide_state *this,
        char a2)
{
  survarium::double_barreled_weapon_core_aimed_fire_state::~double_barreled_weapon_core_aimed_fire_state(
    (survarium::pistol_weapon_core_show_state *)this,
    (survarium::pistol_weapon_core_show_state *)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
