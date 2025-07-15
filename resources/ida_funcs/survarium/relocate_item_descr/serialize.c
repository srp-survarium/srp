void __usercall survarium::relocate_item_descr::serialize(
        survarium::relocate_item_descr *this@<esi>,
        vostok::network_core::tcp_packet *packet@<eax>)
{
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v3; // ecx
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v4; // ecx
  vostok::network_core::packet<vostok::network_core::tcp_packet> *buffer; // [esp+4h] [ebp-4h] BYREF

  buffer = (vostok::network_core::packet<vostok::network_core::tcp_packet> *)this->profile_id;
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
    (vostok::network_core::packet<vostok::network_core::tcp_packet> *)&buffer,
    (int)packet,
    (unsigned __int8 *)&buffer,
    4u);
  buffer = (vostok::network_core::packet<vostok::network_core::tcp_packet> *)this->item_id;
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
    v3,
    (int)packet,
    (unsigned __int8 *)&buffer,
    4u);
  buffer = (vostok::network_core::packet<vostok::network_core::tcp_packet> *)this->item_dict_id;
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
    buffer,
    (int)packet,
    (unsigned __int8 *)&buffer,
    4u);
  buffer = (vostok::network_core::packet<vostok::network_core::tcp_packet> *)this->source_slot_id;
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
    (vostok::network_core::packet<vostok::network_core::tcp_packet> *)&buffer,
    (int)packet,
    (unsigned __int8 *)&buffer,
    4u);
  buffer = (vostok::network_core::packet<vostok::network_core::tcp_packet> *)this->target_slot_id;
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
    v4,
    (int)packet,
    (unsigned __int8 *)&buffer,
    4u);
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
    (vostok::network_core::packet<vostok::network_core::tcp_packet> *)this->amount,
    (int)packet,
    (unsigned __int8 *)&buffer,
    2u);
}
