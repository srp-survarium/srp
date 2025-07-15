void __thiscall survarium::jump_logic::initialize_logic(survarium::jump_logic *this)
{
  vostok::memory::doug_lea_allocator *v1; // eax
  vostok::ai::fsm *v2; // eax
  vostok::memory::doug_lea_allocator *v3; // eax
  vostok::memory::doug_lea_allocator *v4; // eax
  survarium::game_camera *v5; // eax
  vostok::memory::doug_lea_allocator *v6; // eax
  survarium::jump_logic_base_state *v7; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v8; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v9; // ecx
  survarium::game_camera *v10; // ecx
  int v11; // eax
  boost::_bi::list4<enum vostok::connection_error_types_enum &,enum vostok::handshaking_error_types_enum &,enum vostok::socket_error_types_enum &,enum vostok::lobby_server_message_types_enum &> *v12; // ecx
  vostok::socket_error_types_enum *v13; // eax
  survarium::jump_logic_base_state *v14; // [esp+4h] [ebp-BCh]
  survarium::game_camera *v15; // [esp+8h] [ebp-B8h]
  survarium::jump_logic_base_state *v16; // [esp+Ch] [ebp-B4h]
  vostok::ai::fsm *v17; // [esp+10h] [ebp-B0h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > > v19; // [esp+18h] [ebp-A8h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > > f; // [esp+24h] [ebp-9Ch]
  void *v21; // [esp+30h] [ebp-90h]
  void *v22; // [esp+38h] [ebp-88h]
  void *v23; // [esp+40h] [ebp-80h]
  void *_Where; // [esp+48h] [ebp-78h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > v25; // [esp+50h] [ebp-70h] BYREF
  boost::function<bool __cdecl(void)> v26; // [esp+58h] [ebp-68h] BYREF
  boost::_bi::bind_t<bool,bool (__cdecl*)(void),boost::_bi::list0> result; // [esp+78h] [ebp-48h] BYREF
  boost::function<bool __cdecl(void)> transition_predicate; // [esp+80h] [ebp-40h] BYREF
  survarium::jump_logic_state_landing *v29; // [esp+A4h] [ebp-1Ch]
  survarium::jump_logic_state_start *v30; // [esp+A8h] [ebp-18h]
  survarium::jump_logic_base_state *v31; // [esp+ACh] [ebp-14h]
  vostok::ai::fsm *v32; // [esp+B0h] [ebp-10h]
  survarium::jump_logic_base_state *start; // [esp+B4h] [ebp-Ch]
  survarium::jump_logic_base_state *landing; // [esp+B8h] [ebp-8h]
  survarium::jump_logic_base_state *inactive; // [esp+BCh] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v1, 0x14u);
  v32 = (vostok::ai::fsm *)operator new(0x14u, _Where);
  if ( v32 )
  {
    vostok::ai::fsm::fsm(v32);
    v17 = v2;
  }
  else
  {
    v17 = 0;
  }
  this->m_logic = v17;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v23 = vostok::memory::doug_lea_allocator::malloc_impl(v3, 0x28u);
  v31 = (survarium::jump_logic_base_state *)operator new(0x28u, v23);
  if ( v31 )
  {
    survarium::jump_logic_base_state::jump_logic_base_state(v31, this);
    v31->__vftable = (survarium::jump_logic_base_state_vtbl *)&survarium::jump_logic_state_inactive::`vftable';
    v16 = v31;
  }
  else
  {
    v16 = 0;
  }
  inactive = v16;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v16);
  v22 = vostok::memory::doug_lea_allocator::malloc_impl(v4, 0x30u);
  v30 = (survarium::jump_logic_state_start *)operator new(0x30u, v22);
  if ( v30 )
  {
    survarium::jump_logic_state_start::jump_logic_state_start(v30, this);
    v15 = v5;
  }
  else
  {
    v15 = 0;
  }
  start = (survarium::jump_logic_base_state *)v15;
  survarium::weapon_user_dead_state::finalize(v15);
  v21 = vostok::memory::doug_lea_allocator::malloc_impl(v6, 0x2Cu);
  v29 = (survarium::jump_logic_state_landing *)operator new(0x2Cu, v21);
  if ( v29 )
  {
    survarium::jump_logic_state_landing::jump_logic_state_landing(v29, this);
    v14 = v7;
  }
  else
  {
    v14 = 0;
  }
  landing = v14;
  vostok::ai::fsm::add_state(this->m_logic, inactive);
  vostok::ai::fsm::add_state(this->m_logic, start);
  vostok::ai::fsm::add_state(this->m_logic, v14);
  f = (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > >)*boost::bind<bool>(&result, (bool (__cdecl *)())survarium::true_predicate);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)f.f_.f_,
    &transition_predicate);
  if ( boost::detail::function::basic_vtable1<void,boost::system::error_code>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::http_client,boost::system::error_code>,boost::_bi::list2<boost::_bi::value<vostok::network::http_client *>,boost::arg<1>>>>(
         (boost::detail::function::basic_vtable1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> *)&`boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,bool (__cdecl *)(void),boost::_bi::list0>>'::`2'::stored_vtable,
         f,
         &transition_predicate.functor) )
  {
    transition_predicate.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,bool (__cdecl *)(void),boost::_bi::list0>>'::`2'::stored_vtable.base.manager
                                                                         + 1);
  }
  else
  {
    transition_predicate.vtable = 0;
  }
  vostok::ai::fsm::add_transition(
    this->m_logic,
    inactive,
    start,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&transition_predicate);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v8,
    (int *)&transition_predicate);
  v19 = (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&v25, (void (__thiscall *)(vostok::sound::sound_debug_stats *))survarium::jump_logic::landing_predicate, (vostok::sound::sound_debug_stats *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v19.f_.f_,
    &v26);
  if ( boost::detail::function::basic_vtable1<void,boost::system::error_code>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::http_client,boost::system::error_code>,boost::_bi::list2<boost::_bi::value<vostok::network::http_client *>,boost::arg<1>>>>(
         (boost::detail::function::basic_vtable1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> *)&`boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::jump_logic>,boost::_bi::list1<boost::_bi::value<survarium::jump_logic *>>>>'::`2'::stored_vtable,
         v19,
         &v26.functor) )
  {
    v26.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::jump_logic>,boost::_bi::list1<boost::_bi::value<survarium::jump_logic *>>>>'::`2'::stored_vtable.base.manager
                                                        + 1);
  }
  else
  {
    v26.vtable = 0;
  }
  vostok::ai::fsm::add_transition(
    this->m_logic,
    start,
    landing,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v26);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v9,
    (int *)&v26);
  survarium::weapon_user_dead_state::finalize(v10);
  v13 = boost::_bi::list3<char const * &,enum survarium::hit_affects_type_enum &,enum survarium::affect_event_type_enum &>::operator[](
          v12,
          v11);
  vostok::ai::fsm::set_initial_state(this->m_logic, (vostok::ai::fsm_state *)v13);
}
