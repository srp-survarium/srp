void __thiscall vostok::network::match_client_impl::match_client_impl(
        vostok::network::match_client_impl *this,
        boost::asio::io_service *io_service,
        vostok::network_core::udp_match_packets_orderer *packets_orderer,
        const vostok::network_core::udp_network_flow_emulator_options *options)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v4; // ecx
  survarium::game_camera *v5; // ecx
  vostok::memory::doug_lea_allocator *v6; // eax
  int v7; // eax
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v8; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v9; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v10; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v11; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v12; // ecx
  int v13; // [esp+8h] [ebp-D4h]
  int v14; // [esp+Ch] [ebp-D0h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::match_client_impl,enum vostok::network_core::disconnect_event_types_enum>,boost::_bi::list2<boost::_bi::value<vostok::network::match_client_impl *>,boost::arg<1> > > v16; // [esp+34h] [ebp-A8h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network::match_client_impl,unsigned char,vostok::network_core::packet_reader &>,boost::_bi::list3<boost::_bi::value<vostok::network::match_client_impl *>,boost::arg<1>,boost::arg<2> > > f; // [esp+5Ch] [ebp-80h]
  int *_Where; // [esp+64h] [ebp-78h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > v19; // [esp+84h] [ebp-58h] BYREF
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> v20; // [esp+8Ch] [ebp-50h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+ACh] [ebp-30h] BYREF
  boost::function2<void,unsigned char,vostok::network_core::packet_reader &> v22; // [esp+B4h] [ebp-28h] BYREF
  vostok::network_core::udp_network_flow_emulator *v23; // [esp+D8h] [ebp-4h]

  vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>(
    (vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy> *)((char *)this + (_DWORD)&loc_257FFD + 3),
    (vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::node *)this,
    0x258000u);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    v4,
    &this->m_packets_storage.elems[0][(_DWORD)&loc_25800F + 1]);
  if ( options )
  {
    survarium::weapon_user_dead_state::finalize(v5);
    _Where = vostok::memory::doug_lea_allocator::malloc_impl(v6, 0x30u);
    v23 = (vostok::network_core::udp_network_flow_emulator *)operator new(0x30u, _Where);
    if ( v23 )
    {
      vostok::network_core::udp_network_flow_emulator::udp_network_flow_emulator(
        v23,
        vostok::network::g_allocator,
        (vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy> *)((char *)this + (_DWORD)&loc_257FFD + 3),
        options);
      v14 = v7;
    }
    else
    {
      v14 = 0;
    }
    v13 = v14;
  }
  else
  {
    v13 = 0;
  }
  *(int *)((char *)&dword_258030 + (_DWORD)this) = v13;
  vostok::network_core::udp_match_client::udp_match_client(
    (vostok::network_core::udp_match_client *)((char *)this + (_DWORD)&loc_258034 + 4),
    io_service,
    (vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy> *)((char *)this + (_DWORD)&loc_257FFD + 3),
    packets_orderer,
    *(vostok::network_core::udp_network_flow_emulator **)((char *)&dword_258030 + (_DWORD)this));
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    v8,
    (Scaleform::Render::TreeNode::NodeData *(__thiscall *)(Scaleform::Render::TreeNode::NodeData *, const Scaleform::Render::TreeNode::NodeData *))((char *)Scaleform::Render::TreeNode::NodeData::operator= + (_DWORD)this));
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    v9,
    &this->m_packets_storage.elems[0][(_DWORD)&loc_258B7F + 1]);
  *(_DWORD *)&this->m_packets_storage.elems[0][(_DWORD)&loc_258B9D + 3] = 0;
  f = (boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network::match_client_impl,unsigned char,vostok::network_core::packet_reader &>,boost::_bi::list3<boost::_bi::value<vostok::network::match_client_impl *>,boost::arg<1>,boost::arg<2> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result, (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::network::match_client_impl::on_packet_received, (vostok::sound::sound_debug_stats *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v10, &v22);
  boost::function2<void,unsigned char,vostok::network_core::packet_reader &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network::match_client_impl,unsigned char,vostok::network_core::packet_reader &>,boost::_bi::list3<boost::_bi::value<vostok::network::match_client_impl *>,boost::arg<1>,boost::arg<2>>>>(
    &v22,
    f);
  boost::function<void __cdecl (unsigned char,vostok::network_core::packet_reader &)>::operator=(
    (boost::function<void __cdecl(unsigned int,unsigned int)> *)&v22,
    (boost::function2<void,unsigned int,unsigned int> *)((char *)this + (_DWORD)&loc_25856F + 1));
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v11,
    (int *)&v22);
  v16 = (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::match_client_impl,enum vostok::network_core::disconnect_event_types_enum>,boost::_bi::list2<boost::_bi::value<vostok::network::match_client_impl *>,boost::arg<1> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&v19, (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::network::match_client_impl::on_disconnect, (vostok::sound::sound_debug_stats *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v16.f_.f_,
    &v20);
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::match_client_impl,enum vostok::network_core::disconnect_event_types_enum>,boost::_bi::list2<boost::_bi::value<vostok::network::match_client_impl *>,boost::arg<1>>>>(
    &v20,
    v16);
  boost::function<void __cdecl (unsigned char,vostok::network_core::packet_reader &)>::operator=(
    (boost::function<void __cdecl(unsigned int,unsigned int)> *)&v20,
    (boost::function2<void,unsigned int,unsigned int> *)((char *)&loc_258590 + (_DWORD)this));
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v12,
    (int *)&v20);
}
