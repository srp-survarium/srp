void __thiscall survarium::body_part_parameters::set_parameters(
        survarium::body_part_parameters *this,
        float max_health,
        float regeneration_speed)
{
  this->m_max_health = max_health;
  this->m_regeneration_speed = regeneration_speed;
}
