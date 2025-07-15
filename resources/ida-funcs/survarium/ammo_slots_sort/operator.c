BOOL __userpurge survarium::ammo_slots_sort::operator()@<eax>(
        survarium::ammo_slots_sort *this@<ecx>,
        const survarium::relocate_item_descr *first@<eax>,
        const survarium::relocate_item_descr *second)
{
  unsigned int v4; // ebx
  survarium::items_dictionary *m_dict; // edi
  char v6; // al
  unsigned int v7; // esi
  char v8; // bl
  char v9; // al
  unsigned int first_item_dict_id; // [esp+Ch] [ebp-8h]
  char v12; // [esp+10h] [ebp-4h]
  char v13; // [esp+11h] [ebp-3h]
  unsigned __int8 v14; // [esp+12h] [ebp-2h]
  unsigned __int8 v15; // [esp+13h] [ebp-1h]
  unsigned int item_dict_id; // [esp+1Ch] [ebp+8h]

  v4 = this->m_weapon_ids[0];
  m_dict = this->m_dict;
  v14 = 0;
  v15 = 0;
  first_item_dict_id = first->item_dict_id;
  v6 = survarium::items_dictionary::check_items_compatibility(this->m_dict, first_item_dict_id, v4);
  v7 = this->m_weapon_ids[1];
  v12 = v6;
  v13 = survarium::items_dictionary::check_items_compatibility(m_dict, first_item_dict_id, v7);
  item_dict_id = second->item_dict_id;
  v8 = survarium::items_dictionary::check_items_compatibility(m_dict, item_dict_id, v4);
  v9 = survarium::items_dictionary::check_items_compatibility(m_dict, item_dict_id, v7);
  if ( v12 )
  {
    if ( !v13 )
      goto LABEL_7;
    v14 = 1;
  }
  if ( v13 && !v12 )
    v14 = 2;
LABEL_7:
  if ( v8 )
  {
    if ( !v9 )
      return v14 < v15;
    v15 = 1;
  }
  if ( v9 && !v8 )
    v15 = 2;
  return v14 < v15;
}
