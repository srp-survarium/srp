unsigned __int8 __thiscall survarium::damage_model::get_total_health(survarium::damage_model *this)
{
  survarium::body_part_parameters *it_body_part; // [esp+4h] [ebp-8h]
  unsigned __int8 result_value; // [esp+Bh] [ebp-1h]

  result_value = 100;
  for ( it_body_part = this->m_body_parts.m_first; it_body_part; it_body_part = it_body_part->next )
  {
    if ( survarium::body_part_parameters::can_affect_death(it_body_part) )
    {
      if ( (unsigned __int8)survarium::body_part_parameters::get_health_in_percentage(it_body_part) < (int)result_value )
        result_value = survarium::body_part_parameters::get_health_in_percentage(it_body_part);
    }
  }
  return result_value;
}
