void __thiscall survarium::inventory_item::serialize_game_world_object_header(
        survarium::inventory_item *this,
        survarium::game_world_object *object,
        vostok::network_core::udp_match_packet *packet)
{
  _BYTE v3[272]; // [esp-110h] [ebp-244h] BYREF
  _BYTE v4[300]; // [esp+0h] [ebp-134h] BYREF

  qmemcpy(v4, packet, sizeof(v4));
  qmemcpy(v3, object, sizeof(v3));
  survarium::weapon_user_dead_state::finalize(0);
  JUMPOUT(0x96A26);
}
