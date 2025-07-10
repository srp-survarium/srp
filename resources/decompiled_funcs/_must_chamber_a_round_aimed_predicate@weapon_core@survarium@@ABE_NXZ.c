bool __thiscall survarium::weapon_core::must_chamber_a_round_aimed_predicate(survarium::weapon_core *this)
{
  return survarium::weapon_core::must_chamber_a_round_predicate(this) && survarium::weapon_core::is_trying_to_aim(this);
}
