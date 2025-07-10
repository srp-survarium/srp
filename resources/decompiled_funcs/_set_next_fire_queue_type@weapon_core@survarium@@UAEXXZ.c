void __thiscall survarium::weapon_core::set_next_fire_queue_type(survarium::weapon_core *this)
{
  if ( this->m_fire_queue_type == this->m_weapon_fire_queue_types_count - 1 )
    this->m_fire_queue_type = 0;
  else
    ++this->m_fire_queue_type;
}
