void __thiscall vostok::network::send_order::~send_order(vostok::network::send_order *this)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  vostok::memory::base_allocator *allocator; // [esp-14h] [ebp-20h]
  vostok::network_core::tcp_packet *pointer; // [esp+8h] [ebp-4h] BYREF

  pointer = (vostok::network_core::tcp_packet *)this->m_packet;
  allocator = this->allocator;
  this->__vftable = (vostok::network::send_order_vtbl *)&vostok::network::send_order::`vftable';
  vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::network_core::tcp_packet const>(
    allocator,
    (vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> **)&pointer,
    "vostok::network::send_order::~send_order",
    "c:\\survarium.deploy\\sources\\vostok\\network\\sources\\send_order.h",
    0x28u);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v2,
    (int *)&this->m_sender);
  this->__vftable = (vostok::network::send_order_vtbl *)&vostok::network::order::`vftable';
}
