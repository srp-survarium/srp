char __thiscall survarium::items_dictionary::check_items_compatibility(
        survarium::items_dictionary *this,
        unsigned int first_item_dict_id,
        unsigned int second_item_dict_id)
{
  survarium::items_compatibility *M_start; // eax
  survarium::items_compatibility *M_finish; // ecx
  int v5; // edx

  M_start = this->m_item_compatibilities._M_impl._M_start;
  M_finish = this->m_item_compatibilities._M_impl._M_finish;
  while ( 1 )
  {
    if ( M_start == M_finish )
      return 0;
    v5 = M_start->first_item_dict_id;
    if ( v5 == first_item_dict_id && M_start->second_item_dict_id == second_item_dict_id )
      break;
    if ( v5 == second_item_dict_id && M_start->second_item_dict_id == first_item_dict_id )
      break;
    ++M_start;
  }
  return 1;
}
