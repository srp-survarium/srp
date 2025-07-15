void __thiscall survarium::lobby_client::on_connected(survarium::lobby_client *this)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  vostok::network_core::buffer_writer *v3; // ecx
  vostok::network_core::buffer_writer *v4; // ecx
  vostok::network::tcp_packet_client *v5; // ecx
  vostok::network_core::buffer_writer *v6; // ecx
  vostok::network_core::mutable_buffer *v7; // ecx
  unsigned __int8 v8; // [esp+Fh] [ebp-51h] BYREF
  __int64 v9; // [esp+10h] [ebp-50h]
  boost::function<void __cdecl(vostok::network_core::buffer_reader &)> v10; // [esp+18h] [ebp-48h] BYREF
  vostok::network_core::tcp_packet v11; // [esp+38h] [ebp-28h] BYREF

  LODWORD(v9) = survarium::lobby_client::sign_in_on_packet_received;
  HIDWORD(v9) = this;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus((vostok::particle::particle_action *)this) )
  {
    v10.vtable = 0;
  }
  else
  {
    *(_QWORD *)&v10.functor.obj_ptr = v9;
    v10.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::network_core::buffer_reader &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::lobby_client,vostok::network_core::buffer_reader &>,boost::_bi::list2<boost::_bi::value<survarium::lobby_client *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                        + 1);
  }
  boost::function<void __cdecl (boost::system::error_code)>::operator=(
    &v10,
    (boost::function1<void,vostok::physics::contact_point const &> *)&this->m_packet_client);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v2,
    (int *)&v10);
  vostok::network_core::tcp_packet::tcp_packet(
    (vostok::network_core::tcp_packet *)&vostok::memory::g_mt_allocator,
    (int)&v11);
  v8 = 38;
  vostok::network_core::buffer_writer::w(v3, &v11.m_writer.serialization_operations_descriptors.m_size, &v8, 1u);
  vostok::network_core::buffer_writer::w(
    v4,
    &v11.m_writer.serialization_operations_descriptors.m_size,
    (unsigned __int8 *)&this->m_connection_info,
    4u);
  vostok::network::tcp_packet_client::send(v5, (const vostok::network_core::tcp_packet *)&this->m_packet_client, &v11);
  vostok::network_core::buffer_writer::~buffer_writer(v6, &v11.m_writer.serialization_operations_descriptors);
  vostok::network_core::mutable_buffer::~mutable_buffer(v7, &v11);
}
