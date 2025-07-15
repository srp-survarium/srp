void __thiscall survarium::weapon_core_throw_grenade_base_substate::subscribe_animation_player(
        survarium::weapon_core_throw_grenade_base_substate *this)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_throw_grenade_base_substate,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_throw_grenade_base_substate *>,boost::arg<1> > > v3; // [esp-8h] [ebp-38h]
  int v4; // [esp+0h] [ebp-30h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v5; // [esp+Ch] [ebp-24h] BYREF
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> v6; // [esp+10h] [ebp-20h] BYREF

  if ( this->m_playback_type )
  {
    v5.m_object = 0;
    v3.l_.a1_.t_ = this;
    v3.f_.f_ = survarium::weapon_core_throw_grenade_base_substate::on_animation_end;
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      (boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)this,
      (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_throw_grenade_base_substate,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_throw_grenade_base_substate *>,boost::arg<1> > > *)&v6,
      v3,
      v4);
    survarium::base_player::subscribe_animation_player(
      (survarium::base_player *)&v6,
      (vostok::animation::reserved_channel_ids_enum)this->m_weapon->m_user,
      (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)1,
      &v6,
      (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)this,
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v5,
      this->m_weapon->m_user);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v2,
      (int *)&v6);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v5);
  }
}
