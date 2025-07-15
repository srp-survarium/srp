void __thiscall survarium::messaging_client::on_connected(survarium::messaging_client *this)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  vostok::network_core::buffer_writer *v3; // ecx
  vostok::network_core::buffer_writer *v4; // ecx
  vostok::network_core::buffer_writer *v5; // ecx
  vostok::network::tcp_packet_client *v6; // ecx
  vostok::network_core::buffer_writer *v7; // ecx
  vostok::network_core::mutable_buffer *v8; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::messaging_client,vostok::network_core::buffer_reader &>,boost::_bi::list2<boost::_bi::value<survarium::messaging_client *>,boost::arg<1> > > v9; // [esp-8h] [ebp-68h]
  int v10; // [esp+0h] [ebp-60h]
  unsigned __int8 v11; // [esp+13h] [ebp-4Dh] BYREF
  unsigned int m_session_id; // [esp+14h] [ebp-4Ch] BYREF
  boost::function<void __cdecl(vostok::network_core::buffer_reader &)> v13; // [esp+18h] [ebp-48h] BYREF
  vostok::network_core::tcp_packet v14; // [esp+38h] [ebp-28h] BYREF

  v9.l_.a1_.t_ = this;
  v9.f_.f_ = survarium::messaging_client::sign_in_on_packet_received;
  this->m_connection_state = client_connecting;
  boost::function<void __cdecl (vostok::network_core::buffer_reader &)>::function<void __cdecl (vostok::network_core::buffer_reader &)>(
    (boost::function<void __cdecl(vostok::network_core::buffer_reader &)> *)this,
    (boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::messaging_client,vostok::network_core::buffer_reader &>,boost::_bi::list2<boost::_bi::value<survarium::messaging_client *>,boost::arg<1> > > *)&v13,
    v9,
    v10);
  boost::function<void __cdecl (boost::system::error_code)>::operator=(
    &v13,
    (boost::function1<void,vostok::physics::contact_point const &> *)&this->m_network_client);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v2,
    (int *)&v13);
  vostok::network_core::tcp_packet::tcp_packet(
    (vostok::network_core::tcp_packet *)&vostok::memory::g_mt_allocator,
    (int)&v14);
  v11 = -61;
  vostok::network_core::buffer_writer::w(v3, &v14.m_writer.serialization_operations_descriptors.m_size, &v11, 1u);
  m_session_id = this->m_game->m_network_client->login_client(this->m_game->m_network_client)->m_client->m_session_id;
  vostok::network_core::buffer_writer::w(
    v4,
    &v14.m_writer.serialization_operations_descriptors.m_size,
    (unsigned __int8 *)&m_session_id,
    4u);
  v11 = 5;
  vostok::network_core::buffer_writer::w(v5, &v14.m_writer.serialization_operations_descriptors.m_size, &v11, 1u);
  vostok::network::tcp_packet_client::send(v6, (const vostok::network_core::tcp_packet *)&this->m_network_client, &v14);
  vostok::network_core::buffer_writer::~buffer_writer(v7, &v14.m_writer.serialization_operations_descriptors);
  vostok::network_core::mutable_buffer::~mutable_buffer(v8, &v14);
}
