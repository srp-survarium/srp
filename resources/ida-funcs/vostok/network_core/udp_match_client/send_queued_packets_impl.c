void __userpurge vostok::network_core::udp_match_client::send_queued_packets_impl(
        vostok::network_core::udp_match_client *this@<ecx>,
        int a2@<eax>,
        boost::function<void __cdecl(vostok::network_core::udp_match_packet &,boost::function<void __cdecl(vostok::network_core::udp_match_packet &,boost::system::error_code const &,unsigned int)> const &)> *time_in_ms)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  __int64 v5; // [esp+8h] [ebp-28h] BYREF
  boost::function<void __cdecl(vostok::network_core::udp_match_packet &,boost::function<void __cdecl(vostok::network_core::udp_match_packet &,boost::system::error_code const &,unsigned int)> const &)> v6; // [esp+10h] [ebp-20h] BYREF

  LODWORD(v5) = vostok::network_core::udp_match_client::send_packet;
  HIDWORD(v5) = a2;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus((vostok::particle::particle_action *)this) )
  {
    v6.vtable = 0;
  }
  else
  {
    *(_QWORD *)&v6.functor.obj_ptr = v5;
    v6.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function2<void,vostok::network_core::udp_match_packet &,boost::function<void __cdecl (vostok::network_core::udp_match_packet &,boost::system::error_code const &,unsigned int)> const &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::udp_match_client,vostok::network_core::udp_match_packet &,boost::function<void __cdecl (vostok::network_core::udp_match_packet &,boost::system::error_code const &,unsigned int)> const &>,boost::_bi::list3<boost::_bi::value<vostok::network_core::udp_match_client *>,boost::arg<1>,boost::arg<2>>>>'::`2'::stored_vtable
                                                       + 1);
  }
  vostok::network_core::udp_match_connection::send_queued_packets(
    (vostok::network_core::udp_match_connection *)&v5,
    a2,
    (unsigned int)time_in_ms,
    &v6);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v4,
    (int *)&v6);
}
