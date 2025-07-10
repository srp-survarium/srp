int __thiscall survarium::body_part_parameters::get_health_in_percentage(survarium::body_part_parameters *this)
{
  return 100 * (unsigned __int8)(int)(float)(this->m_health / this->m_max_health);
}
