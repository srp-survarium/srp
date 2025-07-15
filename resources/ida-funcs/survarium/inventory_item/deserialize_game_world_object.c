void __thiscall survarium::inventory_item::deserialize_game_world_object(
        survarium::inventory_item *this,
        vostok::network_core::packet_reader *reader)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)reader->m_pointer);
  JUMPOUT(0xAB263);
}
