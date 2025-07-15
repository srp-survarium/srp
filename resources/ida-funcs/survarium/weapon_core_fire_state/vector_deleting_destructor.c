survarium::weapon_core_fire_state *__thiscall survarium::weapon_core_fire_state::`vector deleting destructor'(
        survarium::weapon_core_fire_state *this,
        char a2)
{
  survarium::weapon_core_chamber_a_round_state::~weapon_core_chamber_a_round_state(
    (survarium::weapon_core_chamber_a_round_state *)this,
    (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
