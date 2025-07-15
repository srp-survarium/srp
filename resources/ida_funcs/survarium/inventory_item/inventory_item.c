void __thiscall survarium::inventory_item::inventory_item(
        survarium::inventory_item *this,
        survarium::inventory_item::action_behaviour_type type)
{
  survarium::interactive_object::interactive_object(this, this);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_action_behaviuor);
  this->__vftable = (survarium::inventory_item_vtbl *)&survarium::inventory_item::`vftable';
  this->m_action_behaviuor = type;
  this->m_inventory = 0;
  this->m_slot_id = max_slots_count;
  this->m_amount = 0;
  this->m_dict_id = 0;
}
