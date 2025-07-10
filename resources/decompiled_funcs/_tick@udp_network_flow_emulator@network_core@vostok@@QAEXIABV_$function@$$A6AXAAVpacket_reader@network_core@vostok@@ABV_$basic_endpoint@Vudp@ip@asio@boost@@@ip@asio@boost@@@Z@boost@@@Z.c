void __thiscall vostok::network_core::udp_network_flow_emulator::tick(
        vostok::network_core::udp_network_flow_emulator *this,
        survarium::flash_external_handler_vtbl *time_in_ms,
        boost::function2<void,char const *,vostok::network_core::udp_match_packet const *> *functor)
{
  void *v3; // esp
  survarium::game_camera *v4; // ecx
  stlp_std::pair<vostok::network_core::udp_match_packet *,boost::asio::ip::basic_endpoint<boost::asio::ip::udp> > *v5; // eax
  survarium::game_camera *v6; // ecx
  survarium::base_project::resolve_link_object *v7; // esi
  vostok::network_core::packet_reader *v8; // ecx
  vostok::network_core::packet_reader *v9; // ecx
  survarium::base_project::resolve_link_object *v10; // esi
  delayed_packets_predicate v11; // [esp-8h] [ebp-1F8h] BYREF
  _DWORD v12[2]; // [esp+0h] [ebp-1F0h] BYREF
  vostok::network_core::udp_network_flow_emulator *thisa; // [esp+8h] [ebp-1E8h]
  stlp_std::pair<vostok::network_core::udp_match_packet *,boost::asio::ip::basic_endpoint<boost::asio::ip::udp> > *k; // [esp+Ch] [ebp-1E4h]
  const void **v15; // [esp+150h] [ebp-A0h]
  const void **v16; // [esp+154h] [ebp-9Ch]
  vostok::network_core::udp_match_packet *v17; // [esp+158h] [ebp-98h]
  const void **p_m_buffer; // [esp+164h] [ebp-8Ch]
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v19; // [esp+168h] [ebp-88h]
  vostok::network_core::udp_match_packet *first; // [esp+16Ch] [ebp-84h]
  stlp_std::pair<vostok::network_core::udp_match_packet *,boost::asio::ip::basic_endpoint<boost::asio::ip::udp> > *m_end; // [esp+170h] [ebp-80h]
  stlp_std::pair<vostok::network_core::udp_match_packet *,boost::asio::ip::basic_endpoint<boost::asio::ip::udp> > *j; // [esp+174h] [ebp-7Ch]
  stlp_std::pair<vostok::network_core::udp_match_packet *,boost::asio::ip::basic_endpoint<boost::asio::ip::udp> > *v23; // [esp+178h] [ebp-78h]
  stlp_std::pair<vostok::network_core::udp_match_packet *,boost::asio::ip::basic_endpoint<boost::asio::ip::udp> > *v24; // [esp+17Ch] [ebp-74h]
  stlp_std::pair<vostok::network_core::udp_match_packet *,boost::asio::ip::basic_endpoint<boost::asio::ip::udp> > *__first; // [esp+194h] [ebp-5Ch]
  stlp_std::pair<vostok::network_core::udp_match_packet *,boost::asio::ip::basic_endpoint<boost::asio::ip::udp> > *__last; // [esp+198h] [ebp-58h]
  survarium::game_options *v27; // [esp+19Ch] [ebp-54h]
  stlp_std::pair<vostok::network_core::udp_match_packet *,boost::asio::ip::basic_endpoint<boost::asio::ip::udp> > *M_finish; // [esp+1A0h] [ebp-50h]
  stlp_std::pair<vostok::network_core::udp_match_packet *,boost::asio::ip::basic_endpoint<boost::asio::ip::udp> > *v29; // [esp+1A4h] [ebp-4Ch]
  char v30; // [esp+1ABh] [ebp-45h]
  int v31; // [esp+1ACh] [ebp-44h]
  int v32; // [esp+1B0h] [ebp-40h]
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > v33; // [esp+1B4h] [ebp-3Ch] BYREF
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v34; // [esp+1C0h] [ebp-30h]
  unsigned __int16 received_local_sequence_id; // [esp+1C8h] [ebp-28h]
  _DWORD v36[2]; // [esp+1CCh] [ebp-24h] BYREF
  unsigned __int16 remote_sequence_id; // [esp+1D4h] [ebp-1Ch]
  vostok::network_core::packet_reader reader; // [esp+1D8h] [ebp-18h] BYREF
  stlp_std::pair<vostok::network_core::udp_match_packet *,boost::asio::ip::basic_endpoint<boost::asio::ip::udp> > *e; // [esp+1E0h] [ebp-10h]
  stlp_std::pair<vostok::network_core::udp_match_packet *,boost::asio::ip::basic_endpoint<boost::asio::ip::udp> > *i; // [esp+1E4h] [ebp-Ch]
  vostok::buffer_vector<stlp_std::pair<vostok::network_core::udp_match_packet *,boost::asio::ip::basic_endpoint<boost::asio::ip::udp> > > delayed_packets_to_appear; // [esp+1E8h] [ebp-8h] BYREF

  thisa = this;
  if ( this->m_delayed_packets._M_impl._M_start != this->m_delayed_packets._M_impl._M_finish )
  {
    v3 = alloca(
           32
         * stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::size((stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl> > *)thisa));
    v12[1] = v12;
    v32 = stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::size((stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl> > *)thisa);
    v31 = stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::size((stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl> > *)thisa);
    survarium::weapon_user_dead_state::finalize(v4);
    v29 = v5;
    delayed_packets_to_appear.m_begin = v5;
    delayed_packets_to_appear.m_end = v5;
    v30 = 0;
    survarium::weapon_user_dead_state::finalize(v6);
    M_finish = thisa->m_delayed_packets._M_impl._M_finish;
    v27 = (survarium::game_options *)&v11;
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v11);
    v27->vostok::input::handler::__vftable = (survarium::game_options_vtbl *)&delayed_packets_to_appear;
    v27->survarium::flash_external_handler::__vftable = time_in_ms;
    __last = thisa->m_delayed_packets._M_impl._M_finish;
    __first = thisa->m_delayed_packets._M_impl._M_start;
    v23 = (stlp_std::pair<vostok::network_core::udp_match_packet *,boost::asio::ip::basic_endpoint<boost::asio::ip::udp> > *)stlp_std::remove_if<stlp_std::pair<vostok::network_core::udp_match_packet *,boost::asio::ip::basic_endpoint<boost::asio::ip::udp>> *,delayed_packets_predicate>(__first, __last, v11);
    v24 = stlp_std::priv::_Impl_vector<stlp_std::pair<vostok::network_core::udp_match_packet *,boost::asio::ip::basic_endpoint<boost::asio::ip::udp>>,vostok::vectora_allocator<stlp_std::pair<vostok::network_core::udp_match_packet *,boost::asio::ip::basic_endpoint<boost::asio::ip::udp>>>>::erase(
            &thisa->m_delayed_packets._M_impl,
            v23,
            M_finish);
    if ( delayed_packets_to_appear.m_begin == delayed_packets_to_appear.m_end )
    {
      for ( j = delayed_packets_to_appear.m_begin; j != delayed_packets_to_appear.m_end; ++j )
        ;
      delayed_packets_to_appear.m_end = delayed_packets_to_appear.m_begin;
    }
    else
    {
      m_end = delayed_packets_to_appear.m_end;
      stlp_std::random_shuffle<stlp_std::pair<vostok::network_core::udp_match_packet *,boost::asio::ip::basic_endpoint<boost::asio::ip::udp>> *,vostok::math::random32>(
        delayed_packets_to_appear.m_begin,
        delayed_packets_to_appear.m_end,
        &thisa->m_out_of_order_random);
      i = delayed_packets_to_appear.m_begin;
      e = delayed_packets_to_appear.m_end;
      while ( i != e )
      {
        first = i->first;
        v7 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
               (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)i,
               (int)first);
        v19 = (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)((char *)v7 + (unsigned __int8)vostok::network_core::udp_match_packet::header_size(first));
        p_m_buffer = (const void **)&i->first->m_buffer;
        v33._M_impl._M_end_of_storage._M_data = p_m_buffer;
        v34 = v19;
        v36[0] = &v33._M_impl._M_end_of_storage;
        v36[1] = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                   v19,
                   (int)&v33._M_impl._M_end_of_storage);
        remote_sequence_id = vostok::network_core::packet_reader::r<unsigned short>(v8, (int)v36);
        received_local_sequence_id = vostok::network_core::packet_reader::r<unsigned short>(v9, (int)v36);
        v17 = i->first;
        v10 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)v17,
                (int)v17);
        v16 = (const void **)((char *)&v10->config.data.pointer
                            + (unsigned __int8)vostok::network_core::udp_match_packet::header_size(v17));
        v15 = (const void **)&i->first->m_buffer;
        v33._M_impl._M_start = v15;
        v33._M_impl._M_finish = v16;
        reader.m_packet = (const vostok::network_core::base_packet *)&v33;
        reader.m_pointer = (const unsigned __int8 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                      &v33,
                                                      (int)&v33);
        boost::function2<void,vostok::ai::brain_unit const *,vostok::ai::animation_item const *>::operator()(
          functor,
          (const char *)&reader,
          (const vostok::network_core::udp_match_packet *)&i->second);
        vostok::network_core::delete_udp_match_packet(
          thisa->m_packets_allocator,
          (vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::node **)i++);
      }
      for ( k = delayed_packets_to_appear.m_begin; k != delayed_packets_to_appear.m_end; ++k )
        ;
    }
  }
}
