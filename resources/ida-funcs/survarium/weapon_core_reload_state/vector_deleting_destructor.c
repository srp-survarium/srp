survarium::weapon_core_reload_state *__thiscall survarium::weapon_core_reload_state::`vector deleting destructor'(
        survarium::weapon_core_reload_state *this,
        char a2)
{
  survarium::weapon_core_reload_state::~weapon_core_reload_state(this, (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


survarium::weapon_core_reload_state *__thiscall survarium::weapon_core_reload_state::`vector deleting destructor'(
        char *this,
        char a2)
{
  return survarium::weapon_core_reload_state::`vector deleting destructor'(
           (survarium::weapon_core_reload_state *)(this - 24),
           a2);
}
