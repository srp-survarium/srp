void __cdecl survarium::call_item_deserialize(
        survarium::inventory_slot *slot,
        vostok::network_core::packet_reader *reader)
{
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v2; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  const vostok::variant<32> **v4; // eax
  survarium::inventory_item *v5; // ecx
  const survarium::profile_slot_enum *v6; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v7; // ecx
  const vostok::variant<32> **v8; // eax
  survarium::collision_geometry_subscriber *__val; // [esp+8h] [ebp-Ch] BYREF
  const survarium::profile_slot_enum *ignored_slots_start; // [esp+Ch] [ebp-8h]
  const survarium::profile_slot_enum *ignored_slots_end; // [esp+10h] [ebp-4h]

  ignored_slots_start = ignored_slots_for_serialization;
  ignored_slots_end = (const survarium::profile_slot_enum *)player_templates_84;
  if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator survarium::inventory_item * (__thiscall vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::*)(void)const(
         v2,
         slot) )
  {
    v4 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v3, (int)slot);
    __val = (survarium::collision_geometry_subscriber *)survarium::inventory_item::profile_slot_id(v5, (int)v4);
    v6 = (const survarium::profile_slot_enum *)stlp_std::find<vostok::physics::base_physics_object * const *,vostok::physics::base_physics_object *>(
                                                 (survarium::collision_geometry_subscriber **)ignored_slots_start,
                                                 (survarium::collision_geometry_subscriber **)ignored_slots_end,
                                                 &__val);
    if ( v6 == ignored_slots_end )
    {
      v8 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v7, (int)slot);
      (*(void (__thiscall **)(const vostok::variant<32> **, vostok::network_core::packet_reader *))&(*v8)[1].m_storage[20])(
        v8,
        reader);
    }
  }
}
