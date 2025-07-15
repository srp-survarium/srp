void __thiscall survarium::inventory::remove(survarium::inventory *this)
{
  survarium::inventory_slot *slot; // [esp+4h] [ebp-4h]

  for ( slot = this->m_slots; slot != (survarium::inventory_slot *)&this->m_active_slot; ++slot )
    survarium::call_item_remove(slot);
  this->m_active_slot = max_slots_count;
}
