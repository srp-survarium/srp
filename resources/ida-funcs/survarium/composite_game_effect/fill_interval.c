int __thiscall survarium::composite_game_effect::fill_interval(
        survarium::composite_game_effect *this,
        const survarium::game_effect_interval_description *interval,
        survarium::single_game_effect **effects)
{
  int v4; // ebx
  unsigned int i; // edi
  survarium::game_effect *m_object; // ecx

  v4 = 0;
  for ( i = 0; i < this->m_effects_count; ++i )
  {
    m_object = this->m_effects[i].m_object;
    v4 += m_object->fill_interval(m_object, interval, &effects[v4]);
  }
  return v4;
}
