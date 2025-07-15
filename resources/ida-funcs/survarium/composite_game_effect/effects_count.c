int __thiscall survarium::composite_game_effect::effects_count(
        survarium::composite_game_effect *this,
        const survarium::game_effect_interval_description *interval)
{
  int v3; // ebx
  unsigned int i; // edi
  survarium::game_effect *m_object; // ecx

  v3 = 0;
  for ( i = 0; i < this->m_effects_count; ++i )
  {
    m_object = this->m_effects[i].m_object;
    v3 += m_object->effects_count(m_object, interval);
  }
  return v3;
}
