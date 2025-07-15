void __thiscall survarium::short_jump_start_state::deserialize(
        survarium::short_jump_start_state *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader)
{
  bool v4; // al
  survarium::jump_logic *m_jump_logic; // esi
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *animation; // eax
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v7; // ecx
  survarium::weapon_user_animations_selector *v8; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v10; // ecx
  survarium::weapon_user_animations_selector *v11; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v12; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::short_jump_start_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::short_jump_start_state *>,boost::arg<1> > > v13; // [esp-8h] [ebp-38h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::short_jump_start_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::short_jump_start_state *>,boost::arg<1> > > v14; // [esp-8h] [ebp-38h]
  int v15; // [esp+0h] [ebp-30h]
  int v16; // [esp+0h] [ebp-30h]
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > v17; // [esp+8h] [ebp-28h] BYREF
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> v18; // [esp+10h] [ebp-20h] BYREF

  survarium::jump_logic_base_state::deserialize(this, reader, client_reader);
  v4 = vostok::network_core::buffer_reader::r<bool>(reader);
  m_jump_logic = this->m_jump_logic;
  this->m_jump_animation_ended = v4;
  animation = survarium::jump_logic::get_animation(m_jump_logic, 0, &v17);
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>>::operator=(
    &this->m_animation,
    animation);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v17.second);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v17.first);
  v13.l_.a1_.t_ = this;
  v13.f_.f_ = survarium::short_jump_start_state::on_animation_end;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v7,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::short_jump_start_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::short_jump_start_state *>,boost::arg<1> > > *)&v18,
    v13,
    v15);
  survarium::weapon_user_animations_selector::set_animation_callback(
    v8,
    (vostok::animation::reserved_channel_ids_enum)this->m_jump_logic->m_owner,
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)1,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)this,
    &v18);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v9,
    (int *)&v18);
  v14.l_.a1_.t_ = this;
  v14.f_.f_ = (vostok::animation::callback_return_type_enum (__thiscall *)(survarium::short_jump_start_state *, vostok::animation::animation_callback_params *))survarium::jump_logic_state_start::on_jump_event;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v10,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::short_jump_start_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::short_jump_start_state *>,boost::arg<1> > > *)&v18,
    v14,
    v16);
  survarium::weapon_user_animations_selector::set_animation_callback(
    v11,
    (const char *)this->m_jump_logic->m_owner,
    this,
    &v18);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v12,
    (int *)&v18);
}
