void __thiscall survarium::player_logic_dead_state::deserialize(
        survarium::player_logic_dead_state *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader)
{
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *death_animation; // eax
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v5; // ecx
  survarium::weapon_user_animations_selector *v6; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::player_logic_dead_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::player_logic_dead_state *>,boost::arg<1> > > v8; // [esp-8h] [ebp-38h]
  int v9; // [esp+0h] [ebp-30h]
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > v10; // [esp+8h] [ebp-28h] BYREF
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> v11; // [esp+10h] [ebp-20h] BYREF

  this->m_is_ready_to_be_deactivated = vostok::network_core::buffer_reader::r<bool>(reader);
  death_animation = survarium::weapon_user_animations_container::get_death_animation(
                      (survarium::weapon_user_animations_container *)&v10,
                      (stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *)this->m_owner->m_animations.m_object,
                      &v10);
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>>::operator=(
    &this->m_animation,
    death_animation);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v10.second);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v10.first);
  v8.l_.a1_.t_ = this;
  v8.f_.f_ = survarium::player_logic_dead_state::on_animation_end;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v5,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::player_logic_dead_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::player_logic_dead_state *>,boost::arg<1> > > *)&v11,
    v8,
    v9);
  survarium::weapon_user_animations_selector::set_animation_callback(
    v6,
    (vostok::animation::reserved_channel_ids_enum)this->m_owner,
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)1,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)this,
    &v11);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v7,
    (int *)&v11);
}
