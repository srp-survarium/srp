void __thiscall vostok::animation::hand_to_weapon_ik_solver::hand::hand(
        vostok::animation::hand_to_weapon_ik_solver::hand *this)
{
  int v2; // edx
  unsigned __int16 *p_m_bone; // ecx

  v2 = 5;
  p_m_bone = &this->locators[0][0].m_bone;
  do
  {
    *p_m_bone = -1;
    p_m_bone += 50;
    --v2;
  }
  while ( v2 >= 0 );
  this->start_transition_time_in_ms = 0;
  this->hand_bone_index = -1;
  this->hand_matrix_index = -1;
  this->index_of_ik_bone_in_weapon = -1;
  this->locator_id = ik_locator_id_bone;
  this->previous_locator_id = ik_locator_id_count;
  this->is_active = 1;
}
