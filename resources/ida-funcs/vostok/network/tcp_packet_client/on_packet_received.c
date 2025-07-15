void __thiscall vostok::network::tcp_packet_client::on_packet_received(
        vostok::network::tcp_packet_client *this,
        const vostok::network_core::tcp_packet *packet)
{
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v2; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  unsigned __int8 *v4; // eax
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v5; // ecx
  survarium::game_camera *v6; // ecx
  vostok::memory::doug_lea_allocator *v7; // eax
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v8; // ecx
  survarium::base_project::resolve_link_object *v9; // [esp-4h] [ebp-68h]
  vostok::network::response_vtbl *v11; // [esp+10h] [ebp-54h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::tcp_packet_client,vostok::network_core::packet_reader &>,boost::_bi::list2<boost::_bi::value<vostok::network::tcp_packet_client *>,boost::arg<1> > > f; // [esp+14h] [ebp-50h]
  int *_Where; // [esp+24h] [ebp-40h]
  char v14; // [esp+30h] [ebp-34h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+34h] [ebp-30h] BYREF
  boost::function1<void,vostok::network_core::packet_reader &> v16; // [esp+3Ch] [ebp-28h] BYREF
  vostok::network::response *v17; // [esp+5Ch] [ebp-8h]
  vostok::network_core::tcp_packet *cloned_packet; // [esp+60h] [ebp-4h]

  v14 = 0;
  if ( !vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this) )
  {
    cloned_packet = vostok::network::network_world::new_packet(this->m_world);
    cloned_packet->m_buffer_size = 0;
    v9 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
           v2,
           (int)packet);
    v4 = (unsigned __int8 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                              v3,
                              (int)packet);
    vostok::network_core::packet<vostok::network_core::tcp_packet>::append(v5, (int)cloned_packet, v4, (unsigned int)v9);
    survarium::weapon_user_dead_state::finalize(v6);
    _Where = vostok::memory::doug_lea_allocator::malloc_impl(v7, 0x30u);
    v17 = (vostok::network::response *)operator new(0x30u, _Where);
    if ( v17 )
    {
      f = (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::tcp_packet_client,vostok::network_core::packet_reader &>,boost::_bi::list2<boost::_bi::value<vostok::network::tcp_packet_client *>,boost::arg<1> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result, (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::network::tcp_packet_client::on_packet_received_impl, (vostok::sound::sound_debug_stats *)this);
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v8, &v16);
      boost::function1<void,vostok::network_core::packet_reader &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::tcp_packet_client,vostok::network_core::packet_reader &>,boost::_bi::list2<boost::_bi::value<vostok::network::tcp_packet_client *>,boost::arg<1>>>>(
        &v16,
        f);
      v14 = 1;
      v11 = (vostok::network::response_vtbl *)vostok::network::g_allocator;
      v17->__vftable = (vostok::network::response_vtbl *)&vostok::network::response::`vftable';
      survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v17[1]);
      v17->__vftable = (vostok::network::response_vtbl *)&vostok::network::receive_response::`vftable';
      boost::function<void __cdecl (unsigned int,float,float,char const *)>::function<void __cdecl (unsigned int,float,float,char const *)>((boost::function<void __cdecl(unsigned int,float,float,char const *)> *)&v16);
      v17[5].__vftable = v11;
      v17[5].next_for_responses = (vostok::network::response *)cloned_packet;
      vostok::network::network_world::add_response(this->m_world, v17);
    }
    else
    {
      vostok::network::network_world::add_response(this->m_world, 0);
    }
    if ( (v14 & 1) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)(v14 & 1),
        (int *)&v16);
  }
}
