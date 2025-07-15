void __cdecl survarium::call_item_serialize(
        survarium::inventory_slot *slot,
        vostok::network_core::udp_match_packet *packet,
        unsigned int client_offset)
{
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v3; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v4; // ecx
  const vostok::variant<32> **v5; // eax
  survarium::inventory_item *v6; // ecx
  const survarium::profile_slot_enum *v7; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v8; // ecx
  const vostok::variant<32> **v9; // [esp+0h] [ebp-14h]
  survarium::collision_geometry_subscriber *__val; // [esp+8h] [ebp-Ch] BYREF
  const survarium::profile_slot_enum *ignored_slots_start; // [esp+Ch] [ebp-8h]
  const survarium::profile_slot_enum *ignored_slots_end; // [esp+10h] [ebp-4h]

  ignored_slots_start = ignored_slots_for_serialization;
  ignored_slots_end = (const survarium::profile_slot_enum *)player_templates_84;
  if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator survarium::inventory_item * (__thiscall vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::*)(void)const(
         v3,
         slot) )
  {
    v5 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v4, (int)slot);
    __val = (survarium::collision_geometry_subscriber *)survarium::inventory_item::profile_slot_id(v6, (int)v5);
    v7 = (const survarium::profile_slot_enum *)stlp_std::find<vostok::physics::base_physics_object * const *,vostok::physics::base_physics_object *>(
                                                 (survarium::collision_geometry_subscriber **)ignored_slots_start,
                                                 (survarium::collision_geometry_subscriber **)ignored_slots_end,
                                                 &__val);
    if ( v7 == ignored_slots_end )
    {
      v9 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v8, (int)slot);
      (*(void (__thiscall **)(const vostok::variant<32> **, vostok::network_core::udp_match_packet *, unsigned int))&(*v9)[1].m_storage[16])(
        v9,
        packet,
        client_offset);
    }
  }
}
