void __thiscall survarium::short_jump_start_state::initialize(survarium::short_jump_start_state *this)
{
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v2; // ecx
  survarium::weapon_user_animations_selector *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v5; // ecx
  survarium::weapon_user_animations_selector *v6; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::short_jump_start_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::short_jump_start_state *>,boost::arg<1> > > v8; // [esp-8h] [ebp-38h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::short_jump_start_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::short_jump_start_state *>,boost::arg<1> > > v9; // [esp-8h] [ebp-38h]
  int v10; // [esp+0h] [ebp-30h]
  int v11; // [esp+0h] [ebp-30h]
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > v12; // [esp+8h] [ebp-28h] BYREF
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> v13; // [esp+10h] [ebp-20h] BYREF

  v12.first.m_object = 0;
  v12.second.m_object = 0;
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>>::operator=(
    &this->m_animation,
    &v12);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v12.second);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v12.first);
  v8.l_.a1_.t_ = this;
  v8.f_.f_ = survarium::short_jump_start_state::on_animation_end;
  this->m_jump_animation_ended = 0;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v2,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::short_jump_start_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::short_jump_start_state *>,boost::arg<1> > > *)&v13,
    v8,
    v10);
  survarium::weapon_user_animations_selector::set_animation_callback(
    v3,
    (vostok::animation::reserved_channel_ids_enum)this->m_jump_logic->m_owner,
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)1,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)this,
    &v13);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v4,
    (int *)&v13);
  v9.l_.a1_.t_ = this;
  v9.f_.f_ = (vostok::animation::callback_return_type_enum (__thiscall *)(survarium::short_jump_start_state *, vostok::animation::animation_callback_params *))survarium::jump_logic_state_start::on_jump_event;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v5,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::short_jump_start_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::short_jump_start_state *>,boost::arg<1> > > *)&v13,
    v9,
    v11);
  survarium::weapon_user_animations_selector::set_animation_callback(
    v6,
    (const char *)this->m_jump_logic->m_owner,
    this,
    &v13);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v7,
    (int *)&v13);
}
