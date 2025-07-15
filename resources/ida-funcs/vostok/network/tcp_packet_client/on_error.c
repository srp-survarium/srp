void __thiscall vostok::network::tcp_packet_client::on_error(
        vostok::network::tcp_packet_client *this,
        vostok::network_core::client_error_codes_enum client_error_code,
        const boost::system::error_code error_code)
{
  vostok::memory::doug_lea_allocator *v3; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::bullet_manager,unsigned int,unsigned int,unsigned int>,boost::_bi::list4<boost::_bi::value<survarium::bullet_manager *>,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int> > > v5; // [esp+8h] [ebp-9Ch]
  int *_Where; // [esp+58h] [ebp-4Ch]
  char v7; // [esp+64h] [ebp-40h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network::tcp_packet_client,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>,boost::_bi::list3<boost::_bi::value<vostok::network::tcp_packet_client *>,boost::_bi::value<enum vostok::network_core::client_error_codes_enum>,boost::_bi::value<boost::system::error_code> > > result; // [esp+68h] [ebp-3Ch] BYREF
  boost::function<void __cdecl(void)> f; // [esp+7Ch] [ebp-28h] BYREF
  vostok::network::response *v10; // [esp+A0h] [ebp-4h]

  v7 = 0;
  if ( !vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_on_error) )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)vostok::network::g_allocator);
    _Where = vostok::memory::doug_lea_allocator::malloc_impl(v3, 0x28u);
    v10 = (vostok::network::response *)operator new(0x28u, _Where);
    if ( v10 )
    {
      v5 = *(boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::bullet_manager,unsigned int,unsigned int,unsigned int>,boost::_bi::list4<boost::_bi::value<survarium::bullet_manager *>,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int> > > *)boost::bind<void,vostok::network::tcp_packet_client,enum vostok::network_core::client_error_codes_enum,boost::system::error_code,vostok::network::tcp_packet_client *,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>(&result, (void (__thiscall *)(vostok::network::tcp_packet_client *, vostok::network_core::client_error_codes_enum, boost::system::error_code))vostok::network::tcp_packet_client::on_error_impl, this, client_error_code, error_code);
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
        (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v5.l_.a3_.t_,
        &f);
      if ( boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_core_shotgun_reload_state_cook,vostok::resources::queries_result &,vostok::mutable_buffer,survarium::weapon_state_creation_params const *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_core_shotgun_reload_state_cook *>,boost::arg<1>,boost::_bi::value<vostok::mutable_buffer>,boost::_bi::value<survarium::weapon_state_creation_params const *>>>>(
             (boost::detail::function::basic_vtable0<void> *)&`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network::tcp_packet_client,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>,boost::_bi::list3<boost::_bi::value<vostok::network::tcp_packet_client *>,boost::_bi::value<enum vostok::network_core::client_error_codes_enum>,boost::_bi::value<boost::system::error_code>>>>'::`2'::stored_vtable,
             v5,
             &f.functor) )
      {
        f.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network::tcp_packet_client,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>,boost::_bi::list3<boost::_bi::value<vostok::network::tcp_packet_client *>,boost::_bi::value<enum vostok::network_core::client_error_codes_enum>,boost::_bi::value<boost::system::error_code>>>>'::`2'::stored_vtable.base.manager
                                                          + 1);
      }
      else
      {
        f.vtable = 0;
      }
      v7 = 1;
      v10->__vftable = (vostok::network::response_vtbl *)&vostok::network::response::`vftable';
      v10->__vftable = (vostok::network::response_vtbl *)&vostok::network::functor_response::`vftable';
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
        (boost::function<void __cdecl(void)> *)&v10[1],
        &f);
      vostok::network::network_world::add_response(this->m_world, v10);
    }
    else
    {
      vostok::network::network_world::add_response(this->m_world, 0);
    }
    if ( (v7 & 1) != 0 )
      boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&f);
  }
}
