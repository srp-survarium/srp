void __thiscall survarium::jump_logic_state_start::deserialize(
        survarium::jump_logic_state_start *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader)
{
  bool v4; // al
  survarium::jump_logic *m_jump_logic; // esi
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *animation; // eax
  survarium::jump_logic *v7; // ecx
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *move_animation; // eax
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v9; // ecx
  survarium::weapon_user_animations_selector *v10; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v11; // ecx
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v12; // ecx
  survarium::weapon_user_animations_selector *v13; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v14; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_start,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_start *>,boost::arg<1> > > v15; // [esp-8h] [ebp-38h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_start,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_start *>,boost::arg<1> > > v16; // [esp-8h] [ebp-38h]
  int v17; // [esp+0h] [ebp-30h]
  int v18; // [esp+0h] [ebp-30h]
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > v19; // [esp+8h] [ebp-28h] BYREF
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> v20; // [esp+10h] [ebp-20h] BYREF

  survarium::jump_logic_base_state::deserialize(this, reader, client_reader);
  this->m_preface_interval_ended = vostok::network_core::buffer_reader::r<bool>(reader);
  v4 = vostok::network_core::buffer_reader::r<bool>(reader);
  m_jump_logic = this->m_jump_logic;
  this->m_jump_interval_ended = v4;
  animation = survarium::jump_logic::get_animation(m_jump_logic, 0, &v19);
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>>::operator=(
    &this->m_animation,
    animation);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v19.second);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v19.first);
  move_animation = survarium::jump_logic::get_move_animation(v7, (int)this->m_jump_logic, &v19);
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>>::operator=(
    &this->m_preface_animation,
    move_animation);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v19.second);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v19.first);
  v15.l_.a1_.t_ = this;
  v15.f_.f_ = survarium::jump_logic_state_start::on_interval_end;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v9,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_start,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_start *>,boost::arg<1> > > *)&v20,
    v15,
    v17);
  survarium::weapon_user_animations_selector::set_animation_callback(
    v10,
    (vostok::animation::reserved_channel_ids_enum)this->m_jump_logic->m_owner,
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)2,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)this,
    &v20);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v11,
    (int *)&v20);
  v16.l_.a1_.t_ = this;
  v16.f_.f_ = (vostok::animation::callback_return_type_enum (__thiscall *)(survarium::jump_logic_state_start *, vostok::animation::animation_callback_params *))survarium::jump_logic_state_start::on_jump_event;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v12,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_start,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_start *>,boost::arg<1> > > *)&v20,
    v16,
    v18);
  survarium::weapon_user_animations_selector::set_animation_callback(
    v13,
    (const char *)this->m_jump_logic->m_owner,
    this,
    &v20);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v14,
    (int *)&v20);
}
