void __thiscall survarium::inventory_item::set_inventory(
        survarium::inventory_item *this,
        survarium::inventory *inv,
        survarium::profile_slot_enum slot)
{
  this->m_inventory = inv;
  this->m_slot_id = slot;
}
