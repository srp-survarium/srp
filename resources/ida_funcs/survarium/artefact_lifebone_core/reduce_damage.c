double __thiscall survarium::artefact_lifebone_core::reduce_damage(
        survarium::artefact_lifebone_core *this,
        const char *body_part_name,
        survarium::game_camera *damage_type,
        float amount,
        float armor_piercing)
{
  _BYTE *v5; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v5 )
    survarium::weapon_user_dead_state::finalize(damage_type);
  return amount;
}
