void __thiscall survarium::inventory_item::deserialize(
        survarium::inventory_item *this,
        vostok::network_core::packet_reader *reader)
{
  this->m_amount = vostok::network_core::packet_reader::r<unsigned short>(
                     (vostok::network_core::packet_reader *)this,
                     (int)reader);
}
