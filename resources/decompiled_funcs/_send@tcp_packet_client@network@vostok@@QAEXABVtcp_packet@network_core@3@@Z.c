void __thiscall vostok::network::tcp_packet_client::send(
        vostok::network::tcp_packet_client *this,
        const vostok::network_core::tcp_packet *packet)
{
  vostok::memory::base_allocator *v2; // eax
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v3; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v4; // ecx
  unsigned __int8 *v5; // eax
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v6; // ecx
  vostok::memory::base_allocator *v7; // eax
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v8; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v9; // ecx
  survarium::base_project::resolve_link_object *v10; // [esp-4h] [ebp-B4h]
  vostok::network_core::tcp_packet *v11; // [esp+8h] [ebp-A8h]
  boost::function1<void,enum vostok::handshaking_error_types_enum> *p_functor; // [esp+18h] [ebp-98h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *v14; // [esp+1Ch] [ebp-94h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *v15; // [esp+20h] [ebp-90h]
  vostok::network::network_world *v16; // [esp+24h] [ebp-8Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network_core::tcp_packet_client,vostok::network_core::tcp_packet const &>,boost::_bi::list2<boost::_bi::value<vostok::network_core::tcp_packet_client *>,boost::arg<1> > > f; // [esp+30h] [ebp-80h]
  void *v18; // [esp+38h] [ebp-78h]
  survarium::game_camera *v19; // [esp+40h] [ebp-70h]
  vostok::network::network_world *v20; // [esp+4Ch] [ebp-64h]
  vostok::memory::base_allocator *m_owner_allocator; // [esp+50h] [ebp-60h]
  void *_Where; // [esp+58h] [ebp-58h]
  vostok::network::network_world *m_world; // [esp+60h] [ebp-50h]
  char v24; // [esp+6Ch] [ebp-44h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+70h] [ebp-40h] BYREF
  boost::function1<void,vostok::network_core::tcp_packet const &> v26; // [esp+78h] [ebp-38h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *v27; // [esp+9Ch] [ebp-14h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *v28; // [esp+A0h] [ebp-10h]
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v29; // [esp+A4h] [ebp-Ch]
  char *v30; // [esp+A8h] [ebp-8h]
  vostok::network_core::tcp_packet *cloned_packet; // [esp+ACh] [ebp-4h]

  v24 = 0;
  m_world = this->m_world;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_world);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_world->m_channel.orders.m_owner_allocator);
  _Where = vostok::memory::base_allocator::malloc_impl(v2, 0x10u);
  v30 = (char *)operator new(0x10u, _Where);
  if ( v30 )
  {
    v20 = this->m_world;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v20);
    m_owner_allocator = v20->m_channel.orders.m_owner_allocator;
    *(_DWORD *)v30 = 0;
    *((_DWORD *)v30 + 1) = 0;
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)(v30 + 8));
    *((_DWORD *)v30 + 2) = m_owner_allocator;
    *((_DWORD *)v30 + 3) = 0;
    v3 = (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)v30;
    v11 = (vostok::network_core::tcp_packet *)v30;
  }
  else
  {
    v11 = 0;
  }
  cloned_packet = v11;
  v11->m_buffer_size = 0;
  v10 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
          v3,
          (int)packet);
  v5 = (unsigned __int8 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                            v4,
                            (int)packet);
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(v6, (int)cloned_packet, v5, (unsigned int)v10);
  v19 = (survarium::game_camera *)this->m_world;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v19);
  v18 = vostok::memory::base_allocator::malloc_impl(v7, 0x30u);
  v29 = (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)operator new(0x30u, v18);
  if ( v29 )
  {
    f = (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network_core::tcp_packet_client,vostok::network_core::tcp_packet const &>,boost::_bi::list2<boost::_bi::value<vostok::network_core::tcp_packet_client *>,boost::arg<1> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result, (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::network_core::tcp_packet_client::send, (vostok::sound::sound_debug_stats *)this->m_client);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v8, &v26);
    boost::function1<void,vostok::network_core::tcp_packet const &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network_core::tcp_packet_client,vostok::network_core::tcp_packet const &>,boost::_bi::list2<boost::_bi::value<vostok::network_core::tcp_packet_client *>,boost::arg<1>>>>(
      &v26,
      f);
    v24 = 1;
    v16 = this->m_world;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v16);
    v28 = boost::addressof<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result>,boost::_bi::list2<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>>>>((boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *)v16->m_channel.orders.m_owner_allocator);
    v15 = v28;
    v27 = boost::addressof<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result>,boost::_bi::list2<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>>>>((boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *)cloned_packet);
    v14 = v27;
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)&(&v29->vtable)[1]);
    v29->vtable = (boost::detail::function::vtable_base *)&vostok::network::order::`vftable';
    v9 = v29;
    v29->vtable = (boost::detail::function::vtable_base *)&vostok::network::send_order::`vftable';
    p_functor = (boost::function1<void,enum vostok::handshaking_error_types_enum> *)&v29->functor;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v9, &v29->functor.obj_ptr);
    boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::assign_to_own(
      p_functor,
      (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v26);
    v29[1].functor.obj_ptr = v14;
    v29[1].functor.vostok_pointer_size_alignment[1] = v15;
    vostok::network::network_world::add_order(this->m_world, (vostok::network::response *)v29);
  }
  else
  {
    vostok::network::network_world::add_order(this->m_world, 0);
  }
  if ( (v24 & 1) != 0 )
    boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v26);
}
