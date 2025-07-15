void __thiscall vostok::network_core::udp_match_client::send_queued_packets(
        vostok::network_core::udp_match_client *this,
        survarium::game_camera *current_time_in_ms)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v2; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > > f; // [esp+Ch] [ebp-44h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+28h] [ebp-28h] BYREF
  boost::function<void __cdecl(vostok::network_core::packet_reader &,boost::asio::ip::basic_endpoint<boost::asio::ip::udp> const &)> functor; // [esp+30h] [ebp-20h] BYREF

  if ( !this->m_network_flow_emulator
    || ((f = (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result, (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::network_core::udp_match_client::process_incoming_packet, (vostok::sound::sound_debug_stats *)this),
         boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v2, &functor),
         !boost::detail::function::basic_vtable1<void,boost::system::error_code>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::http_client,boost::system::error_code>,boost::_bi::list2<boost::_bi::value<vostok::network::http_client *>,boost::arg<1>>>>(
            (boost::detail::function::basic_vtable1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> *)&stru_984D24.m_working_macro_list.m_buffer[1].m_store[356],
            f,
            &functor.functor))
      ? (functor.vtable = 0)
      : (functor.vtable = (boost::detail::function::vtable_base *)&stru_984D24.m_working_macro_list.m_buffer[1].m_store[357]),
        vostok::network_core::udp_network_flow_emulator::tick(
          this->m_network_flow_emulator,
          (survarium::flash_external_handler_vtbl *)this->m_time_in_ms,
          (boost::function2<void,char const *,vostok::network_core::udp_match_packet const *> *)&functor),
        boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&functor),
        this->m_connection.m_state != disconnected) )
  {
    this->m_time_in_ms = (unsigned int)current_time_in_ms;
    vostok::network_core::udp_match_client::check_consistency(this);
    vostok::network_core::udp_match_connection::send_queued_packets(&this->m_connection, current_time_in_ms);
    vostok::network_core::udp_match_client::check_consistency(this);
  }
}
