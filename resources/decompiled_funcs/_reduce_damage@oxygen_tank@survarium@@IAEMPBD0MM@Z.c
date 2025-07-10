double __thiscall survarium::oxygen_tank::reduce_damage(
        survarium::oxygen_tank *this,
        const char *body_part_name,
        const char *damage_type,
        float amount,
        float armor_piercing)
{
  const survarium::oxygen_tank::item_influence *infl; // [esp+4h] [ebp-4h]

  infl = survarium::oxygen_tank::find_influence(this, body_part_name, damage_type);
  if ( !infl )
    return amount;
  if ( infl->threshold <= amount )
    return (amount - infl->threshold) * infl->hit_coeff;
  return 0.0;
}
