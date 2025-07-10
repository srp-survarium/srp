const survarium::medkit::damage_protection *__thiscall survarium::medkit::find_damage_protection(
        survarium::medkit *this,
        const char *body_part_name,
        const char *hit_type)
{
  const survarium::medkit::damage_protection *dmgp; // [esp+8h] [ebp-8h]
  unsigned int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < this->m_damage_protect_count; ++i )
  {
    dmgp = &this->m_damage_protect[i];
    if ( vostok::strings::equal(dmgp->body_part_name, body_part_name)
      && vostok::strings::equal(dmgp->hit_type, hit_type) )
    {
      return dmgp;
    }
  }
  return 0;
}
