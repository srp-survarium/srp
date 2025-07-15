void __thiscall survarium::weapon_core::set_next_fire_queue_type(survarium::weapon_core *this)
{
  unsigned __int8 m_weapon_fire_queue_types_count; // cl
  unsigned __int8 m_fire_queue_type; // dl
  survarium::weapon_core *v4; // ecx

  m_weapon_fire_queue_types_count = this->m_weapon_fire_queue_types_count;
  if ( m_weapon_fire_queue_types_count != 1 )
  {
    m_fire_queue_type = this->m_fire_queue_type;
    v4 = (survarium::weapon_core *)(m_weapon_fire_queue_types_count - 1);
    if ( (survarium::weapon_core *)m_fire_queue_type == v4 )
      this->m_fire_queue_type = 0;
    else
      this->m_fire_queue_type = m_fire_queue_type + 1;
    survarium::weapon_core::reset_fire_queue(v4, (int)this);
  }
}
