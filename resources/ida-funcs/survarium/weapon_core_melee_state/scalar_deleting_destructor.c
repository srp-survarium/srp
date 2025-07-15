survarium::weapon_core_melee_state *__thiscall survarium::weapon_core_melee_state::`scalar deleting destructor'(
        survarium::weapon_core_melee_state *this,
        char a2)
{
  survarium::weapon_core_melee_state::~weapon_core_melee_state(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
