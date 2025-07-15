void __thiscall survarium::bullet_manager::add_decal(
        survarium::bullet_manager *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *decal,
        float size,
        const vostok::math::float3 *position,
        const vostok::math::float3 *direction,
        const vostok::math::float3 *normal,
        bool is_front_face)
{
  survarium::bullet_manager::bullet_functor *v7; // eax
  survarium::bullet_manager::bullet_functor *v8; // [esp+14h] [ebp-98h]
  vostok::intrusive_mpmc_stack<survarium::bullet_manager::bullet_functor,survarium::bullet_manager::bullet_functor,72> *target; // [esp+1Ch] [ebp-90h]
  volatile __int64 comperand; // [esp+20h] [ebp-8Ch]
  survarium::bullet_manager::bullet_functor *exchange; // [esp+28h] [ebp-84h]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > >,vostok::network_core::tcp_packet const *,boost::system::error_code const &,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > > *>,boost::_bi::value<vostok::network_core::tcp_packet *>,boost::arg<1>,boost::arg<2> > > v13; // [esp+30h] [ebp-7Ch]
  boost::function0<void> v14; // [esp+5Ch] [ebp-50h] BYREF
  void *_Where; // [esp+88h] [ebp-24h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_voice,void *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_voice *>,boost::_bi::value<void *> > > result; // [esp+98h] [ebp-14h] BYREF
  survarium::bullet_manager::bullet_functor *v17; // [esp+A4h] [ebp-8h]
  survarium::bullet_manager::bullet_functor *functor; // [esp+A8h] [ebp-4h]

  if ( this->m_engine
    && vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator survarium::inventory_item * (__thiscall vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::*)(void)const(
         (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this,
         decal) )
  {
    _Where = survarium::bullet_manager::bullet_functor_mt_allocator::malloc_impl(
               &this->m_mt_stack_allocator,
               (survarium::game_camera *)0x58);
    v17 = (survarium::bullet_manager::bullet_functor *)operator new(0x58u, _Where);
    if ( v17 )
    {
      survarium::bullet_manager::bullet_functor::bullet_functor(v17);
      v8 = v7;
    }
    else
    {
      v8 = 0;
    }
    functor = v8;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
      &v8->resource,
      decal);
    v8->position = *position;
    functor->direction = *direction;
    functor->normal = *normal;
    functor->size = size;
    functor->is_front_face = is_front_face;
    v13 = *boost::bind<void,vostok::network::match_client,vostok::network_core::udp_network_flow_emulator_options const *,vostok::network::match_client *,vostok::network_core::udp_network_flow_emulator_options const *>(
             (boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > >,vostok::network_core::tcp_packet const *,boost::system::error_code const &,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > > *>,boost::_bi::value<vostok::network_core::tcp_packet *>,boost::arg<1>,boost::arg<2> > > *)&result,
             (void (__thiscall *)(vostok::sound::sound_voice *, void *))survarium::bullet_manager::add_decal_impl,
             (vostok::sound::sound_voice *)this,
             (vostok::network_core::tcp_packet *)functor);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v13.f_.f_,
      &v14);
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::bullet_manager,survarium::bullet_manager::bullet_functor *>,boost::_bi::list2<boost::_bi::value<survarium::bullet_manager *>,boost::_bi::value<survarium::bullet_manager::bullet_functor *>>>>(
      &v14,
      (boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::bullet_manager,survarium::bullet_manager::bullet_functor *>,boost::_bi::list2<boost::_bi::value<survarium::bullet_manager *>,boost::_bi::value<survarium::bullet_manager::bullet_functor *> > >)v13);
    boost::function0<void>::swap(&v14, &functor->functor);
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v14);
    target = &this->m_functors;
    exchange = functor;
    do
    {
      comperand = target->m_top.whole;
      exchange->next = target->m_top.m_pointer;
    }
    while ( vostok::threading::interlocked_compare_exchange(
              &target->m_top.whole,
              __SPAIR64__(HIDWORD(comperand), (unsigned int)exchange),
              comperand) != comperand );
  }
}
