void __thiscall survarium::jump_logic_state_landing::deserialize(
        survarium::jump_logic_state_landing *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader)
{
  const unsigned __int8 *m_pointer; // esi
  survarium::jump_logic *m_jump_logic; // esi
  int m_jump_type; // ecx
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *animation; // eax
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v8; // ecx
  survarium::weapon_user_animations_selector *v9; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v10; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > > v11; // [esp-8h] [ebp-50h]
  int v12; // [esp+0h] [ebp-48h]
  int v13; // [esp+13h] [ebp-35h]
  char v14; // [esp+14h] [ebp-34h]
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > v15; // [esp+18h] [ebp-30h] BYREF
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > v16; // [esp+20h] [ebp-28h] BYREF
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> v17; // [esp+28h] [ebp-20h] BYREF

  survarium::jump_logic_base_state::deserialize(this, reader, client_reader);
  m_pointer = reader->m_pointer;
  v13 = *m_pointer;
  reader->m_pointer = m_pointer + 1;
  m_jump_logic = this->m_jump_logic;
  this->m_landing_type = (unsigned __int8)v13;
  m_jump_type = m_jump_logic->m_jump_type;
  if ( m_jump_type == 1 || m_jump_type >= 8 )
  {
    v14 = 1;
    animation = survarium::jump_logic::get_animation(m_jump_logic, 2u, &v16);
  }
  else
  {
    v14 = 2;
    animation = survarium::jump_logic::get_animation(m_jump_logic, (unsigned __int8)v13, &v15);
  }
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>>::operator=(
    &this->m_animation,
    animation);
  if ( (v14 & 2) != 0 )
  {
    v14 &= ~2u;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v15.second);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v15.first);
  }
  if ( (v14 & 1) != 0 )
  {
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v16.second);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v16.first);
  }
  if ( !this->m_is_jump_finished )
  {
    v11.l_.a1_.t_ = this;
    v11.f_.f_ = survarium::jump_logic_state_landing::on_interval_end;
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v8,
      (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > > *)&v17,
      v11,
      v12);
    survarium::weapon_user_animations_selector::set_animation_callback(
      v9,
      (vostok::animation::reserved_channel_ids_enum)this->m_jump_logic->m_owner,
      (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)2,
      (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)this,
      &v17);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v10,
      (int *)&v17);
  }
}
