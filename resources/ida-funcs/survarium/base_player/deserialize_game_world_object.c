void __thiscall survarium::base_player::deserialize_game_world_object(
        survarium::base_player *this,
        vostok::network_core::packet_reader *reader)
{
  survarium::game_camera *v2; // ecx
  boost::_bi::list4<enum vostok::connection_error_types_enum &,enum vostok::handshaking_error_types_enum &,enum vostok::socket_error_types_enum &,enum vostok::lobby_server_message_types_enum &> *v3; // ecx
  vostok::socket_error_types_enum *v4; // eax
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> *v5; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v6; // ecx
  const vostok::variant<32> **v7; // [esp+0h] [ebp-18h]
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> item; // [esp+10h] [ebp-8h] BYREF
  survarium::profile_slot_enum slot; // [esp+14h] [ebp-4h]

  slot = vostok::network_core::packet_reader::r<unsigned char>((vostok::network_core::packet_reader *)this, (int)reader);
  survarium::weapon_user_dead_state::finalize(v2);
  v4 = boost::_bi::list3<char const * &,enum survarium::hit_affects_type_enum &,enum survarium::affect_event_type_enum &>::operator[](
         v3,
         (int)this);
  v5 = survarium::inventory::item_in_slot((survarium::inventory *)slot, (int)v4);
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>(
    (vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v5,
    (survarium::inventory **)&item);
  v7 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v6, (int)&item);
  (*(void (__thiscall **)(const vostok::variant<32> **, vostok::network_core::packet_reader *))&(*v7)[2].m_storage[12])(
    v7,
    reader);
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&item);
}
