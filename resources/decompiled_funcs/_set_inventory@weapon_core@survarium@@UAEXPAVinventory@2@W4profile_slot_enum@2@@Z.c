void __thiscall survarium::weapon_core::set_inventory(
        survarium::weapon_core *this,
        survarium::inventory *inv,
        survarium::profile_slot_enum slot)
{
  survarium::inventory_item::set_inventory(&this->survarium::inventory_item, inv, slot);
}
