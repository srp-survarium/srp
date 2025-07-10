vostok::network_core::udp_match_packet *__thiscall vostok::network::match_client_impl::clone_packet(
        vostok::network::match_client_impl *this,
        vostok::network_core::udp_match_packet *packet)
{
  _BYTE *v2; // eax
  vostok::network_core::packet_reader *v3; // ecx
  unsigned int v4; // esi
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v5; // ecx
  unsigned __int8 *v6; // eax
  vostok::network_core::udp_match_packet *result; // [esp+28h] [ebp-Ch]
  vostok::network_core::packet_reader reader; // [esp+2Ch] [ebp-8h] BYREF

  result = vostok::network_core::new_udp_match_packet((vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy> *)((char *)this + (_DWORD)&loc_257FFD + 3));
  reader.m_packet = packet;
  reader.m_pointer = (const unsigned __int8 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)packet,
                                                (int)packet);
  result->message_type = packet->message_type;
  *((_BYTE *)result + 42) = *((_BYTE *)packet + 42) & 0x3F | *((_BYTE *)result + 42) & 0xC0;
  *((_BYTE *)result + 42) = (((*((_BYTE *)packet + 42) & 0x40) != 0) << 6) | *((_BYTE *)result + 42) & 0xBF;
  *((_BYTE *)result + 42) = (*((_BYTE *)packet + 42) >> 7 << 7) | *((_BYTE *)result + 42) & 0x7F;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)result);
  LOBYTE(v3) = *v2;
  result->m_buffer.elems[0] = *v2;
  v4 = vostok::network_core::packet_reader::size_to_eof(v3, &reader);
  v6 = (unsigned __int8 *)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                            v5,
                            (int)&reader);
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(v4, result, v6);
  return result;
}
