bool __thiscall survarium::weapon_core::must_chamber_a_round_aimed_and_animation_ended_predicate(
        survarium::weapon_core *this)
{
  return survarium::weapon_core::must_chamber_a_round_and_animation_ended_predicate(this)
      && survarium::weapon_core::is_trying_to_aim(this);
}
