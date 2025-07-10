void __thiscall vostok::network::match_client_impl::set_on_packet_received(
        vostok::network::match_client_impl *this,
        boost::function<void __cdecl(unsigned int,unsigned int)> *on_packet_received)
{
  boost::function<void __cdecl (unsigned char,vostok::network_core::packet_reader &)>::operator=(
    on_packet_received,
    (boost::function2<void,unsigned int,unsigned int> *)((char *)this + (_DWORD)&loc_258B7F + 1));
  if ( *(_DWORD *)&this->m_packets_storage.elems[0][(_DWORD)&loc_258B9D + 3] == 1 )
    boost::function<void __cdecl (unsigned char,vostok::network_core::packet_reader &)>::operator=(
      (boost::function<void __cdecl(unsigned int,unsigned int)> *)((char *)this + (_DWORD)&loc_258B7F + 1),
      (boost::function2<void,unsigned int,unsigned int> *)((char *)this + (_DWORD)&loc_25856F + 1));
}
