void __thiscall survarium::medkit::deserialize(
        survarium::weapon_ammunition *this,
        vostok::network_core::packet_reader *reader)
{
  survarium::inventory_item::deserialize(this, reader);
}
