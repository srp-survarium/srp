void __thiscall survarium::portable_interactive_object::deserialize(
        survarium::portable_interactive_object *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader,
        unsigned int time_offset)
{
  vostok::animation::hand_to_weapon_ik_solver::ik_locator_id_enum m_default_ik_locator_id; // ecx
  bool *p_is_active; // eax

  survarium::portable_interactive_object_core::deserialize(this, reader, client_reader, time_offset);
  if ( client_reader )
  {
    vostok::animation::hand_to_weapon_ik_solver::deserialize(&this->m_hand_ik_solver, client_reader, time_offset);
  }
  else
  {
    m_default_ik_locator_id = this->m_default_ik_locator_id;
    if ( &this->m_hand_ik_solver != (vostok::animation::hand_to_weapon_ik_solver *)&this->m_hand_ik_solver.m_interpolator )
    {
      p_is_active = &this->m_hand_ik_solver.m_hands[0].is_active;
      do
      {
        *((_DWORD *)p_is_active - 6) = 0;
        *p_is_active = 1;
        *((_DWORD *)p_is_active - 2) = m_default_ik_locator_id;
        p_is_active += 628;
      }
      while ( p_is_active - 624 != (bool *)&this->m_hand_ik_solver.m_interpolator );
    }
  }
}
