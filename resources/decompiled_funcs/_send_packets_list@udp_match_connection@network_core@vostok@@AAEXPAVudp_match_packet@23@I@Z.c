void __thiscall vostok::network_core::udp_match_connection::send_packets_list(
        vostok::network_core::udp_match_connection *this,
        survarium::game_camera *packets_list,
        unsigned int packets_count)
{
  survarium::game_camera *v3; // ecx
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v4; // ecx
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v5; // ecx
  survarium::base_project::resolve_link_object *v6; // esi
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v7; // ecx
  survarium::base_project::resolve_link_object *v8; // eax
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v9; // ecx
  void *v10; // esp
  survarium::game_camera *v11; // ecx
  survarium::game_camera *v12; // eax
  survarium::game_camera *v13; // ecx
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v14; // ecx
  survarium::base_project::resolve_link_object *v15; // eax
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v16; // ecx
  survarium::base_project::resolve_link_object *v17; // eax
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v18; // ecx
  survarium::base_project::resolve_link_object *v19; // eax
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *bytes; // ecx
  survarium::base_project::resolve_link_object *v21; // eax
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v22; // ecx
  unsigned __int8 v23; // al
  survarium::base_project::resolve_link_object *v24; // eax
  _DWORD v25[2]; // [esp+0h] [ebp-84h] BYREF
  vostok::network_core::udp_match_connection *thisa; // [esp+8h] [ebp-7Ch]
  vostok::network_core::udp_match_packet **j; // [esp+Ch] [ebp-78h]
  void *buffer; // [esp+38h] [ebp-4Ch]
  survarium::game_camera *v29; // [esp+48h] [ebp-3Ch]
  char v30; // [esp+4Fh] [ebp-35h]
  vostok::network_core::sequence_number<unsigned short> *p_sequence_id; // [esp+50h] [ebp-34h]
  char *v32; // [esp+64h] [ebp-20h]
  char v33; // [esp+69h] [ebp-1Bh]
  char v34; // [esp+6Ah] [ebp-1Ah]
  char v35; // [esp+6Bh] [ebp-19h]
  vostok::network_core::udp_match_packet **e; // [esp+6Ch] [ebp-18h]
  vostok::network_core::udp_match_packet **packet; // [esp+70h] [ebp-14h]
  vostok::network_core::udp_match_packet *i; // [esp+74h] [ebp-10h] BYREF
  vostok::network_core::udp_match_packet *packet_to_send; // [esp+78h] [ebp-Ch]
  vostok::buffer_vector<vostok::network_core::udp_match_packet *> packets; // [esp+7Ch] [ebp-8h] BYREF

  thisa = this;
  v3 = (survarium::game_camera *)(packets_count + this->m_stats.sent.messages.count);
  thisa->m_stats.sent.messages.count = (unsigned int)v3;
  if ( LODWORD(packets_list->m_inverted_view_matrix.j.z) )
  {
    v34 = 0;
    survarium::weapon_user_dead_state::finalize(v3);
    packet_to_send = vostok::network_core::new_udp_match_packet(thisa->m_packets_allocator);
    *((_BYTE *)packet_to_send + 42) &= ~0x40u;
    p_sequence_id = &packet_to_send->sequence_id;
    packet_to_send->sequence_id.m_number = LOWORD(packets_list->m_inverted_view_matrix.lines[2].x);
    packet_to_send->m_buffer.elems[0] = 1;
    vostok::network_core::udp_match_connection::fill_packet_header(thisa, packet_to_send);
    v10 = alloca(4 * packets_count);
    v25[1] = v25;
    survarium::weapon_user_dead_state::finalize(v11);
    v29 = v12;
    packets.m_begin = (vostok::network_core::udp_match_packet **)v12;
    packets.m_end = (vostok::network_core::udp_match_packet **)v12;
    v30 = 0;
    survarium::weapon_user_dead_state::finalize(v12);
    v13 = packets_list;
    for ( i = (vostok::network_core::udp_match_packet *)packets_list; i; i = i->next )
    {
      v33 = 0;
      survarium::weapon_user_dead_state::finalize(v13);
      v15 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
              v14,
              (int)i);
      thisa->m_stats.sent.data_bytes += (unsigned int)v15;
      if ( i->send_count > 1u )
      {
        v16 = (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)thisa;
        ++thisa->m_stats.resent.packets.count;
        v17 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                v16,
                (int)i);
        thisa->m_stats.resent.packets.bytes += (unsigned int)&v17->config.data.pointer + 1;
        v18 = (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)thisa;
        ++thisa->m_stats.resent.messages.count;
        v19 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                v18,
                (int)i);
        bytes = (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)thisa->m_stats.resent.messages.bytes;
        thisa->m_stats.resent.messages.bytes = (unsigned int)&bytes->_M_start + (_DWORD)v19 + 1;
        v21 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                bytes,
                (int)i);
        thisa->m_stats.resent.data_bytes += (unsigned int)v21;
      }
      vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
        (vostok::buffer_vector<void const *> *)&packets,
        (const void **)&i);
      v23 = (unsigned __int8)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                               v22,
                               (int)i);
      vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet_to_send, v23);
      buffer = i->vostok::network_core::packet<vostok::network_core::udp_match_packet>::vostok::network_core::base_packet::m_buffer;
      v24 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
              (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)i,
              (int)i);
      vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(
        (unsigned int)v24,
        packet_to_send,
        (unsigned __int8 *)buffer);
    }
    vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
      (vostok::intrusive_list<vostok::ai::sensed_visual_object,vostok::ai::sensed_visual_object *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&thisa->m_outgoing_packets,
      (survarium::game_camera *)packet_to_send,
      0);
    vostok::network_core::udp_match_connection::send(thisa, packet_to_send);
    packet = packets.m_begin;
    e = packets.m_end;
    while ( packet != e )
    {
      if ( (*((_BYTE *)*packet + 42) & 0x40) != 0 )
        vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
          (vostok::intrusive_list<vostok::ai::sensed_visual_object,vostok::ai::sensed_visual_object *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&thisa->m_unacknowledged_packets,
          (survarium::game_camera *)*packet,
          0);
      else
        vostok::network_core::delete_udp_match_packet(
          thisa->m_packets_allocator,
          (vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::node **)packet);
      ++packet;
    }
    for ( j = packets.m_begin; j != packets.m_end; ++j )
      ;
  }
  else
  {
    v35 = 0;
    survarium::weapon_user_dead_state::finalize(v3);
    vostok::network_core::udp_match_connection::fill_packet_header(
      thisa,
      (vostok::network_core::udp_match_packet *)packets_list);
    thisa->m_stats.sent.data_bytes += (unsigned int)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                                                      v4,
                                                      (int)packets_list);
    if ( BYTE1(packets_list->m_inverted_view_matrix.lines[2].elements[1]) > 1u )
    {
      v5 = (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)thisa;
      ++thisa->m_stats.resent.packets.count;
      v6 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
             v5,
             (int)packets_list);
      v32 = (char *)v6
          + (unsigned __int8)vostok::network_core::udp_match_packet::header_size((vostok::network_core::udp_match_packet *)packets_list);
      thisa->m_stats.resent.packets.bytes += (unsigned int)(v32 + 46);
      v7 = (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)thisa;
      ++thisa->m_stats.resent.messages.count;
      v8 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
             v7,
             (int)packets_list);
      v9 = (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)thisa;
      thisa->m_stats.resent.messages.bytes += (unsigned int)v8;
      thisa->m_stats.resent.data_bytes += (unsigned int)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                                                          v9,
                                                          (int)packets_list);
    }
    vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
      (vostok::intrusive_list<vostok::ai::sensed_visual_object,vostok::ai::sensed_visual_object *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&thisa->m_outgoing_packets,
      packets_list,
      0);
    vostok::network_core::udp_match_connection::send(thisa, (vostok::network_core::udp_match_packet *)packets_list);
  }
}
