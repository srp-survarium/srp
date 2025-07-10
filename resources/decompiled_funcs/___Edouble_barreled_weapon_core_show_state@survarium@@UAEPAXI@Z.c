survarium::double_barreled_weapon_core_hide_state *__thiscall survarium::double_barreled_weapon_core_show_state::`vector deleting destructor'(
        survarium::double_barreled_weapon_core_hide_state *this,
        char a2)
{
  survarium::double_barreled_weapon_core_hide_state::~double_barreled_weapon_core_hide_state(
    (survarium::double_barreled_weapon_core_show_state *)this,
    (survarium::double_barreled_weapon_core_show_state *)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
