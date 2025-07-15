const survarium::oxygen_tank::item_influence *__thiscall survarium::oxygen_tank::find_influence(
        survarium::oxygen_tank *this,
        const char *body_part_name,
        const char *hit_type)
{
  const survarium::oxygen_tank::item_influence *infl; // [esp+8h] [ebp-8h]
  unsigned int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < this->m_influences_count; ++i )
  {
    infl = &this->m_influences[i];
    if ( vostok::strings::equal(infl->body_part_name, body_part_name)
      && vostok::strings::equal(infl->hit_type, hit_type) )
    {
      return infl;
    }
  }
  return 0;
}
