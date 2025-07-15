void __thiscall survarium::weapon_core::set_inventory(
        survarium::weapon_core *this,
        survarium::inventory *inv,
        survarium::profile_slot_enum slot)
{
  this->survarium::inventory_item::vostok::resources::unmanaged_resource::m_flags.survarium::inventory_item::vostok::resources::unmanaged_resource::m_flags = (unsigned int)inv;
  *(_DWORD *)&this->m_inlined_in_fat = slot;
  this->m_aim_progress.m_start_value = survarium::items_dictionary::item_by_id(
                                         *(survarium::items_dictionary **)(this->survarium::inventory_item::vostok::resources::unmanaged_resource::m_flags.survarium::inventory_item::vostok::resources::unmanaged_resource::m_flags
                                                                         + 268),
                                         (survarium::items_dictionary_vtbl *)HIWORD(this->survarium::inventory_item::m_game_world_core))->modifiers[4];
}
