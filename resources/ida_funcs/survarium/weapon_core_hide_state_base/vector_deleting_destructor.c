survarium::weapon_core_hide_state_base *__thiscall survarium::weapon_core_hide_state_base::`vector deleting destructor'(
        survarium::weapon_core_hide_state_base *this,
        char a2)
{
  survarium::weapon_core_chamber_a_round_aimed_state_base::~weapon_core_chamber_a_round_aimed_state_base(
    (survarium::weapon_core_show_state_base *)this,
    (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
