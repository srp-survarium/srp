char __usercall survarium::lobby_client::can_move_item@<al>(
        survarium::lobby_client *this@<eax>,
        const unsigned int item_category_id@<edi>,
        const unsigned int target_slot_id@<esi>)
{
  unsigned int m_profile_slot_restrictions_count; // edx
  int v5; // ecx
  survarium::profile_slot_restriction *i; // eax

  if ( target_slot_id == 100 )
    return 1;
  m_profile_slot_restrictions_count = this->m_profile_slot_restrictions_count;
  v5 = 0;
  if ( !m_profile_slot_restrictions_count )
    return 0;
  for ( i = this->m_profile_slot_restrictions;
        i->slot_dict_id != target_slot_id || i->category_dict_id != item_category_id;
        ++i )
  {
    if ( ++v5 >= m_profile_slot_restrictions_count )
      return 0;
  }
  return 1;
}
