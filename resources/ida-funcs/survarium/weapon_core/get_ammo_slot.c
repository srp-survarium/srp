survarium::profile_slot_enum __thiscall survarium::weapon_core::get_ammo_slot(
        survarium::weapon_core *this,
        survarium::ammo_id_enum slot_id)
{
  survarium::profile_slot_enum v3; // [esp+0h] [ebp-8h]

  v3 = survarium::inventory_item::profile_slot_id(&this->survarium::inventory_item, (int)this);
  if ( v3 == weapon1_slot )
    return weapon_ammo_slots[0][slot_id];
  if ( v3 == weapon2_slot )
    return dword_9BE634[slot_id];
  return 19;
}
