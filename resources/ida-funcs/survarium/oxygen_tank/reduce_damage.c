void __thiscall survarium::oxygen_tank::reduce_damage(
        survarium::oxygen_tank *this,
        char *body_part_name,
        survarium::hit_type_enum damage_type,
        float *amount,
        float *armor_piercing)
{
  unsigned int m_influences_count; // edi
  unsigned int v6; // ebx
  survarium::oxygen_tank::item_influence *m_influences; // esi
  float threshold; // xmm1_4
  float v9; // xmm0_4

  m_influences_count = this->m_influences_count;
  v6 = 0;
  if ( this->m_influences_count )
  {
    m_influences = this->m_influences;
    while ( vostok::strings::compare(m_influences->body_part_name, body_part_name)
         || m_influences->hit_type != damage_type )
    {
      ++v6;
      ++m_influences;
      if ( v6 >= m_influences_count )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    m_influences = 0;
  }
  if ( m_influences )
  {
    threshold = m_influences->threshold;
    if ( threshold <= *amount )
      v9 = (float)(*amount - threshold) * m_influences->hit_coeff;
    else
      v9 = 0.0;
    *amount = v9;
  }
}
