void __thiscall survarium::jump_logic_state_prepare::deserialize(
        survarium::jump_logic_state_prepare *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader)
{
  const unsigned __int8 *m_pointer; // eax
  vostok::resources::managed_resource *m_object; // xmm0_4
  survarium::jump_logic *v6; // ecx
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *move_animation; // eax
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v8; // ecx
  survarium::weapon_user_animations_selector *v9; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v10; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_prepare,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_prepare *>,boost::arg<1> > > v11; // [esp-8h] [ebp-40h]
  int v12; // [esp+0h] [ebp-38h]
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > v13; // [esp+10h] [ebp-28h] BYREF
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> v14; // [esp+18h] [ebp-20h] BYREF

  survarium::jump_logic_base_state::deserialize(this, reader, client_reader);
  m_pointer = reader->m_pointer;
  v13.first.m_object = *(vostok::resources::managed_resource **)m_pointer;
  m_object = v13.first.m_object;
  reader->m_pointer = m_pointer + 4;
  LODWORD(this->m_time_scale) = m_object;
  this->m_prepare_interval_ended = vostok::network_core::buffer_reader::r<bool>(reader);
  move_animation = survarium::jump_logic::get_move_animation(v6, (int)this->m_jump_logic, &v13);
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>>::operator=(
    &this->m_animation,
    move_animation);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v13.second);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v13.first);
  v11.l_.a1_.t_ = this;
  v11.f_.f_ = survarium::jump_logic_state_prepare::on_interval_end;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v8,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_prepare,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_prepare *>,boost::arg<1> > > *)&v14,
    v11,
    v12);
  survarium::weapon_user_animations_selector::set_animation_callback(
    v9,
    (vostok::animation::reserved_channel_ids_enum)this->m_jump_logic->m_owner,
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)2,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)this,
    &v14);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v10,
    (int *)&v14);
}
