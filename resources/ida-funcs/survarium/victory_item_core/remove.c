void __thiscall survarium::victory_item_core::remove(survarium::victory_item_core *this)
{
  bool *p_m_collision_is_inserted; // esi

  p_m_collision_is_inserted = &this->m_collision_is_inserted;
  if ( this->m_collision_is_inserted )
  {
    survarium::usable_object::remove((survarium::usable_object *)this, &this->survarium::usable_object);
    *p_m_collision_is_inserted = 0;
  }
}
