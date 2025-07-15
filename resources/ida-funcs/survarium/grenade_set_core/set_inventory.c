void __thiscall survarium::grenade_set_core::set_inventory(
        survarium::grenade_set_core *this,
        survarium::inventory *inv,
        survarium::profile_slot_enum slot)
{
  this->m_inventory = inv;
  this->m_slot_id = slot;
  inv->m_grenade_slot = slot;
  this->m_explosive.item_dict_id = this->m_dict_id;
}
