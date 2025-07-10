void __thiscall vostok::network::match_client::on_packet_received(
        vostok::network::match_client *this,
        unsigned __int8 message_type,
        vostok::network_core::packet_reader *reader)
{
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  const vostok::variant<32> **v4; // eax
  vostok::network_core::packet_reader *v5; // ecx
  unsigned int v6; // esi
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v7; // ecx
  unsigned __int8 *v8; // eax
  survarium::game_camera *v9; // ecx
  vostok::memory::doug_lea_allocator *v10; // eax
  vostok::network::response *v12; // [esp+14h] [ebp-74h]
  char *v13; // [esp+18h] [ebp-70h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::breath_vibration_calculator,bool>,boost::_bi::list2<boost::_bi::value<survarium::breath_vibration_calculator *>,boost::_bi::value<bool> > > v14; // [esp+1Ch] [ebp-6Ch]
  int *_Where; // [esp+28h] [ebp-60h]
  char v16; // [esp+48h] [ebp-40h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network::match_client,unsigned char,vostok::network_core::packet_reader &>,boost::_bi::list3<boost::_bi::value<vostok::network::match_client *>,boost::_bi::value<unsigned char>,boost::arg<1> > > result; // [esp+4Ch] [ebp-3Ch] BYREF
  boost::function1<void,vostok::network_core::packet_reader &> v18; // [esp+58h] [ebp-30h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *v19; // [esp+7Ch] [ebp-Ch]
  vostok::network::response *v20; // [esp+80h] [ebp-8h]
  vostok::network_core::udp_match_packet *packet; // [esp+84h] [ebp-4h]

  v16 = 0;
  if ( (!vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_on_packet_received)
      ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
      : 0) != 0 )
  {
    v4 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
           v3,
           (int)&this->m_response_packets_allocator);
    packet = vostok::network_core::new_udp_match_packet((vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy> *)v4);
    v6 = vostok::network_core::packet_reader::size_to_eof(v5, reader);
    v8 = (unsigned __int8 *)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                              v7,
                              (int)reader);
    vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(v6, packet, v8);
    survarium::weapon_user_dead_state::finalize(v9);
    _Where = vostok::memory::doug_lea_allocator::malloc_impl(v10, 0xB8u);
    v20 = (vostok::network::response *)operator new(0xB8u, _Where);
    if ( v20 )
    {
      v14 = *boost::bind<bool,survarium::breath_vibration_calculator,bool,survarium::breath_vibration_calculator *,bool>(
               (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::breath_vibration_calculator,bool>,boost::_bi::list2<boost::_bi::value<survarium::breath_vibration_calculator *>,boost::_bi::value<bool> > > *)&result,
               (bool (__thiscall *)(survarium::breath_vibration_calculator *, bool))vostok::network::match_client::on_packet_received_impl,
               this,
               message_type);
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
        (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v14.l_.a1_.t_,
        &v18);
      boost::function1<void,vostok::network_core::packet_reader &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network::match_client,unsigned char,vostok::network_core::packet_reader &>,boost::_bi::list3<boost::_bi::value<vostok::network::match_client *>,boost::_bi::value<unsigned char>,boost::arg<1>>>>(
        &v18,
        (boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network::match_client,unsigned char,vostok::network_core::packet_reader &>,boost::_bi::list3<boost::_bi::value<vostok::network::match_client *>,boost::_bi::value<unsigned char>,boost::arg<1> > >)v14);
      v16 = 1;
      v13 = (char *)&loc_258034 + (unsigned int)*this->m_client + 4;
      v19 = boost::addressof<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result>,boost::_bi::list2<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>>>>((boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *)packet);
      v12 = (vostok::network::response *)v19;
      v20->__vftable = (vostok::network::response_vtbl *)&vostok::network::response::`vftable';
      survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v20[1]);
      v20->__vftable = (vostok::network::response_vtbl *)&vostok::network::receive_udp_response::`vftable';
      qmemcpy(&v20[1], v13, 0x80u);
      boost::function<void __cdecl (unsigned int,float,float,char const *)>::function<void __cdecl (unsigned int,float,float,char const *)>((boost::function<void __cdecl(unsigned int,float,float,char const *)> *)&v18);
      vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>(
        &this->m_response_packets_allocator,
        (vostok::network_core::udp_match_packets_allocator **)&v20[21]);
      v20[21].next_for_responses = v12;
      v20[22].__vftable = (vostok::network::response_vtbl *)&this->m_stats;
      vostok::network::network_world::add_response(this->m_world, v20);
    }
    else
    {
      vostok::network::network_world::add_response(this->m_world, 0);
    }
    if ( (v16 & 1) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)(v16 & 1),
        (int *)&v18);
  }
}
