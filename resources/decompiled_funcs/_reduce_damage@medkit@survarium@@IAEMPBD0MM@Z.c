double __thiscall survarium::medkit::reduce_damage(
        survarium::medkit *this,
        const char *body_part_name,
        const char *damage_type,
        float amount,
        float armor_piercing)
{
  const survarium::medkit::damage_protection *dmgp; // [esp+4h] [ebp-4h]

  dmgp = survarium::medkit::find_damage_protection(this, body_part_name, damage_type);
  if ( !dmgp )
    return amount;
  if ( dmgp->threshold <= amount )
    return (amount - dmgp->threshold) * dmgp->hit_coeff;
  return 0.0;
}
