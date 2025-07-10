void __thiscall survarium::inventory::inventory(survarium::inventory *this)
{
  vostok::resources::unmanaged_resource::unmanaged_resource(this, 1u);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this->m_slots);
  this->__vftable = (survarium::inventory_vtbl *)&survarium::inventory::`vftable';
  `vector constructor iterator'(
    (char *)this->m_slots,
    4u,
    19,
    (void *(__thiscall *)(void *))survarium::inventory_slot::inventory_slot);
  this->m_active_slot = max_slots_count;
  this->m_holder = 0;
  this->m_victory_item = 0;
}
