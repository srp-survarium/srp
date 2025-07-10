void __thiscall survarium::weapon_user_animations_selector::activate(
        survarium::weapon_user_animations_selector *this,
        survarium::base_player *user,
        const boost::function<void __cdecl(void)> *sprint_start_callback,
        const boost::function<void __cdecl(void)> *sprint_end_callback)
{
  int v4; // eax
  boost::_bi::list4<enum vostok::connection_error_types_enum &,enum vostok::handshaking_error_types_enum &,enum vostok::socket_error_types_enum &,enum vostok::lobby_server_message_types_enum &> *v5; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v6; // ecx
  int v7; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v8; // ecx
  const vostok::variant<32> **v9; // eax
  survarium::base_player *m_user; // [esp-4h] [ebp-58h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_user_animations_selector,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_user_animations_selector *>,boost::arg<1> > > f; // [esp+10h] [ebp-44h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+24h] [ebp-30h] BYREF
  boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> v14; // [esp+2Ch] [ebp-28h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v15; // [esp+4Ch] [ebp-8h] BYREF
  vostok::ai::fsm_state *i; // [esp+50h] [ebp-4h]

  this->m_user = user;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)user);
  for ( i = (vostok::ai::fsm_state *)boost::_bi::list3<char const * &,enum survarium::hit_affects_type_enum &,enum survarium::affect_event_type_enum &>::operator[](
                                       v5,
                                       v4); i; i = i->next )
    ((void (__thiscall *)(vostok::ai::fsm_state *, survarium::base_player *))i->__vftable[1].~vostok::ai::fsm_state)(
      i,
      user);
  vostok::ai::fsm::set_initial_state(&this->m_logic, this->m_player_logic_initial_state);
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
    &v15,
    0);
  f = (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_user_animations_selector,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_user_animations_selector *>,boost::arg<1> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result, (void (__thiscall *)(vostok::sound::sound_debug_stats *))survarium::weapon_user_animations_selector::on_interval_ended, (vostok::sound::sound_debug_stats *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)f.f_.f_,
    &v14);
  boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>::assign_to<boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_user_animations_selector,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_user_animations_selector *>,boost::arg<1>>>>(
    &v14,
    f);
  m_user = this->m_user;
  ((void (__thiscall *)(survarium::base_player *, int, boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> *, survarium::weapon_user_animations_selector *))m_user->subscribe_animation_player)(
    m_user,
    2,
    &v14,
    this);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v6,
    (int *)&v14);
  vostok::animation::mixing::animation_interval::~animation_interval(&v15);
  v7 = ((int (__thiscall *)(survarium::base_player *, int, survarium::affect_subscriber *))this->m_user->damage_model)(
         this->m_user,
         4,
         &this->m_leg_damaged_subscriber);
  v9 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v8, v7);
  survarium::damage_model::subscribe_on_affect(
    (survarium::damage_model *)v9,
    (const survarium::hit_affects_type_enum)&v15,
    (survarium::affect_subscriber *const)m_user);
  survarium::weapon_user_animations_selector::set_sprint_callbacks(this, sprint_start_callback, sprint_end_callback);
}
