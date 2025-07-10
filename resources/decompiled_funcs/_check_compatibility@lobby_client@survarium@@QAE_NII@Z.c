char __userpurge survarium::lobby_client::check_compatibility@<al>(
        survarium::lobby_client *this@<eax>,
        const unsigned int first_item_id@<edi>,
        unsigned int second_item_id)
{
  unsigned int m_items_compatibilities_count; // esi
  int v4; // ecx
  survarium::items_compatibility *i; // eax
  int first_item_dict_id; // edx

  m_items_compatibilities_count = this->m_items_compatibilities_count;
  v4 = 0;
  if ( !m_items_compatibilities_count )
    return 0;
  for ( i = this->m_items_compatibility; ; ++i )
  {
    first_item_dict_id = i->first_item_dict_id;
    if ( first_item_dict_id == first_item_id && i->second_item_dict_id == second_item_id )
      break;
    if ( first_item_dict_id == second_item_id && i->second_item_dict_id == first_item_id )
      break;
    if ( ++v4 >= m_items_compatibilities_count )
      return 0;
  }
  return 1;
}
