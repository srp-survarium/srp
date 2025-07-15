void __thiscall survarium::medkit::set_inventory(
        survarium::medkit *this,
        survarium::inventory *inv,
        survarium::profile_slot_enum slot)
{
  survarium::items_dictionary_vtbl *m_dict_id; // ecx

  this->m_slot_id = slot;
  m_dict_id = (survarium::items_dictionary_vtbl *)this->m_dict_id;
  this->m_inventory = inv;
  this->m_add_stamina_regen.value = survarium::items_dictionary::item_by_id(inv->m_items_dictionary, m_dict_id)->modifiers[3];
}
