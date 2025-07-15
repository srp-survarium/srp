void __thiscall survarium::medkit::reduce_damage(
        survarium::medkit *this,
        char *body_part_name,
        survarium::hit_type_enum damage_type,
        float *amount,
        float *armor_piercing)
{
  unsigned int m_damage_protect_count; // edi
  unsigned int v6; // ebx
  survarium::medkit::damage_protection *m_damage_protect; // esi
  float threshold; // xmm1_4
  float v9; // xmm0_4

  m_damage_protect_count = this->m_damage_protect_count;
  v6 = 0;
  if ( this->m_damage_protect_count )
  {
    m_damage_protect = this->m_damage_protect;
    while ( vostok::strings::compare(m_damage_protect->body_part_name, body_part_name)
         || m_damage_protect->hit_type != damage_type )
    {
      ++v6;
      ++m_damage_protect;
      if ( v6 >= m_damage_protect_count )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    m_damage_protect = 0;
  }
  if ( m_damage_protect )
  {
    threshold = m_damage_protect->threshold;
    if ( threshold <= *amount )
      v9 = (float)(*amount - threshold) * m_damage_protect->hit_coeff;
    else
      v9 = 0.0;
    *amount = v9;
  }
}
