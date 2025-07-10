void __thiscall vostok::network_core::udp_match_connection::send_queued_packets(
        vostok::network_core::udp_match_connection *this,
        survarium::game_camera *current_time_in_ms)
{
  survarium::game_camera *m_state; // ecx
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // eax
  survarium::game_camera *v5; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v6; // ecx
  survarium::game_camera *v7; // eax
  void *v8; // esp
  survarium::game_camera *v9; // ecx
  vostok::network_core::udp_match_packet **v10; // eax
  survarium::game_camera *v11; // ecx
  survarium::game_camera *v12; // ecx
  survarium::game_camera *v13; // ecx
  survarium::game_camera *v14; // ecx
  survarium::game_camera *v15; // ecx
  unsigned __int8 v16; // al
  survarium::base_project::resolve_link_object *v17; // eax
  survarium::base_project::resolve_link_object *v18; // eax
  vostok::network_core::udp_match_packet *v19; // [esp-4h] [ebp-17Ch] BYREF
  int v20; // [esp+0h] [ebp-178h] BYREF
  vostok::ai::planning::action_parameter **matched; // [esp+4h] [ebp-174h]
  _BYTE *v22; // [esp+8h] [ebp-170h]
  int *v23; // [esp+Ch] [ebp-16Ch]
  survarium::game_camera *v24; // [esp+10h] [ebp-168h]
  vostok::network_core::udp_match_connection *thisa; // [esp+14h] [ebp-164h]
  vostok::network_core::udp_match_packet **j; // [esp+18h] [ebp-160h]
  vostok::network_core::udp_match_packet **__first; // [esp+60h] [ebp-118h]
  vostok::network_core::udp_match_packet **v28; // [esp+64h] [ebp-114h]
  vostok::network_core::udp_match_packet **v29; // [esp+68h] [ebp-110h]
  vostok::network_core::udp_match_packet **v30; // [esp+6Ch] [ebp-10Ch]
  stlp_std::priv::_STLP_alloc_proxy<survarium::base_project::resolve_link_object *,survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v31; // [esp+70h] [ebp-108h]
  unsigned __int16 *v32; // [esp+74h] [ebp-104h]
  stlp_std::priv::_STLP_alloc_proxy<survarium::base_project::resolve_link_object *,survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v33; // [esp+78h] [ebp-100h]
  stlp_std::priv::_STLP_alloc_proxy<survarium::base_project::resolve_link_object *,survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v34; // [esp+7Ch] [ebp-FCh]
  stlp_std::priv::_STLP_alloc_proxy<survarium::base_project::resolve_link_object *,survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v35; // [esp+80h] [ebp-F8h]
  stlp_std::priv::_STLP_alloc_proxy<survarium::base_project::resolve_link_object *,survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v36; // [esp+84h] [ebp-F4h]
  stlp_std::priv::_STLP_alloc_proxy<survarium::base_project::resolve_link_object *,survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v37; // [esp+88h] [ebp-F0h]
  stlp_std::priv::_STLP_alloc_proxy<survarium::base_project::resolve_link_object *,survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v38; // [esp+8Ch] [ebp-ECh]
  stlp_std::priv::_STLP_alloc_proxy<survarium::base_project::resolve_link_object *,survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v39; // [esp+90h] [ebp-E8h]
  stlp_std::priv::_STLP_alloc_proxy<survarium::base_project::resolve_link_object *,survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *p_M_end_of_storage; // [esp+94h] [ebp-E4h]
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v41; // [esp+98h] [ebp-E0h]
  vostok::network_core::udp_match_packet **m_end; // [esp+9Ch] [ebp-DCh]
  vostok::network_core::sequence_number<unsigned short> *v43; // [esp+A0h] [ebp-D8h]
  vostok::network_core::sequence_number<unsigned short> *p_m_local_sequence_id; // [esp+A4h] [ebp-D4h]
  char v45; // [esp+AAh] [ebp-CEh]
  char v46; // [esp+ABh] [ebp-CDh]
  vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy> *m_packets_allocator; // [esp+ACh] [ebp-CCh]
  void *pointer[4]; // [esp+B4h] [ebp-C4h] BYREF
  char v49; // [esp+C7h] [ebp-B1h]
  survarium::game_camera *p_sequence_id; // [esp+C8h] [ebp-B0h]
  vostok::network_core::udp_match_packet **v51; // [esp+E0h] [ebp-98h]
  char v52; // [esp+E7h] [ebp-91h]
  unsigned int m_max_packet_wait_time_in_ms; // [esp+108h] [ebp-70h]
  const char *m_logging_id; // [esp+10Ch] [ebp-6Ch]
  vostok::ai::planning::action_parameter **begin; // [esp+124h] [ebp-54h] BYREF
  vostok::ai::planning::action_parameter **end; // [esp+128h] [ebp-50h] BYREF
  char v57; // [esp+12Ch] [ebp-4Ch]
  char v58; // [esp+12Dh] [ebp-4Bh]
  char v59; // [esp+12Eh] [ebp-4Ah]
  char v60; // [esp+12Fh] [ebp-49h]
  vostok::network_core::move_to_list_predicate predicate; // [esp+130h] [ebp-48h] BYREF
  char v62; // [esp+141h] [ebp-37h]
  char v63; // [esp+142h] [ebp-36h]
  char v64; // [esp+143h] [ebp-35h]
  vostok::network_core::udp_match_packet **m_begin; // [esp+144h] [ebp-34h]
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v66; // [esp+148h] [ebp-30h]
  vostok::network_core::udp_match_packet **e; // [esp+14Ch] [ebp-2Ch]
  vostok::network_core::udp_match_packet **i; // [esp+150h] [ebp-28h]
  vostok::network_core::udp_match_packet *packets_list; // [esp+154h] [ebp-24h]
  unsigned int size_left; // [esp+158h] [ebp-20h]
  vostok::network_core::udp_match_packet *packet_list_tail; // [esp+15Ch] [ebp-1Ch]
  vostok::network_core::sequence_number<unsigned short> test; // [esp+160h] [ebp-18h] BYREF
  unsigned int v73; // [esp+164h] [ebp-14h]
  vostok::network_core::udp_match_packet *packet; // [esp+168h] [ebp-10h] BYREF
  vostok::buffer_vector<vostok::network_core::udp_match_packet *> packets; // [esp+16Ch] [ebp-Ch] BYREF
  unsigned int packets_count; // [esp+174h] [ebp-4h]

  thisa = this;
  vostok::threading::interlocked_exchange_pointer(&this->m_last_send_attempt_time_in_ms, (int)current_time_in_ms);
  m_state = (survarium::game_camera *)thisa->m_state;
  v24 = m_state;
  switch ( (unsigned int)m_state )
  {
    case 0u:
      if ( !thisa->m_last_receive_time_in_ms
        || thisa->m_disconnection_timeout_in_ms + thisa->m_last_receive_time_in_ms > (unsigned int)current_time_in_ms )
      {
        goto LABEL_11;
      }
      vostok::network_core::udp_match_connection::instant_disconnect(thisa, 0);
      return;
    case 1u:
      v64 = 0;
      survarium::weapon_user_dead_state::finalize(m_state);
      v63 = 0;
      survarium::weapon_user_dead_state::finalize(v3);
      v4 = (survarium::game_camera *)vostok::network_core::udp_match_connection::new_low_level_packet(thisa, 0);
      vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
        (vostok::intrusive_list<vostok::ai::sensed_visual_object,vostok::ai::sensed_visual_object *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&thisa->m_packets_to_send,
        v4,
        0);
      goto LABEL_11;
    case 2u:
      if ( thisa->m_max_packet_wait_time_in_ms + thisa->m_disconnection_receive_time_in_ms <= (unsigned int)current_time_in_ms )
      {
        vostok::network_core::udp_match_connection::instant_disconnect(
          thisa,
          (boost::function4<void,unsigned int,float,float,char const *> *)2);
        return;
      }
      v5 = (survarium::game_camera *)vostok::network_core::udp_match_connection::new_low_level_packet(thisa, 1u);
      vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
        (vostok::intrusive_list<vostok::ai::sensed_visual_object,vostok::ai::sensed_visual_object *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&thisa->m_packets_to_send,
        v5,
        0);
LABEL_11:
      m_max_packet_wait_time_in_ms = thisa->m_max_packet_wait_time_in_ms;
      m_logging_id = thisa->m_logging_id;
      survarium::weapon_core::cast_weapon_core((survarium::game_options *)&predicate);
      predicate.m_list_to_move_to = &thisa->m_packets_to_send;
      predicate.m_logging_id = m_logging_id;
      predicate.m_current_time_in_ms = (const unsigned int)current_time_in_ms;
      predicate.m_max_time_delta = m_max_packet_wait_time_in_ms;
      vostok::intrusive_list<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_packet *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::remove_if<vostok::network_core::move_to_list_predicate>(
        &thisa->m_unacknowledged_packets,
        (vostok::size_policy *)&predicate);
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&predicate);
      packets_count = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                      v6,
                                      (int)&thisa->m_packets_to_send);
      if ( packets_count )
        goto LABEL_14;
      if ( (unsigned int)current_time_in_ms < thisa->m_max_idle_time_in_ms + thisa->m_last_send_time_in_ms )
        return;
      v7 = (survarium::game_camera *)vostok::network_core::udp_match_connection::new_low_level_packet(thisa, 2u);
      vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
        (vostok::intrusive_list<vostok::ai::sensed_visual_object,vostok::ai::sensed_visual_object *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&thisa->m_packets_to_send,
        v7,
        0);
      packets_count = 1;
LABEL_14:
      vostok::network_core::udp_match_connection::dump(
        thisa,
        &stru_984D24.m_working_macro_list.m_buffer[4].m_store[476],
        current_time_in_ms);
      v8 = alloca(4 * packets_count);
      v23 = &v20;
      survarium::weapon_user_dead_state::finalize(v9);
      v51 = v10;
      packets.m_begin = v10;
      packets.m_end = v10;
      v52 = 0;
      survarium::weapon_user_dead_state::finalize(v11);
      while ( thisa->m_packets_to_send.m_first )
      {
        packet = (vostok::network_core::udp_match_packet *)vostok::intrusive_list<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_packet *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::pop_front((vostok::intrusive_list<vostok::ai::sensed_visual_object,vostok::ai::sensed_visual_object *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&thisa->m_packets_to_send);
        packet->next = 0;
        p_sequence_id = (survarium::game_camera *)&packet->sequence_id;
        v12 = (survarium::game_camera *)&packet->sequence_id;
        packet->sequence_id.m_number = thisa->m_local_sequence_id.m_number;
        v49 = 0;
        survarium::weapon_user_dead_state::finalize(v12);
        vostok::buffer_vector<void const *>::construct((const void **)packets.m_end++, (const void **)&packet);
      }
      v60 = 0;
      pointer[3] = packets.m_end;
      stlp_std::sort<vostok::network_core::udp_match_packet * *,packets_predicate>(packets.m_begin, packets.m_end, 0);
      break;
    case 3u:
      v62 = 0;
      survarium::weapon_user_dead_state::finalize(m_state);
      goto LABEL_11;
  }
  while ( packets.m_begin != packets.m_end )
  {
    test.m_number = thisa->m_local_sequence_id.m_number;
    ++test.m_number;
    if ( vostok::network_core::sequence_number<unsigned short>::operator<=(&test, &thisa->m_received_local_sequence_id) )
    {
      i = packets.m_begin;
      e = packets.m_end;
      while ( i != e )
      {
        if ( (*((_BYTE *)*i + 42) & 0x40) != 0 )
        {
          vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
            (vostok::intrusive_list<vostok::ai::sensed_visual_object,vostok::ai::sensed_visual_object *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&thisa->m_packets_to_send,
            (survarium::game_camera *)*i,
            0);
        }
        else
        {
          m_packets_allocator = thisa->m_packets_allocator;
          v19 = *i;
          vostok::network_core::udp_match_packet::helper::call_destructor();
          pointer[0] = *i;
          vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::deallocate(
            m_packets_allocator,
            pointer);
          *i = 0;
        }
        ++i;
      }
      break;
    }
    v46 = 0;
    survarium::weapon_user_dead_state::finalize(v13);
    packets_list = (vostok::network_core::udp_match_packet *)*((_DWORD *)packets.m_end - 1);
    v45 = 0;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)packets.m_end--);
    packet_list_tail = packets_list;
    packets_list->last_send_time_in_ms = (unsigned int)current_time_in_ms;
    v59 = 0;
    survarium::weapon_user_dead_state::finalize(current_time_in_ms);
    p_m_local_sequence_id = &thisa->m_local_sequence_id;
    ++thisa->m_local_sequence_id.m_number;
    v14 = (survarium::game_camera *)&packets_list->sequence_id;
    v43 = &packets_list->sequence_id;
    LOWORD(v14) = (vostok::network_core::sequence_number<unsigned short>)p_m_local_sequence_id->m_number;
    packets_list->sequence_id = (vostok::network_core::sequence_number<unsigned short>)p_m_local_sequence_id->m_number;
    v58 = 0;
    survarium::weapon_user_dead_state::finalize(v14);
    LOBYTE(v15) = packets_list->send_count + 1;
    packets_list->send_count = (unsigned __int8)v15;
    v73 = 1;
    v57 = 0;
    survarium::weapon_user_dead_state::finalize(v15);
    v16 = vostok::network_core::udp_match_packet::header_size(packets_list);
    size_left = 256
              - v16
              - (_DWORD)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                          (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)v16,
                          (int)packets_list)
              - 1;
    if ( size_left > 1 && !packets_list->m_buffer.elems[0] )
    {
      m_end = packets.m_end;
      v66 = (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)packets.m_end;
      m_begin = packets.m_begin;
      while ( 1 )
      {
        v41 = v66;
        if ( v66 == (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)m_begin )
          break;
        p_M_end_of_storage = &v66[-1]._M_end_of_storage;
        v17 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                v66,
                (int)v66[-1]._M_end_of_storage._M_data);
        if ( size_left > (unsigned int)v17 )
        {
          v39 = &v66[-1]._M_end_of_storage;
          if ( !BYTE3(v66[-1]._M_end_of_storage._M_data[1].config.id.max_storage) )
          {
            v38 = &v66[-1]._M_end_of_storage;
            v18 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                    (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)((char *)v66 - 4),
                    (int)v66[-1]._M_end_of_storage._M_data);
            size_left -= (unsigned int)&v18->config.data.pointer + 1;
            v37 = &v66[-1]._M_end_of_storage;
            packet_list_tail->next = (vostok::network_core::udp_match_packet *)v66[-1]._M_end_of_storage._M_data;
            v36 = &v66[-1]._M_end_of_storage;
            packet_list_tail = (vostok::network_core::udp_match_packet *)v66[-1]._M_end_of_storage._M_data;
            v35 = &v66[-1]._M_end_of_storage;
            (&v66[-1]._M_end_of_storage._M_data->object)[1] = 0;
            v34 = &v66[-1]._M_end_of_storage;
            v66[-1]._M_end_of_storage._M_data[1].config.data.pointer = current_time_in_ms;
            v33 = &v66[-1]._M_end_of_storage;
            v32 = (unsigned __int16 *)&v66[-1]._M_end_of_storage._M_data[1].config.data.max_storage + 2;
            *v32 = packets_list->sequence_id.m_number;
            v31 = &v66[-1]._M_end_of_storage;
            v22 = (char *)&v66[-1]._M_end_of_storage._M_data[1].config.id.pointer + 1;
            ++*v22;
            ++v73;
          }
        }
        v66 = (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)((char *)v66 - 4);
      }
      v30 = packets.m_end;
      end = (vostok::ai::planning::action_parameter **)packets.m_end;
      v19 = (vostok::network_core::udp_match_packet *)(v66 == (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)m_begin);
      v29 = &v19;
      LOWORD(v19) = packets_list->sequence_id.m_number;
      v28 = packets.m_end;
      __first = packets.m_begin;
      matched = (vostok::ai::planning::action_parameter **)stlp_std::remove_if<vostok::network_core::udp_match_packet * *,packets_in_list_predicate>(
                                                             packets.m_begin,
                                                             packets.m_end,
                                                             (packets_in_list_predicate)v19);
      begin = matched;
      vostok::buffer_vector<vostok::ai::planning::action_parameter *>::erase(
        (vostok::buffer_vector<vostok::ai::planning::action_parameter *> *)&packets,
        &begin,
        &end);
    }
    thisa->m_last_send_time_in_ms = (unsigned int)current_time_in_ms;
    vostok::network_core::udp_match_connection::send_packets_list(thisa, (survarium::game_camera *)packets_list, v73);
  }
  vostok::network_core::udp_match_connection::dump(
    thisa,
    &stru_984D24.m_working_macro_list.m_buffer[4].m_store[504],
    current_time_in_ms);
  for ( j = packets.m_begin; j != packets.m_end; ++j )
    ;
}
