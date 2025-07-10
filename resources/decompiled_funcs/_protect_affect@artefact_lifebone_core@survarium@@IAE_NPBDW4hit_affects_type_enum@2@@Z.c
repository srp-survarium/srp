bool __thiscall survarium::artefact_lifebone_core::protect_affect(
        survarium::artefact_lifebone_core *this,
        const char *__formal,
        survarium::hit_affects_type_enum affect)
{
  return affect >= affects_type_hand_damage && affect <= affects_type_leg_damage;
}
