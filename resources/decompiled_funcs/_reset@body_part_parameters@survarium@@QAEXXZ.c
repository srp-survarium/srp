void __thiscall survarium::body_part_parameters::reset(survarium::body_part_parameters *this)
{
  stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *i; // [esp+8h] [ebp-4h]

  this->m_health = this->m_max_health;
  this->m_last_hit_time = 0;
  for ( i = this->m_affects.m_begin; i != this->m_affects.m_end; ++i )
    ;
  this->m_affects.m_end = this->m_affects.m_begin;
}
